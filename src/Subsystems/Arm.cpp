#include "Arm.h"
#include "Commands/ArmMove.h"
#include "Commands/BrakeOn.h"
#include "RobotMap.h"

static const int kSlotIndex = 0;

const char Arm::kSubsystemName[] = "Arm";
const std::string kKey = "ArmScale";
const std::string kKeyPot = "ArmPotBottom";

std::shared_ptr<Arm> Arm::self;

std::shared_ptr<Arm> Arm::getInstance() {
        if (! self) {
          self = std::shared_ptr<Arm>(new Arm);
        }
        return self;
}
static double calcFeedforward() {
  static const double kMaxUnitsPer100ms = 3675.0;
  // static const double kUnitsPerRev = 4096.0;
  // double rpm = (kMaxUnitsPer100ms * 600.0) / kUnitsPerRev;
  double feedforward = 1023.0 / kMaxUnitsPer100ms;
  return feedforward;
}
static double calcP(){
  static const double kEigthUnitsPerRev = 4096.0/ 1.0;
  double pGain = 1* 1023.0/kEigthUnitsPerRev;
  return pGain;
}
Arm::Arm() : Subsystem(kSubsystemName),
  leftArmMotor(RobotMap::kIDLeftArm),
  rightArmMotor(RobotMap::kIDRightArm),
  brake(RobotMap::kIDBrakeForward, RobotMap::kIDBrakeReverse),
  armPot(RobotMap::kIDArmPot),
  calibrateEncoderDown(0),
  calibratePotDown(0)
{
  EngageBrake();
  SetUpTalons();
  SetUpMotionMagic();
}

void Arm::InitDefaultCommand() {
  SetDefaultCommand(new BrakeOn());
}

void Arm::SetArmMove(double speed) {
  leftArmMotor.Set(ControlMode::PercentOutput, speed);
}
void Arm::SetArmPos(int position){
  leftArmMotor.Set(ControlMode::MotionMagic, position);
}
void Arm::SetUpTalons() {
  leftArmMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,
                                         kPID_PrimaryClosedLoop,
                                         kTimeout_10Millis);
  leftArmMotor.ConfigForwardSoftLimitEnable(false, kTimeout_10Millis);
  leftArmMotor.ConfigReverseSoftLimitEnable(false, kTimeout_10Millis);
  leftArmMotor.ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, kTimeout_10Millis);
  leftArmMotor.ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, kTimeout_10Millis);
  leftArmMotor.SetSensorPhase(true);
  leftArmMotor.SetInverted(true);
  leftArmMotor.ConfigPeakOutputForward(0.1, kTimeout_10Millis);
  leftArmMotor.ConfigPeakOutputReverse(-0.02, kTimeout_10Millis);

  rightArmMotor.SetInverted(true);
  rightArmMotor.Follow(leftArmMotor);

 leftArmMotor.SetSelectedSensorPosition(CalculateEncoderPos(), kPID_PrimaryClosedLoop, kTimeout_10Millis);

}

int Arm::GetVelocity()
{
 return leftArmMotor.GetSelectedSensorVelocity(kPID_PrimaryClosedLoop);
}

int Arm::GetPosition()
{
  return leftArmMotor.GetSelectedSensorPosition(kPID_PrimaryClosedLoop);
}

void Arm::SetUpMotionMagic() {
  leftArmMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeout_10Millis);
  leftArmMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);

  leftArmMotor.ConfigNominalOutputForward(0, kTimeout_10Millis);
  leftArmMotor.ConfigNominalOutputReverse(0, kTimeout_10Millis);
  leftArmMotor.ConfigPeakOutputForward(1, kTimeout_10Millis);
  leftArmMotor.ConfigPeakOutputReverse(-1, kTimeout_10Millis);

  static const double kF = calcFeedforward();
  static const double kP = calcP();
  static const double kI = 0;
  static const double kD = 0;
  static const double kMaxVelocity = 3675;
  static const int kCruiseVelocity = kMaxVelocity; //Sensor Units per 100ms
  static const int kMotionAcceleration = kCruiseVelocity * 2; //Sensor Units per 100ms/sec

  leftArmMotor.SelectProfileSlot(kSlotIndex, kPID_PrimaryClosedLoop);
  leftArmMotor.Config_kF(kSlotIndex, kF, kTimeout_10Millis);
  leftArmMotor.Config_kP(kSlotIndex, kP, kTimeout_10Millis);
  leftArmMotor.Config_kI(kSlotIndex, kI, kTimeout_10Millis);
  leftArmMotor.Config_kD(kSlotIndex, kD, kTimeout_10Millis);
  leftArmMotor.ConfigMotionCruiseVelocity(kCruiseVelocity, kTimeout_10Millis);
  leftArmMotor.ConfigMotionAcceleration(kMotionAcceleration, kTimeout_10Millis);
}

bool Arm::IsForwardLimitSwitchClosed()
{
  return leftArmMotor.GetSensorCollection().IsFwdLimitSwitchClosed();
}

bool Arm::IsReverseLimitSwitchClosed()
{
  return leftArmMotor.GetSensorCollection().IsRevLimitSwitchClosed();
}

void Arm::EngageBrake(){
  brake.Set(frc::DoubleSolenoid::kForward);
}

void Arm::DisengageBrake(){
  brake.Set(frc::DoubleSolenoid::kReverse);
}

int Arm::GetPositionError(){
  return leftArmMotor.GetClosedLoopError(kSlotIndex);
}

int Arm::GetArmPotValue(){
  return armPot.GetValue();
}

int Arm::GetArmPotVoltage(){
  return armPot.GetVoltage();
}

void Arm::ResetArmPos(){
  leftArmMotor.SetSelectedSensorPosition(0, kPID_PrimaryClosedLoop, kTimeout_10Millis);
}

void Arm::SetArmPositionDown(int potentiometer, int encoder)
{
  calibrateEncoderDown = encoder;
  calibratePotDown = potentiometer;
}

void Arm::SetArmPositionUp(int potentiometer, int encoder)
{
  double scaleFactor = (calibrateEncoderDown - encoder) / (calibratePotDown - potentiometer);
  Preferences::GetInstance()->PutDouble(kKey, scaleFactor);
  Preferences::GetInstance()->PutDouble(kKeyPot, calibratePotDown);
}

int Arm::CalculateEncoderPos()
{
  return Preferences::GetInstance()->GetDouble(kKey,0) * (Arm::GetArmPotValue() - Preferences::GetInstance()->GetDouble(kKeyPot,0));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
