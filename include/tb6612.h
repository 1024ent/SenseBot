/**
 * @file tb6612.h
 * @brief TB6612 Motor Driver Library
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

 // Speed and Delay Duration Declaration
#define MID_SPEED 100    
#define HIGH_SPEED 120    
#define LOW_SPEED 90
#define LONG_DELAY_TIME 110 
#define DELAY_TIME 80 
#define SHORT_DELAY_TIME 70 

// PWM Channel Declaration
const int pwmChannel_left = 1;       // PWM channel (0-15)
const int pwmFrequency_left = 5000;  // Frequency in Hz
const int pwmResolution_left = 8;    // Resolution in bits (0-255)
const int pwmChannel_right = 0;       // PWM channel (0-15)
const int pwmFrequency_right = 5000;  // Frequency in Hz
const int pwmResolution_right = 8;    // Resolution in bits (0-255)

class Motor
{
  public:
    // Constructor. Mainly sets up pins.
    Motor(int In1pin, int In2pin, int PWMpin, int offset, int STBYpin);      

    // Drive in direction given by sign, at speed given by magnitude of the 
	//parameter.
    void drive(int speed);  
	
	// drive(), but with a delay(duration)
    void drive(int speed, int duration);  
	
	//Stops motor by setting both input pins high
    void brake(); 
	
	//set the chip to standby mode.  The drive function takes it out of standby 
	//(forward, back, left, and right all call drive)
	void standby();	
	
  private:
    //variables for the 2 inputs, PWM input, Offset value, and the Standby pin
	int In1, In2, LEFT_AIN1, LEFT_AIN2, LEFT_BIN1, LEFT_BIN2, RIGHT_AIN1, RIGHT_AIN2, RIGHT_BIN1, RIGHT_BIN2, PWM, Offset,Standby;
	
    // Private Function That Spin Motor CC And CCW
    void FL_fwd(int speed);           // Front Left Rotate Clockwise
    void FL_rev(int speed);           // Front Left Rotate Counter Clockwise
    void RL_fwd(int speed);           // Rear Left Rotate Clockwise
    void RL_rev(int speed);           // Rear Left Rotate Counter Clockwise
    void FR_fwd(int speed);         // Front Right Rotate Clockwise
    void FR_rev(int speed);         // Front Right Rotate Counter Clockwise
    void RR_fwd(int speed);         // Rear Right Rotate Clockwise
    void RR_rev(int speed);         // Rear RIght Rotate Counter Clockwise
    void brake(int speed);                                          // Stop all motor
};