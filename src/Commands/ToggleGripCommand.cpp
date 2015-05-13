// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include <Commands/ToggleGripCommand.h>
#include "Logging.h"

ToggleGripCommand::ToggleGripCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::gantrySubsystem);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ToggleGripCommand::Initialize() {
	Logger::GetInstance()->Log(GantrySubsystemLogId, Logger::kINFO, "ToggleGripCommand Initialized()");
}

// Called repeatedly when this Command is scheduled to run
void ToggleGripCommand::Execute() {
	bool closed = Robot::gantrySubsystem->ToggleGrip();

	Logger::GetInstance()->Log(GantrySubsystemLogId, Logger::kINFO, "ToggleGripCommand::Execute() -> Grip is toggled to %s.",
								closed ? "CLOSED" : "OPEN");

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleGripCommand::IsFinished() {
	Logger::GetInstance()->Log(GantrySubsystemLogId, Logger::kINFO, "ToggleGripCommand IsFinished() called.");
	return true;
}

// Called once after isFinished returns true
void ToggleGripCommand::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleGripCommand::Interrupted() {

}
