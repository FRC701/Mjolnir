/*
 * Puncher.h
 *
 *  Created on: Jan 17, 2018
 *      Author: VandenRobotics
 */

#ifndef SRC_SUBSYSTEMS_PUNCHER_H_
#define SRC_SUBSYSTEMS_PUNCHER_H_

#include "Commands/Subsystem.h"
#include "ctre/Phoenix.h"
#include "DoubleSolenoid.h"

class Puncher: public frc::Subsystem {
private:
  static const char kSubsystemName[];
  static std::shared_ptr<Puncher> self;

  WPI_TalonSRX pullSling;
  frc::DoubleSolenoid releaseSling;


public:

  static std::shared_ptr<Puncher> getInstance();
  Puncher();


  void InitDefaultCommand();
  void SetSlingShot(double speed);
  bool GetPuncherLimit();
  void MotorDisengage();
  void MotorEngage();
  void SetUpTalon();
  int GetVelocity();
  int GetPosition();
  void SetUpMotionMagic();
  void SetPosition(double position);
  int GetPositionError();
  void ResetPuncherPos();
  double GetCurrent();
  bool IsCubeIn();
};



#endif /* SRC_SUBSYSTEMS_PUNCHER_H_ */
