// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Joystick> coDriver;
	std::shared_ptr<JoystickButton> coButtonRB;
	std::shared_ptr<JoystickButton> coButtonLB;
	std::shared_ptr<JoystickButton> coButtonY;
	std::shared_ptr<JoystickButton> coButtonX;
	std::shared_ptr<JoystickButton> coButtonB;
	std::shared_ptr<JoystickButton> coButtonA;
	std::shared_ptr<Joystick> driver;
	std::shared_ptr<JoystickButton> dButtonLB;
	std::shared_ptr<JoystickButton> dButtonRB;
	std::shared_ptr<JoystickButton> dButtonY;
	std::shared_ptr<JoystickButton> dButtonX;
	std::shared_ptr<JoystickButton> dButtonB;
	std::shared_ptr<JoystickButton> dButtonA;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYP
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
	static std::shared_ptr<OI> self;
	std::shared_ptr<Joystick> driver;
	JoystickButton dA;
	JoystickButton dB;
	JoystickButton dX;
	JoystickButton dY;
	JoystickButton dLB;
	JoystickButton dRB;
	std::shared_ptr<Joystick> coDriver;
	JoystickButton coA;
	JoystickButton coB;
	JoystickButton coX;
	JoystickButton coY;
	JoystickButton coLB;
	JoystickButton coRB;
public:
	static std::shared_ptr<OI> getInstance();
	OI();
	std::shared_ptr<Joystick> getDriver();
	double getDriverLeftXAxis() const;
	double getDriverLeftYAxis() const;
	double getDriverRightXAxis() const;
	double getDriverRightYAxis() const;
	std::shared_ptr<Joystick> getCoDriver();
	double getCoDriverLeftXAxis() const;
	double getCoDriverLeftYAxis() const;
	double getCoDriverRightXAxis() const;
	double getCoDriverRightYAxis() const;

	static const int kButtonA_ID = 1;
	static const int kButtonB_ID = 2;
	static const int kButtonX_ID = 3;
	static const int kButtonY_ID = 4;
	static const int kButtonLB_ID = 5;
	static const int kButtonRB_ID = 6;
	static const int kLeftXAxis_ID = 0;
	static const int kLeftYAxis_ID = 1;
	static const int kRightXAxis_ID = 4;
	static const int kRightYAxis_ID = 5;

};

#endif