#include <Arduino.h>
#include <PS4Controller.h>

// Line Sensor Pins
#define   LINE_D1     33
#define   LINE_D2     32
#define   LINE_D3     35
#define   LINE_D4     34
#define   LINE_D5     36

// TB6612FNG STBY PIN
#define   STBY        10

// TB6612FNG PWM PIN LEFT MOTOR
#define   LEFT_PWM    13
const int pwmChannel_left = 1;       // PWM channel (0-15)
const int pwmFrequency_left = 5000;  // Frequency in Hz
const int pwmResolution_left = 8;    // Resolution in bits (0-255)

// TB6612FNG PWM PIN RIGHT MOTOR
#define   RIGHT_PWM   4
const int pwmChannel_right = 0;       // PWM channel (0-15)
const int pwmFrequency_right = 5000;  // Frequency in Hz
const int pwmResolution_right = 8;    // Resolution in bits (0-255)

// LEFT FRONT MOTOR
#define   LEFT_AIN1  27
#define   LEFT_AIN2  14

// LEFT REAR MOTOR
#define   LEFT_BIN1  26
#define   LEFT_BIN2  25

// RIGHT FRONT MOTOR
#define   RIGHT_AIN1  19
#define   RIGHT_AIN2  18

// RIGHT REAR MOTOR
#define   RIGHT_BIN1  21
#define   RIGHT_BIN2  22

// Speed and Delay Duration Declaration
#define MID_SPEED 100    
#define HIGH_SPEED 120    
#define LOW_SPEED 90
#define LONG_DELAY_TIME 110 
#define DELAY_TIME 80 
#define SHORT_DELAY_TIME 70 

// Motor Driver Function Declaration
void FL_fwd(int speed);                                 // Front Left Rotate Clockwise
void FL_rev(int speed);                                 // Front Left Rotate Counter Clockwise
void RL_fwd(int speed);                                 // Rear Left Rotate Clockwise
void RL_rev(int speed);                                 // Rear Left Rotate Counter Clockwise
void FR_fwd(int speed);                                 // Front Right Rotate Clockwise
void FR_rev(int speed);                                 // Front Right Rotate Counter Clockwise
void RR_fwd(int speed);                                 // Rear Right Rotate Clockwise
void RR_rev(int speed);                                 // Rear RIght Rotate Counter Clockwise
void brake(int speed);                                  // Stop all motor

// Standard Wheel Movement Function Declaration
void std_fwd(int speed);                                  // Standard Wheel Move Foward 
void std_rev(int speed);                                  // Standard Wheel Reverse
void std_left_fwd(int speed_1, int speed_);               // Standard Wheel Move Forward Left
void std_right_fwd(int speed_1, int speed_);              // Standard Wheel Move Forward Right
void std_left_rev(int speed_1, int speed_);               // Standard Wheel Reverse Left
void std_right_rev(int speed_1, int speed_);              // Standard Wheel Reverse Right

// Mecanum Wheel Movement Function Declaration
void mecanum_move_fwd(int speed);           // Mecanum Wheel Move Foward
void mecanum_move_rev(int speed);           // Mecanum Wheel Reverse
void mecanum_shift_left(int speed);         // Mecanum Wheel Shift to the Left
void mecanum_shift_right(int speed);        // Mecanum Wheel Shift to the Right
void mecanum_turn_left(int speed);          // Mecanum Wheel Turn to the Left
void mecanum_turn_right(int speed);         // Mecanum Wheel Turn to the Right
void mecanum_left_fwd(int speed);           // Mecanum Wheel Move to the Left
void mecanum_right_fwd(int speed);          // Mecanum Wheel Move to the Right
void mecanum_left_rev(int speed);           // Mecanum Wheel Reverse Left
void mecanum_right_rev(int speed);          // Mecanum Wheel Reverse Right
void mecanum_sharp_right_turn(int speed);   // Mecanum Wheel Move Sharp Right
void mecanum_sharp_left_turn(int speed);    // Mecanum Wheel Move Sharp Left

