// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "GantrySubsystem.h"
#include "../Logging.h"
#include "../RobotMap.h"
#include "../Commands/CheckContainerAlignmentCommand.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

GantrySubsystem::GantrySubsystem() : Subsystem("GantrySubsystem") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftLiftSolenoid = RobotMap::gantrySubsystemLeftLiftSolenoid;
	rightLiftSolenoid = RobotMap::gantrySubsystemRightLiftSolenoid;
	leftGripSolenoid = RobotMap::gantrySubsystemLeftGripSolenoid;
	rightGripSolenoid = RobotMap::gantrySubsystemRightGripSolenoid;
	crateAlignedSwich = RobotMap::gantrySubsystemCrateAlignedSwich;
	restraintSolenoid = RobotMap::gantrySubsystemRestraintControlSolenoid;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	OpenGrip();
}
    
void GantrySubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new CheckContainerAlignmentCommand());

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
bool GantrySubsystem::CheckContainerAlignedLimitSwitch() {
	uint32_t switchState = crateAlignedSwich->Get();

	// This assumes the limit switch is normally closed
	// and reading non-zero
	// When it reads zero, the switch is open, indicating the limit was hit.
	bool limitHit = (switchState == 0) ? false : true;

	if (limitHit)
	{
//		Logger::GetInstance()->Log(GantrySubsystemLogId, Logger::kWARNING, "*** Container Aligned Limit Switch Hit ***");
	}

	return limitHit;
}
void GantrySubsystem::FireLiftSolenoid(bool fire) {
	leftLiftSolenoid->Set(fire);
	rightLiftSolenoid->Set(fire);
}

bool GantrySubsystem::ToggleLiftSolenoid() {
	ToggleSolenoid(rightLiftSolenoid);
	return ToggleSolenoid(leftLiftSolenoid);
}

bool GantrySubsystem::IsLiftRaised() const
{
	return leftLiftSolenoid->Get() && rightLiftSolenoid->Get();
}


void GantrySubsystem::SetRestraintSolenoid(bool fire) {
	restraintSolenoid->Set(fire);
}

bool GantrySubsystem::ToggleRestraintSolenoid() {
	return ToggleSolenoid(restraintSolenoid);
}

bool GantrySubsystem::IsRestraintApplied() const
{
	return restraintSolenoid->Get();
}

void GantrySubsystem::CloseGrip()
{
	leftGripSolenoid->Set(DoubleSolenoid::kForward); //I flipped the kForward and the kReverse so that
	rightGripSolenoid->Set(DoubleSolenoid::kForward);//OpenGrip() opens the Grip
	gripClosed = true;								 //and CloseGrip() closes the grip
}

void GantrySubsystem::OpenGrip()
{
	if (!IsLiftRaised()){
		leftGripSolenoid->Set(DoubleSolenoid::kReverse);
		rightGripSolenoid->Set(DoubleSolenoid::kReverse);
		gripClosed = false;
	}
}

bool GantrySubsystem::ToggleGrip()
{
	if (gripClosed)
	{
		OpenGrip();
	}
	else
	{
		CloseGrip();
	}

	return gripClosed;
}

bool GantrySubsystem::ToggleSolenoid(Solenoid* solenoid) {
	bool state = !solenoid->Get();
	solenoid->Set(state);
	return state;
}

