#include <Commands/ChassisMotionProfileCommand.h>
#include "Subsystems/Chassis.h"
#include <iostream>

#include "ctre/Phoenix.h"

/**
 * Notes about Talon Motion Profile
 *
 * The trajectory point buffer in the Talon Driver (RoboRio) is 2048 points.
 * The typical trajectory point is 10ms. 2048 represents 20.48 seconds of motion profile.
 *
 * Important -- The code in this implementation does not support more than 2048 trajectory points.
 *
 * The trajectory point buffer in the Talon (bottom buffer) holds 128 points.
 *
 * The Talon Motion Profile Mode has three drive modes controlled by Set()
 * * Neutral (SetValueMotionProfileDisable)
 * * Drive (SetValueMotionProfileEnable)
 * * Hold (SetValueMotionProfileHold)
 *
 *
 */

using frc::Notifier;


// Velocity only is achieved by removed PID. When there are no PID factors, but still and F (feedforward) factor
// then only velocity is used.

// todo: Better logging. See CTRE Instrumentation example.

namespace {

  const double kSecondsToMillis = 1000.0;
  const double kMillisToSeconds = ( 1.0 / kSecondsToMillis );

  typedef ctre::phoenix::motion::TrajectoryPoint ctre_TrajectoryPoint;

  void LoadPoints(
    const robovikes::TrajectoryPoint* chassisLeft,
    const robovikes::TrajectoryPoint* chassisRight,
    unsigned int trajectoryPointCount,
    unsigned int pointDurationMillis,
    bool velocityOnly)
  {
    std::cout << "Load Points:" << trajectoryPointCount << std::endl;
    unsigned int lastPoint = trajectoryPointCount - 1;

    std::cout << chassisLeft << "," << chassisRight << std::endl;
    std::cout << chassisLeft->velocity << "," << chassisRight->velocity << std::endl;

    for (unsigned int point = 0; point < trajectoryPointCount; ++point) {
      std::cout << "LoadPoints:" << point << "," << chassisLeft[point].velocity << "," << chassisRight[point].velocity << std::endl;

      ctre_TrajectoryPoint rightTrajectoryPoint;
      rightTrajectoryPoint.position = chassisRight[point].position;
      rightTrajectoryPoint.velocity = chassisRight[point].velocity;
      rightTrajectoryPoint.profileSlotSelect0 = 0;
      rightTrajectoryPoint.isLastPoint = (point == lastPoint);
      rightTrajectoryPoint.zeroPos = (point == 0);
      rightTrajectoryPoint.timeDur = static_cast<TrajectoryDuration>(pointDurationMillis);

      ctre_TrajectoryPoint leftTrajectoryPoint = rightTrajectoryPoint;
      leftTrajectoryPoint.position = chassisLeft[point].position;
      leftTrajectoryPoint.velocity = chassisLeft[point].velocity;

      Chassis::getInstance()->PushMotionProfileTrajectory(leftTrajectoryPoint, rightTrajectoryPoint);
      std::cout << "LoadPoints:" << point << "," << chassisLeft[point].velocity << "," << chassisRight[point].velocity<< std::endl;
    }
    std::cout << "Load Points Complete"<< std::endl;
  }

  /**
   * The MotionProfileState subclasses are implementations of the State Design Pattern
   * using the Flyweight implementation strategy.
   *
   * A flyweight class is one where the object instance holds no state so that there
   * is only ever one instance of the class.
   *
   * In this implementation each MotionProfileState class determines the next state in getNextState.
   */

