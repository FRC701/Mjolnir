#include "Ramp.h"
#include "DoubleSolenoid.h"
#include "Commands/SetRamp.h"
#include "RobotMap.h"
#include "Commands/SetRampMotor.h"



const char Ramp::kSubsystemName[] = "Ramp";

std::shared_ptr<Ramp> Ramp::self;

std::shared_ptr<Ramp> Ramp::getInstance() {
  if (! self) {
     self = std::shared_ptr<Ramp>(new Ramp);
  }
  return self;
}


Ramp::Ramp() : Subsystem(kSubsystemName),
  actuator(RobotMap::kIDActuatorForward, RobotMap::kIDActuatorReverse),
  RampMotor(RobotMap::kIDRampMotor)
{
  SetUpTalons();
}

void Ramp::SetRamp(RampValue value) {
  actuator.Set(static_cast<DoubleSolenoid::Value>(value));
}

void Ramp::RampMotor(double speed){
  RampMotor.Set(speed);
}
