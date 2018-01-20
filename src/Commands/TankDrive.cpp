// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "TankDrive.h"
#include "OI.h"
#include "Subsystems/Chassis.h"


TankDrive::TankDrive(): Command() {
	Requires(Chassis::getInstance().get());
}

void TankDrive::Initialize() {

}

void TankDrive::Execute() {
	std::shared_ptr<Chassis> chassis = Chassis::getInstance();

	std::shared_ptr<OI> oi = OI::getInstance();

	double left = oi->getDriverLeftYAxis();
	double right = oi->getDriverRightYAxis();

	chassis->SetTankDrive(left, right);


}

bool TankDrive::IsFinished() {
    return false;
}

void TankDrive::End() {

}

void TankDrive::Interrupted() {

}
