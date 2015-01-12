// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::driveSubsystemSpeedControllerleft1 = NULL;
SpeedController* RobotMap::driveSubsystemSpeedControllerleft2 = NULL;
SpeedController* RobotMap::driveSubsystemSpeedControllerright1 = NULL;
SpeedController* RobotMap::driveSubsystemSpeedControllerright2 = NULL;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
RobotDrive* RobotMap::driveSubsystemRobotDriveArcade = NULL;


void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	driveSubsystemSpeedControllerleft1 = new Victor(1);
	lw->AddActuator("DriveSubsystem", "Speed Controller left 1", (Victor*) driveSubsystemSpeedControllerleft1);
	
	driveSubsystemSpeedControllerleft2 = new Victor(2);
	lw->AddActuator("DriveSubsystem", "Speed Controller left 2", (Victor*) driveSubsystemSpeedControllerleft2);
	
	driveSubsystemSpeedControllerright1 = new Victor(3);
	lw->AddActuator("DriveSubsystem", "Speed Controller right 1", (Victor*) driveSubsystemSpeedControllerright1);
	
	driveSubsystemSpeedControllerright2 = new Victor(4);
	lw->AddActuator("DriveSubsystem", "Speed Controller right 2", (Victor*) driveSubsystemSpeedControllerright2);
	

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	driveSubsystemRobotDriveArcade = new RobotDrive(driveSubsystemSpeedControllerleft1, driveSubsystemSpeedControllerleft2,
			driveSubsystemSpeedControllerright1, driveSubsystemSpeedControllerright2);

	driveSubsystemRobotDriveArcade->SetInvertedMotor(RobotDrive::kFrontLeftMotor,true);
	driveSubsystemRobotDriveArcade->SetInvertedMotor(RobotDrive::kFrontRightMotor,true);
	driveSubsystemRobotDriveArcade->SetInvertedMotor(RobotDrive::kRearLeftMotor,true);
	driveSubsystemRobotDriveArcade->SetInvertedMotor(RobotDrive::kRearRightMotor,true);
}
