#ifndef __SERVO_MOTOR_IMPL__
#define __SERVO_MOTOR_IMPL__

#include "ServoMotor.h"
#include "Servo.h"

class ServoMotorImpl: public ServoMotor {

public:
  ServoMotorImpl(int pin);

  void on();
  void setPosition(int angle);
  void off();
  int getPosition();
  void moveOf(int pass);
    
private:
  int pin; 
  Servo motor;
};

#endif