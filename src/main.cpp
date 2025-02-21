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

// TB6612FNG PWM PIN RIGHT MOTOR
#define   RIGHT_PWM   4
const int pwmChannel_right = 0;       // PWM channel (0-15)
const int pwmFrequency_right = 5000;  // Frequency in Hz
const int pwmResolution_right = 8;    // Resolution in bits (0-255)

// TB6612FNG PWM PIN LEFT MOTOR
#define   LEFT_PWM    13
const int pwmChannel_left = 1;       // PWM channel (0-15)
const int pwmFrequency_left = 5000;  // Frequency in Hz
const int pwmResolution_left = 8;    // Resolution in bits (0-255)

// RIGHT FRONT MOTOR
#define   RIGHT_AIN1  19
#define   RIGHT_AIN2  18

// RIGHT REAR MOTOR
#define   RIGHT_BIN1  21
#define   RIGHT_BIN2  22

// LEFT FRONT MOTOR
#define   LEFT_AIN1  27
#define   LEFT_AIN2  14

// LEFT REAR MOTOR
#define   LEFT_BIN1  26
#define   LEFT_BIN2  25

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
