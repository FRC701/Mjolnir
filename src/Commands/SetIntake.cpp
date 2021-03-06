#include "SetIntake.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Puncher.h"

SetIntake::SetIntake(double speed): mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Intake::getInstance().get());
}

// Called just before this Command runs the first time
void SetIntake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetIntake::Execute() {
	Intake::getInstance()->SetIntake(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetIntake::IsFinished() {
  if(mSpeed < 0){
    return ! Puncher::getInstance()->IsCubeIn();
  }
  else{
    return Puncher::getInstance()->IsCubeIn();
  }


}

// Called once after isFinished returns true
void SetIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetIntake::Interrupted() {

}
