// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// Java from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
package org.usfirst.frc3950.Robot2013.commands;
import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc3950.Robot2013.OI;
import org.usfirst.frc3950.Robot2013.Robot;
/**
 *
 */
public class ClimberElevate extends Command {
    private static long maxTimeEverBetweenExecuteCalls = 0;
    private long maxTimeForCommand = 0;
    private long lastExecuteCallTime = 0;
    
    public ClimberElevate() {
        // Use requires() here to declare subsystem dependencies
        // eg. requires(chassis);
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
        requires(Robot.climberScrew);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    }
    // Called just before this Command runs the first time
    protected void initialize() {
    }
    
    private static final long MAX_LIMIT_SWITCH_TIMECHECK_THRESHOLD_IN_MS = 50;
    
    // Called repeatedly when this Command is scheduled to run
    protected void execute() {
        long currTime = System.currentTimeMillis();
         if (lastExecuteCallTime != 0) {
             long timeSpan = currTime - lastExecuteCallTime;
             
             if (timeSpan > maxTimeForCommand) {
                 maxTimeForCommand = timeSpan;
                 
                 if (maxTimeForCommand > MAX_LIMIT_SWITCH_TIMECHECK_THRESHOLD_IN_MS) {
                     System.out.println("WARNING: Max time (between) for current command between limit switch checks is " + maxTimeForCommand + "ms.");
                 }
             }
             
             if (timeSpan > maxTimeEverBetweenExecuteCalls) {
                 maxTimeEverBetweenExecuteCalls = timeSpan;
                 
                 if (maxTimeEverBetweenExecuteCalls > MAX_LIMIT_SWITCH_TIMECHECK_THRESHOLD_IN_MS) {
                     System.out.println("WARNING: Most time for all command instances between limit switch checks is " + maxTimeEverBetweenExecuteCalls);
                 }
             }
             
             lastExecuteCallTime = currTime;
         }
         else {
             lastExecuteCallTime = currTime;
         }
             
        Robot.climberScrew.setHeight(Robot.oi.getClimberSpeed());
    }
    // Make this return true when this Command no longer needs to run execute()
    protected boolean isFinished() {
        return false;
        /*
        double climberSpeed = Robot.oi.getClimberSpeed();
        
        if (climberSpeed > 0.0) {
            return Robot.climberScrew.topLimitHit();
        }
        else if (climberSpeed < 0.0) {
            return Robot.climberScrew.bottomLimitHit();
        }
        
        return false;
        */
    }
    // Called once after isFinished returns true
    protected void end() {
    }
    // Called when another command which requires one or more of the same
    // subsystems is scheduled to run
    protected void interrupted() {
    }
}
