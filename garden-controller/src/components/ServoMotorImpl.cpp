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


void ServoMotorImpl::moveOf(int pass){
  if(this -> getPosition() + pass > 180){
    if (180 - this -> getPosition() == 0){
        this -> setPosition(180);
    } else {
        int diff = 180 - this -> getPosition();
        this -> setPosition(180);
        this -> setPosition(0);
        this -> setPosition(diff);
    }
  } else {
    this -> setPosition(this -> getPosition() + pass);
  }
}