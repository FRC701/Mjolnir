/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoScaleSelector.h"
#include "GameData.h"

#include "Commands/Scheduler.h"

using robovikes::GameData;

AutoScaleSelector::AutoScaleSelector(
    frc::Command* _leftCommand,
    frc::Command* _rightCommand)
: leftCommand(_leftCommand),
  rightCommand(_rightCommand)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoScaleSelector::Initialize() {
  GameData::Side side = GameData::GetScaleSide();

  if (side == GameData::Left) {
    frc::Scheduler::GetInstance()->AddCommand(leftCommand);
  } else if (side == GameData::Right) {
    frc::Scheduler::GetInstance()->AddCommand(rightCommand);
  }
}

