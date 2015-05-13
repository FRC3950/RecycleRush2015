// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include <Commands/CloseGripCommand.h>
#include "Logging.h"

CloseGripCommand::CloseGripCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::gantrySubsystem);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void CloseGripCommand::Initialize() {
	Logger::GetInstance()->Log(GantrySubsystemLogId, Logger::kINFO, "CloseGripCommand Initialized()");
}

// Called repeatedly when this Command is scheduled to run
void CloseGripCommand::Execute() {
	Robot::gantrySubsystem->CloseGrip();
	Logger::GetInstance()->Log(GantrySubsystemLogId, Logger::kINFO, "CloseGripCommand::Execute() -> Grip is closed.");
}

// Make this return true when this Command no longer needs to run execute()
bool CloseGripCommand::IsFinished() {
	Logger::GetInstance()->Log(GantrySubsystemLogId, Logger::kINFO, "CloseGripCommand IsFinished() called.");
	return true;
}

// Called once after isFinished returns true
void CloseGripCommand::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseGripCommand::Interrupted() {

}
