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
using frc::Joystick;

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

,coDriver(new Joystick(1))
, coA(driver.get(), kButtonA_ID)
, coB(driver.get(), kButtonB_ID)
, coX(driver.get(), kButtonX_ID)
, coY(driver.get(), kButtonY_ID)
, coLB(driver.get(), kButtonLB_ID)
, coRB(driver.get(), kButtonRB_ID)

{

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