  class MotionProfileStart : public ChassisMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const ChassisMotionProfileCommand* motionProfile) {
      Chassis::getInstance()->ClearMotionProfileTrajectories();
      Chassis::getInstance()->SetMotionProfileSetValue(SetValueMotionProfile::Disable);
      std::cout << "MotionProfileStart" << std::endl;
    }

    bool isFinished() const {
      return false;
    }

    ChassisMotionProfileCommand::MotionProfileState* getNextState();

    virtual ~MotionProfileStart() { }
  };

  class MotionProfileLoadTalon : public ChassisMotionProfileCommand::MotionProfileState
  {
  public:
    static const int kMinPointsInTalon = 5;

    void run(const ChassisMotionProfileCommand* motionProfile) {
      Chassis::getInstance()->SetMotionProfileSetValue(SetValueMotionProfile::Disable);
    }

    bool isFinished() const {
      return false;
    }

    ChassisMotionProfileCommand::MotionProfileState* getNextState();

    virtual ~MotionProfileLoadTalon() { }
  };

  class MotionProfileRun : public ChassisMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const ChassisMotionProfileCommand* motionProfile) {
      std::cout << "MotionProfileRun" << std::endl;
      Chassis::getInstance()->SetMotionProfileSetValue(SetValueMotionProfile::Enable);
    }

    bool isFinished() const {
      return false;
    }

    ChassisMotionProfileCommand::MotionProfileState* getNextState();

    virtual ~MotionProfileRun() { }
  };

  class MotionProfileFinished : public ChassisMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const ChassisMotionProfileCommand* motionProfile) {
      std::cout << "MotionProfileFinished" << std::endl;
      Chassis::getInstance()->SetMotionProfileSetValue(SetValueMotionProfile::Hold);
    }

    bool isFinished() const {
      return true;
    }

    ChassisMotionProfileCommand::MotionProfileState* getNextState();

    virtual ~MotionProfileFinished() { }
  };

  MotionProfileStart motionProfileStart;
  ChassisMotionProfileCommand::MotionProfileLoad motionProfileLoad;
  MotionProfileLoadTalon motionProfileLoadTalon;
  MotionProfileRun motionProfileRun;
  MotionProfileFinished motionProfileFinished;

  /**
   * The fly weight instances must be defined in order to implement the getNextState methods.
   */

  ChassisMotionProfileCommand::MotionProfileState*
  MotionProfileStart::getNextState() {
    return &motionProfileLoad;
  }

  ChassisMotionProfileCommand::MotionProfileState*
  MotionProfileLoadTalon::getNextState() {
    /**
     * The PeriodicTask will automatically load the Talons as the data points
     * are added. Presumably, by the time we check here, there are already
     * points in the Talon bottom buffer.
     */
    std::cout << "MotionProfileLoadTalon::getNextState" << std::endl;
    MotionProfileStatus leftStatus, rightStatus;
    Chassis::getInstance()->GetMotionProfileStatus(&leftStatus, &rightStatus);
    std::cout << "MotionProfileStatus" << leftStatus.btmBufferCnt << " " << rightStatus.btmBufferCnt << std::endl;
    if (leftStatus.btmBufferCnt > kMinPointsInTalon
        && rightStatus.btmBufferCnt > kMinPointsInTalon) {
      return &motionProfileRun;
    }
    else {
      return this;
    }
  }

  ChassisMotionProfileCommand::MotionProfileState*
  MotionProfileRun::getNextState() {
    MotionProfileStatus leftStatus, rightStatus;
    Chassis::getInstance()->GetMotionProfileStatus(&leftStatus, &rightStatus);
    // activePointValid must precede isLastPoint.
    std::cout << "MotionProfileRun" << leftStatus.activePointValid << " " << rightStatus.activePointValid << std::endl;
    if (rightStatus.activePointValid && rightStatus.isLast
        && leftStatus.activePointValid && leftStatus.isLast) {
      return &motionProfileFinished;
    }
    else {
      return this;
    }
  }

  ChassisMotionProfileCommand::MotionProfileState*
  MotionProfileFinished::getNextState() {
    return this;
  }

} // end namespace

void ChassisMotionProfileCommand::MotionProfileLoad::run(const ChassisMotionProfileCommand* motionProfile) {
  std::cout << "MotionProfileLoad" << std::endl;
  Chassis::getInstance()->ConfigMotionProfileTrajectoryPeriod(motionProfile->pointDurationMillis);
  LoadPoints(motionProfile->chassisLeft, motionProfile->chassisRight,
             motionProfile->trajectoryPointCount, motionProfile->pointDurationMillis, motionProfile->velocityOnly);
}

bool ChassisMotionProfileCommand::MotionProfileLoad::isFinished() const {
  return false;
}

ChassisMotionProfileCommand::MotionProfileState*
ChassisMotionProfileCommand::MotionProfileLoad::getNextState() {
  return &motionProfileLoadTalon;
}

ChassisMotionProfileCommand::MotionProfileLoad::~MotionProfileLoad() {
}


ChassisMotionProfileCommand::ChassisMotionProfileCommand(
  const TrajectoryPoint* _chassisLeft,
  const TrajectoryPoint* _chassisRight,
  unsigned int _trajectoryPointCount,
  unsigned int _pointDurationMillis,
  bool _velocityOnly)
: chassisLeft(_chassisLeft),
  chassisRight(_chassisRight),
  trajectoryPointCount(_trajectoryPointCount),
  pointDurationMillis(_pointDurationMillis),
  velocityOnly(_velocityOnly),
  notifier(&ChassisMotionProfileCommand::PeriodicTask, this),
  state(&motionProfileStart)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Chassis::getInstance().get());
  std::cout<<"ChassisMotionProfileCommand Constructor"<<std::endl;
}

// Called just before this Command runs the first time
void ChassisMotionProfileCommand::Initialize() {
  Chassis::getInstance()->SetModeMotionProfile();
  notifier.StartPeriodic((pointDurationMillis * kMillisToSeconds) / 2.0);
  std::cout << "Start Periodic" << std::endl;
  state = &motionProfileStart;
}

// Called repeatedly when this Command is scheduled to run
void ChassisMotionProfileCommand::Execute() {
  state->run(this);
  state = state->getNextState();
}

// Make this return true when this Command no longer needs to run execute()
bool ChassisMotionProfileCommand::IsFinished() {
  return state->isFinished();
}

// Called once after isFinished returns true
void ChassisMotionProfileCommand::End() {
  std::cout << "ChassisMotionProfileCommand::End" << std::endl;
  notifier.Stop();
  Chassis::getInstance()->SetModePercentOutput();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisMotionProfileCommand::Interrupted() {
  notifier.Stop();
  Chassis::getInstance()->SetModePercentOutput();
}

void ChassisMotionProfileCommand::PeriodicTask() {
  Chassis::getInstance()->ProcessMotionProfileBuffer();
}
