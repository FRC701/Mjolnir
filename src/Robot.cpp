#include "Robot.h"

// This is the one file that needs WPILib.h in order to properly expand START_ROBOT_CLASS
#include "WPILib.h"

#include "OI.h"
#include <iostream>
#include "Subsystems/Arm.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Ramp.h"
#include "Commands/TankDrive.h"
#include "SmartDashboard/SmartDashboard.h"
#include "GameData.h"
#include "Subsystems/Puncher.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Lights.h"
#include "Commands/AutoScaleSelector.h"
#include "Commands/AutoSwitchSelector.h"
#include "Commands/AutoLeftSwitch.h"
#include "Commands/AutoRightSwitch.h"
#include "Commands/AutoRun.h"
#include "Commands/AutoFullLeftSwitch.h"
#include "Commands/AutoFullRightSwitch.h"
#include "Commands/AutoFullLeftScale.h"
#include "Commands/AutoFullPostLeftSwitch.h"
#include "Commands/AutoFullPostRightSwitch.h"
#include "Commands/AutoFullDoubleLeftSwitch.h"
#include "Commands/AutoFullDoubleRightSwitch.h"
#include "Commands/AutoDontShootScale.h"
#include "Commands/AutoDontShootRightScale.h"
#include "Commands/AutoFullRightScale.h"
#include "Commands/AutoFullTripleLeftSwitch.h"
#include "Commands/AutoFullTripleRightSwitch.h"

using robovikes::GameData;

std::unique_ptr<OI> Robot::oi;

static void LimitSwitches(){
  SmartDashboard::PutBoolean("Arm Forward Switch", Arm::getInstance()->IsForwardLimitSwitchClosed());
  SmartDashboard::PutBoolean("Arm Reverse Switch", Arm::getInstance()->IsReverseLimitSwitchClosed());
  SmartDashboard::PutBoolean("Puncher limit Switch", Puncher::getInstance()->GetPuncherLimit());
  SmartDashboard::PutBoolean("Intake Banner Sensor", Puncher::getInstance()->IsCubeIn());

}

Robot::Robot():
    autonomousCommand(nullptr),
    chooser(new frc::SendableChooser<frc::Command*>()) {

}

std::string SideToString(robovikes::GameData::Side side){
  std::string sideString = "Left";
  switch(side) {
    case GameData::Left:
      sideString = "Left";
      break;
    case GameData::Right:
      sideString = "Right";
      break;
    default:
      sideString = "Unknown";
      break;
      }
  return sideString;
}

void Robot::RobotInit() {
	RobotMap::init();
		Arm::getInstance();
    Chassis::getInstance();
		Intake::getInstance();
		Ramp::getInstance();
		Climber::getInstance();
		Lights::getInstance();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());
	//CameraServer::GetInstance()->StartAutomaticCapture().SetFPS(20);

	chooser->AddObject("Twiddle Your Thumbs", new AutonomousCommand());
	chooser->AddDefault("Switch", new AutoSwitchSelector(new AutoFullLeftSwitch(), new AutoFullRightSwitch()));//this is supposed to be default
  chooser->AddObject("Post Switch", new AutoSwitchSelector(new AutoFullPostLeftSwitch(), new AutoFullPostRightSwitch()));
  chooser->AddObject("Double Switch", new AutoSwitchSelector(new AutoFullDoubleLeftSwitch(), new AutoFullDoubleRightSwitch()));
	chooser->AddObject("Left Scale", new AutoScaleSelector(
	     new AutoDontShootScale(), new AutoDontShootScale()));
  chooser->AddObject("Right Scale", new AutoScaleSelector(
       new AutoDontShootRightScale(), new AutoDontShootRightScale()));
	chooser->AddObject("Auto Run", new AutoRun());
	chooser->AddObject("Triple Switch", new AutoSwitchSelector(new AutoFullTripleLeftSwitch(), new AutoFullTripleRightSwitch()));
	SmartDashboard::PutData("Autonomous Chooser", chooser);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
  Lights::getInstance()->SetLights(Relay::kOff);
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
  LimitSwitches();
}

void Robot::AutonomousInit() {
//	if (autonomousCommand.get() != nullptr)
//		autonomousCommand->Start();
  Lights::getInstance()->SetLights(Relay::kOn);

  autonomousCommand.reset(chooser->GetSelected());
  if (autonomousCommand.get() != nullptr)
    autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutString("Our Switch", SideToString(robovikes::GameData::GetOurSwitchSide()));
	SmartDashboard::PutString("Scale", SideToString(robovikes::GameData::GetScaleSide()));
	SmartDashboard::PutString("Their Switch", SideToString(robovikes::GameData::GetTheirSwitchSide()));

}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr) autonomousCommand->Cancel();

  Lights::getInstance()->SetLights(Relay::kOn);
}


void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

 /* SmartDashboard::PutNumber("Left Velocity (u/100ms)", Chassis::getInstance()->getLeftVelocity());
  SmartDashboard::PutNumber("Right Velocity (u/100ms)", Chassis::getInstance()->getRightVelocity());
  SmartDashboard::PutNumber("Left Position", Chassis::getInstance()->GetLeftPosition());
  SmartDashboard::PutNumber("Right Position", Chassis::getInstance()->GetRightPosition());

  SmartDashboard::PutNumber("Arm Velocity (u/100ms)", Arm::getInstance()->GetVelocity());
  SmartDashboard::PutNumber("Arm Position", Arm::getInstance()->GetPosition());
  //SmartDashboard::PutNumber("Pot Value", Arm::getInstance()->GetArmPotValue());
  //SmartDashboard::PutNumber("Arm Voltage", Arm::getInstance()->GetArmPotVoltage());
  //SmartDashboard::PutNumber("Encoder Position", Arm::getInstance()->CalculateEncoderPos());
  //SmartDashboard::PutNumber("Motion Magic Error", Arm::getInstance()->GetPositionError());

  SmartDashboard::PutString("Our Switch", SideToString(robovikes::GameData::GetOurSwitchSide()));
  SmartDashboard::PutString("Scale", SideToString(robovikes::GameData::GetScaleSide()));
  SmartDashboard::PutString("Their Switch", SideToString(robovikes::GameData::GetTheirSwitchSide()));
 */
  SmartDashboard::PutNumber("Puncher velocity", Puncher::getInstance()->GetVelocity());
  SmartDashboard::PutNumber("Puncher Position", Puncher::getInstance()->GetPosition());
  SmartDashboard::PutNumber("Puncher Error", Puncher::getInstance()->GetPositionError());
  SmartDashboard::PutNumber("Puncher Current", Puncher::getInstance()->GetCurrent());

  SmartDashboard::PutNumber("Scale Factor", Arm::getInstance()->CalculateEncoderPos());

  LimitSwitches();
}


void Robot::TestPeriodic() {
	// lw->Run();
}

START_ROBOT_CLASS(Robot);

