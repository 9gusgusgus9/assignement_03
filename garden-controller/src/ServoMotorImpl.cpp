#include "ServoMotorImpl.h"
#include "Arduino.h"

ServoMotorImpl::ServoMotorImpl(int pin){
  this->pin = pin;  
} 

void ServoMotorImpl::on(){
  motor.attach(pin);
}

void ServoMotorImpl::setPosition(int angle){
  motor.write(angle); 
}

void ServoMotorImpl::off(){
  motor.detach();    
}

int ServoMotorImpl::getPosition(){
  return motor.read();
}

void ServoMotorImpl::goToZero(){
  motor.write(0);
}