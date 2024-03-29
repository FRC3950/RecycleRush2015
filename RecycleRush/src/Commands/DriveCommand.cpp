// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveCommand.h"

#include "Logging.h"

DriveCommand::DriveCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::driveSubsystem);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void DriveCommand::Initialize() {
	Logger::GetInstance()->Log(DriveSubsystemLogId, Logger::kINFO, "DriveCommand Initialized()");
}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() {
	float x = Robot::oi->GetDriveStickX();
	float y = Robot::oi->GetDriveStickY();
	float twist = Robot::oi->GetDriveRotation();
	bool slowModeEnabled = Robot::oi->GetSlowDownEnabled();

	Logger::GetInstance()->Log(DriveSubsystemLogId, Logger::kTRACE, "DriveCommand: drive joyStick values(x,y,twist,slowMode)=(%f, %f, %f,%s)",
							   x, y, twist, slowModeEnabled ? "TRUE" : "FALSE");

	Robot::driveSubsystem->MecanumDrive(x, y, twist, slowModeEnabled);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished() {
	Logger::GetInstance()->Log(DriveSubsystemLogId, Logger::kTRACE, "DriveCommand IsFinished() called.");
	return false;
}

// Called once after isFinished returns true
void DriveCommand::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted() {
}