void setup() 
{
  // Line sensor pins
  pinMode(LINE_D1, INPUT);
  pinMode(LINE_D2, INPUT);
  pinMode(LINE_D3, INPUT);
  pinMode(LINE_D4, INPUT);
  pinMode(LINE_D5, INPUT);

  // Left motor TB6612FNG pins
  ledcSetup(pwmChannel_left, pwmFrequency_left, pwmResolution_left);
  ledcAttachPin(LEFT_PWM, pwmChannel_left);
  pinMode(LEFT_AIN1, OUTPUT);
  pinMode(LEFT_AIN2, OUTPUT);
  pinMode(LEFT_BIN1, OUTPUT);
  pinMode(LEFT_BIN2, OUTPUT);

  // Right motor TB6612FNG pins
  ledcSetup(pwmChannel_right, pwmFrequency_right, pwmResolution_right);
  ledcAttachPin(RIGHT_PWM, pwmChannel_right);
  pinMode(RIGHT_AIN1, OUTPUT);
  pinMode(RIGHT_AIN2, OUTPUT);
  pinMode(RIGHT_BIN1, OUTPUT);
  pinMode(RIGHT_BIN2, OUTPUT);

  Serial.begin(115200);
}

void loop() 
{

}

// Motor Driver Function
void FL_fwd(int speed){
  digitalWrite(LEFT_AIN1,1);
  digitalWrite(LEFT_AIN2,0);
  ledcWrite(pwmChannel_left, speed);
}

void FL_rev(int speed){
  digitalWrite(LEFT_AIN1,0);
  digitalWrite(LEFT_AIN2,1);
  ledcWrite(pwmChannel_left, speed);
}

void RL_fwd(int speed){
  digitalWrite(LEFT_BIN1,1);
  digitalWrite(LEFT_BIN2,0);
  ledcWrite(pwmChannel_left, speed);
}

void RL_rev(int speed){
  digitalWrite(LEFT_BIN1,0);
  digitalWrite(LEFT_BIN2,1);
  ledcWrite(pwmChannel_left, speed);
}

void FR_fwd(int speed){
  digitalWrite(RIGHT_AIN1,1);
  digitalWrite(RIGHT_AIN2,0);
  ledcWrite(pwmChannel_right, speed);
}

void FR_rev(int speed){
  digitalWrite(RIGHT_AIN1,0);
  digitalWrite(RIGHT_AIN2,1);
  ledcWrite(pwmChannel_right, speed);
}

void RR_fwd(int speed){
  digitalWrite(RIGHT_BIN1,1);
  digitalWrite(RIGHT_BIN2,0);
  ledcWrite(pwmChannel_right, speed);
}

void RR_rev(int speed){
  digitalWrite(RIGHT_BIN1,0);
  digitalWrite(RIGHT_BIN2,1);
  ledcWrite(pwmChannel_right, speed);
}

void brake(int speed){
  digitalWrite(LEFT_AIN1,1);
  digitalWrite(LEFT_AIN2,1);  
  digitalWrite(LEFT_BIN1,1);
  digitalWrite(LEFT_BIN2,1);
  ledcWrite(pwmChannel_left, speed);  
  digitalWrite(RIGHT_AIN1,1);
  digitalWrite(RIGHT_AIN2,1);
  digitalWrite(RIGHT_BIN1,1);
  digitalWrite(RIGHT_BIN2,1);
  ledcWrite(pwmChannel_right, speed);  
}

// Standard Wheel Movement Function
void std_fwd(int speed){
  FL_fwd(speed);
  RL_fwd(speed);
  FR_fwd(speed);
  RR_fwd(speed);
}

void std_rev(int speed){
  FL_rev(speed);
  RL_rev(speed);
  FR_rev(speed);
  RR_rev(speed);
}

void std_left_fwd(int speed_1, int speed_2){

}

void std_right_fwd(int speed_1, int speed_){

}

void std_left_rev(int speed_1, int speed_){

}

void std_right_rev(int speed_1, int speed_){

}

// Mecanum Wheel Movement Function
void mecanum_move_fwd(int speed){

}

void mecanum_move_rev(int speed){

}

void mecanum_shift_left(int speed){
  
}

void mecanum_shift_right(int speed){
  
}

void mecanum_turn_left(int speed){

}

void mecanum_turn_right(int speed){

}

void mecanum_left_fwd(int speed){
  
}

void mecanum_right_fwd(int speed){

}

void mecanum_left_rev(int speed){

}

void mecanum_right_rev(int speed){

}

void mecanum_sharp_right_turn(int speed){
  
}

void mecanum_sharp_left_turn(int speed){

}
