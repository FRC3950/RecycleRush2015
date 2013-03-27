// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// Java from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
package org.usfirst.frc3950.Robot2013.subsystems;
import org.usfirst.frc3950.Robot2013.RobotMap;
import org.usfirst.frc3950.Robot2013.commands.*;
import edu.wpi.first.wpilibj.*;
import edu.wpi.first.wpilibj.smartdashboard.*;
import edu.wpi.first.wpilibj.command.PIDSubsystem;
import edu.wpi.first.wpilibj.livewindow.LiveWindow;
import org.usfirst.frc3950.Robot2013.Robot;
/**
 *
 */
public class ShootingScrew extends PIDSubsystem {
    private static final double VOLTS_PER_DEGREE_FOR_5K_POT = .0119;
    
    private static final double Kp = 9.0;
    private static final double Ki = 0.0;
    private static final double Kd = 1.0;
    
    private volatile double angleErrorCorrectionFactor = 0.0;
    private boolean pidEnabled = false;
    private boolean angleLowerLimitHit = false;
    private double potFloor = 0.0;
    
    // Flags whether the POT floor home position check was done.
    private boolean potFloorCheckComplete = false;
    
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    SpeedController screwSpeedController = RobotMap.shootingScrewScrewSpeedController;
    AnalogChannel potentiometer = RobotMap.shootingScrewPotentiometer;
    PIDController shooterScrew = RobotMap.shootingScrewShooterScrew;
    DigitalInput angleLowerLimit = RobotMap.shootingScrewAngleLowerLimit;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // Initialize your subsystem here
    public ShootingScrew() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
        super("ShootingScrew", 1.0, 0.0, 0.0);
        setAbsoluteTolerance(0.2);
        getPIDController().setContinuous(false);
        LiveWindow.addActuator("Shooting Screw", "PIDSubsystem Controller", getPIDController());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
        // Use these to get going:
            // setSetpoint() -  Sets where the PID controller should move the system
        //                  to
        // enable() - Enables the PID controller.
    }
    
    private boolean pollLowerLimitSwitch() {
        boolean switchState = angleLowerLimit.get();
    //        System.out.println("bottomLimitSwitch.get() = " + switchState);
        angleLowerLimitHit = switchState;
        
        return angleLowerLimitHit;
    }
    
    private boolean pollUpperLimitSwitch() {
        // TBD if an upper limit switch is installed check it here.
        return false;
    }
    private static final double HOME_FINDING_SPEED = 0.6;
    
    public void findHomePosition() {
        
        // Check to see if the pot floor has already been
        // found.  Don't check for it again.
        if (potFloorCheckComplete) {
            return;
        }
        
        if (!pollLowerLimitSwitch()) {
            screwSpeedController.set(HOME_FINDING_SPEED);
            while (!pollLowerLimitSwitch()) {
                System.out.println("Moving the shooter down.");
            }
            
            screwSpeedController.set(0.0);
        }
        
        potFloor = returnPIDInput();
        System.out.println("potFloor = " + potFloor);
        potFloorCheckComplete = true;
     }
    
    public void initDefaultCommand() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
    }
    
    public void setPIDSubsystem(boolean enable) {
        if (enable && !pidEnabled) {
            pidEnabled = true;
            enable(); // - Enables the PID controller.
        }
        else if (!enable && pidEnabled) {
            pidEnabled = false;
            disable();
        }
    }
    
    protected double returnPIDInput() {
        // Return your input value for the PID loop
        // e.g. a sensor, like a potentiometer:
        // yourPot.getAverageVoltage() / kYourMaxVoltage;
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return potentiometer.getAverageVoltage();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
    }
    
    protected void usePIDOutput(double output) {
 //       System.out.println("usePIDOutput output = " + output);
        
        output *= -1;
        
        if ((output > 0.0) && pollLowerLimitSwitch())
        {
            System.out.println("usePIDOutput lower limit switch hit forcing output to 0");
            
            output = 0.0;
        }
        else if ((output < 0.0) && pollUpperLimitSwitch()) {
            System.out.println("usePIDOutput upper limit switch hit forcing output to 0");
            output = 0.0;
        }
        
        // Use output to drive your system, like a motor
        // e.g. yourMotor.set(output);
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
        screwSpeedController.pidWrite(output);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
    }
    public void potentiometerReading() {
        //System.out.println("Angle: " + potentiometer.getVoltage() * 60);
        //System.out.println("Voltage: " + potentiometer.getVoltage());
    }
    
    public double getPotentiometerReading() {
        double voltage = potentiometer.getVoltage();
        
        return voltage;
    }
    
    public boolean hasReachedTargetVoltage(double pidTargetVoltage)
    {
        double actualPosition = getPotentiometerReading();
        
        System.out.println("Pot Voltage = " + actualPosition);
        System.out.println("hasReachedAngle: desiredPosition = " + pidTargetVoltage + ", actual = " + actualPosition);
        
        return Math.abs(actualPosition - pidTargetVoltage) <= .01;
    }
    
    private static final double ERROR_CORRECTION_MIN = -100.00;
    private static final double ERROR_CORRECTION_MAX = 100.00;
    
    public void setErrorCorrection(double newVal) {
        if ((newVal <= ERROR_CORRECTION_MAX) && (newVal >= ERROR_CORRECTION_MIN)) {
            angleErrorCorrectionFactor = newVal;
            
            // Write the value to the field in the smart dashboard.
            LiveWindow.addSensor("Shooting Screw", "Error", potentiometer);
        }
     }
    
    public double getErrorCorrection() {
        return angleErrorCorrectionFactor;
    }
    
    private static final double MAX_ANGLE = 45.0;
    private static final double MIN_ANGLE = 0.0;
    
    public double setInclineAngle(double angle) {
        angle *= ((angleErrorCorrectionFactor + 100.0) / 100.00);
        
            if (angle < MIN_ANGLE) {
            angle = MIN_ANGLE;
        }
        else if (angle > MAX_ANGLE) {
            angle = MAX_ANGLE;
        }
        
        double pidInput = angleToVoltage(angle);
        
        System.out.println("Shooting Screw setting angle to " + angle + " degrees = " + pidInput + " volts");
        
        setSetpoint(pidInput);
        
        return pidInput;
    }
    
    public void shooterManualSpeed(double voltage) {
        if (pidEnabled) {
            setPIDSubsystem(false);
        }
        if ((voltage > 0.0) && pollLowerLimitSwitch()) {
            voltage = 0.0;
        }
        else if ((voltage < 0.0) && pollUpperLimitSwitch()) {
            voltage = 0.0;
        }
        screwSpeedController.set(voltage);
        //System.out.println("shooterManualSpeed: motor voltage = " + voltage);
        
        //System.out.println("shooterManualSpeed: Pot Voltage = " + getPotentiometerReading());
 
    }
    
    private static final double VOLTS_PER_DEGREE_FACTOR = 0.0119;
    
    private double angleToVoltage(double angle) {
        return angle * VOLTS_PER_DEGREE_FOR_5K_POT + potFloor;
    }
    
    private double voltageToAngle(double voltage) {
        
        return (voltage - potFloor) / VOLTS_PER_DEGREE_FOR_5K_POT ;
    }
}
