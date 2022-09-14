#include "ButtonImpl.h"
#include "Arduino.h"
#include "../utils/Manifest.h"

/* ----------------------- ButtonImpl --------------- */

ButtonImpl::ButtonImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);
  lastState = LOW;
} 
  
bool ButtonImpl::isPressed(){
    int curr = digitalRead(pin);
    if(lastState == HIGH && curr == LOW){
      lastState = curr;
      return true;
    } else {
      lastState = curr;
      return false;
    }
}

