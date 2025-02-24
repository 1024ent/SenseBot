/**
 * @file tb6612.cpp
 * @brief TB6612 Motor Driver Library
 * @copyright UMPSA ROBOTICS
 * @license Apache-2.0
 * @author Loo Hui Kie [ELPROG]
 */

#include <Arduino.h>
#include "tb6612.h"

Motor::Motor(int In1pin, int In2pin, int PWMchannel, int PWMpin, int offset, int STBYpin)
{
  In1 = In1pin;
  In2 = In2pin;
  PWM = PWMpin;
  PWM_Channel = PWMchannel;
  Standby = STBYpin;
  Offset = offset;
  
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  ledcAttachPin(PWM, PWM_Channel);
  ledcSetup(PWM_Channel, 5000, 8);
  pinMode(Standby, OUTPUT);
}

void Motor::drive(int speed)
{
  digitalWrite(Standby, HIGH);
  speed = speed * Offset;
  if (speed>=0) fwd(speed);
  else rev(-speed);
}
void Motor::drive(int speed, int duration)
{
  drive(speed);
  delay(duration);
}

void Motor::fwd(int speed)
{
   digitalWrite(In1, HIGH);
   digitalWrite(In2, LOW);
   ledcWrite(PWM_Channel, speed);
}

void Motor::rev(int speed)
{
   digitalWrite(In1, LOW);
   digitalWrite(In2, HIGH);
   ledcWrite(PWM_Channel, speed);
}

void Motor::brake()
{
   digitalWrite(In1, HIGH);
   digitalWrite(In2, HIGH);
   ledcWrite(PWM,0);
}

void Motor::standby()
{
   digitalWrite(Standby, LOW);
}

