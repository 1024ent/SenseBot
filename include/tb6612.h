/**
 * @file tb6612.h
 * @brief TB6612 Motor Driver Library
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#ifndef TB6612_H__
#define TB6612_H__

#include <Arduino.h>

class Motor{
  public:
    // Constructor. Mainly sets up pins.
    Motor(int In1pin, int In2pin, int PWMchannel, int PWMpin, int offset, int STBYpin);      

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
	int In1, In2, PWM_Channel, PWM, Offset, Standby;
	
	//private functions that spin the motor CC and CCW
	void fwd(int speed);
	void rev(int speed);
};

#endif
