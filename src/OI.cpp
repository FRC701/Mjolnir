// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"
#include "Commands/SlingShot.h"
#include "Commands/SetIntake.h"
#include "Commands/SetSlingEngagement.h"
#include "Commands/SetSlingDisengagement.h"
#include "Commands/SetArmPosition.h"
#include "Commands/ResetArmPosition.h"
#include "Commands/BrakeOff.h"
#include "Commands/BrakeOn.h"
#include "Commands/SetRamp.h"
#include "Commands/IntakeDisengage.h"
#include "Commands/IntakeEngage.h"
#include "Commands/Calibrate.h"
#include "Commands/SetClimber.h"
#include "Commands/SetPuncherPos.h"
#include "Commands/ResetPuncherPosition.h"
#include "Commands/PrepShoot.h"
#include "Commands/PuncherVoltage.h"
#include "Commands/DrawSling.h"
#include "Commands/Intaking.h"
#include "Commands/Vault.h"
#include "Commands/Scale.h"
#include "Commands/Switch.h"
#include "Commands/ScaleBackwards.h"
#include "Commands/SlingShot.h"
#include "Commands/AutoFullLeftSwitch.h"
#include "Commands/AutoFullRightSwitch.h"
#include "Commands/ShootAll.h"
#include "Commands/Outtaking.h"

#include "Commands/AutoRun.h"
#include "Commands/AutoLeftScale.h"
#include "Commands/AutoLeftSwitch.h"
#include "Commands/AutoRightSwitch.h"
#include "Commands/AutoSwitchSelector.h"
#include "Commands/AutoSwitchSide.h"
#include "SmartDashboard/SmartDashboard.h"
using frc::Joystick;
using frc::SmartDashboard;

std::shared_ptr<OI> OI::self;

std::shared_ptr<OI> OI::getInstance() {
	if (! self) {
		self = std::make_shared<OI>();
	}
	return self;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI()
: driver(new Joystick(0))
, dA(driver.get(), kButtonA_ID)
, dB(driver.get(), kButtonB_ID)
, dX(driver.get(), kButtonX_ID)
, dY(driver.get(), kButtonY_ID)
, dLB(driver.get(), kButtonLB_ID)
, dRB(driver.get(), kButtonRB_ID)

, coDriver(new Joystick(1))
, coA(coDriver.get(), kButtonA_ID)
, coB(coDriver.get(), kButtonB_ID)
, coX(coDriver.get(), kButtonX_ID)
, coY(coDriver.get(), kButtonY_ID)
, coLB(coDriver.get(), kButtonLB_ID)
, coRB(coDriver.get(), kButtonRB_ID)
, coStart(coDriver.get(), kButtonStart_ID)
, coSelect(coDriver.get(), kButtonSelect_ID)

{
  dX.WhenPressed(new SetClimber(1.0));
  dY.WhenPressed(new SetClimber(-1.0));
  dRB.WhenPressed(new SetIntake(0.0));
  //dB is being used to stop Climber don't use!


  coA.WhenPressed(new Switch);
  coB.WhenPressed(new Vault);
  coX.WhenPressed(new Intaking);
  coY.WhenPressed(new Scale);
  coLB.WhenPressed(new Outtaking());
  coRB.WhenPressed(new ShootAll);
  coStart.WhenPressed(new ScaleBackwards);
  coSelect.WhenPressed(new SetIntake(0.0));





  SmartDashboard::PutData("Far Shooting Position", new SetArmPosition(13344));
  SmartDashboard::PutData("PuncherButton", new SlingShot(0.5));
  SmartDashboard::PutData("Half Arm", new SetArmPosition(8500));
  SmartDashboard::PutData("Quarter Arm", new SetArmPosition(6250));
  SmartDashboard::PutData("Full Arm", new SetArmPosition(17000));
  SmartDashboard::PutData("Reset Arm", new ResetArmPosition());
  SmartDashboard::PutData("Three Quarter Arm", new SetArmPosition(12750));
  SmartDashboard::PutData("Zero Arm", new SetArmPosition(0));
  SmartDashboard::PutData("Brake Off", new BrakeOff());
  SmartDashboard::PutData("Brake On", new BrakeOn());
  SmartDashboard::PutData("Intake Disengage", new IntakeDisengage());
  SmartDashboard::PutData("Intake Engage", new IntakeEngage());
  SmartDashboard::PutData("Sling Engage", new SetSlingEngagement());
  SmartDashboard::PutData("Sling Disengage", new SetSlingDisengagement());
  SmartDashboard::PutData("Ramp Engage", new SetRamp(Ramp::kRelease));
  SmartDashboard::PutData("Ramp Disengage", new SetRamp(Ramp::kDontRelease));
  SmartDashboard::PutData("Calibrate Arm", new Calibrate);

  // Setup AutoCommands on the Dashboard
  SmartDashboard::PutData("Auto Run", new AutoRun());
  SmartDashboard::PutData("Auto Right Switch", new AutoRightSwitch());
  SmartDashboard::PutData("Auto Left Switch", new AutoLeftSwitch());
  SmartDashboard::PutData("Auto Left Scale", new AutoLeftScale());
  //SmartDashboard::PutData("Auto Switch Side", new AutoSwitchSide());
  SmartDashboard::PutData("Auto Left Switch Full", new AutoFullLeftSwitch);
  SmartDashboard::PutData("Auto Right Switch Full", new AutoFullRightSwitch);

  SmartDashboard::PutData("Auto Switch", new AutoSwitchSelector(new AutoFullLeftSwitch(), new AutoFullRightSwitch()));

  static const double kMaxPuncher = 17809;//number used in group commands if changed here change in PrepSwitch
  SmartDashboard::PutData("Quarter Puncher", new DrawSling(kMaxPuncher/4.0));
  SmartDashboard::PutData("Half Puncher", new DrawSling(kMaxPuncher/2));
  SmartDashboard::PutData("Full Puncher", new DrawSling(kMaxPuncher));
  SmartDashboard::PutData("Three Quarter Puncher", new DrawSling(kMaxPuncher* 3.0/4.0));
  SmartDashboard::PutData("Seventh Puncher", new DrawSling(kMaxPuncher* 7.0/8.0));
  SmartDashboard::PutData("Eighth Puncher", new DrawSling(kMaxPuncher/8.0));
  SmartDashboard::PutData("Thirdth Puncher", new DrawSling(kMaxPuncher* 3.0/8.0));
  SmartDashboard::PutData("Fifth Puncher", new DrawSling(kMaxPuncher* 5/8));
  SmartDashboard::PutData("Reset Puncher", new ResetPuncherPosition);
  SmartDashboard::PutData("Prep Shoot", new PrepShoot());
  SmartDashboard::PutNumber("Puncher zeroing Voltage", 0);
  SmartDashboard::PutData("Puncher Voltage", new PuncherVoltage());
  SmartDashboard::PutData("Intake on", new SetIntake(1.0));
  SmartDashboard::PutData("Inkaking", new Intaking);
  SmartDashboard::PutData("Puncher Move", new SlingShot(0.5));

  SmartDashboard::PutData("Intake out", new SetIntake(-0.3));


}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getDriver() {
   return driver;
}

double OI::getDriverLeftXAxis() const{
	return driver->GetRawAxis(kLeftXAxis_ID);
}
double OI::getDriverLeftYAxis() const{
	return driver->GetRawAxis(kLeftYAxis_ID);
}
double OI::getDriverRightXAxis() const{
	return driver->GetRawAxis(kRightXAxis_ID);
}
double OI::getDriverRightYAxis() const{
	return driver->GetRawAxis(kRightYAxis_ID);
}

bool OI::isDriverBPressed() {
  return dB.Get();
}

bool OI::isCodriverLBPressed() {
  return coLB.Get();
}

std::shared_ptr<Joystick> OI::getCoDriver() {
   return coDriver;
}

double OI::getCoDriverLeftXAxis() const{
	return coDriver->GetRawAxis(kLeftXAxis_ID);
}
double OI::getCoDriverLeftYAxis() const{
	return coDriver->GetRawAxis(kLeftYAxis_ID);
}
double OI::getCoDriverRightXAxis() const{
	return coDriver->GetRawAxis(kRightXAxis_ID);
}
double OI::getCoDriverRightYAxis() const{
	return coDriver->GetRawAxis(kRightYAxis_ID);
}
