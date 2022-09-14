#include "Led.h"
#include "Arduino.h"

Led::Led(int pin){
    this->pin = pin;
    this->currentIntensity = 0;
}

void Led::init(){
    pinMode(pin, OUTPUT);
    this->state = 0;
}

void Led::setIntensity(int intensity){
    this->currentIntensity = intensity;
    int value = map(currentIntensity, 0, 5, 0, 255);
    analogWrite(pin, value);
}

int Led::getIntensity(){
    return this->currentIntensity;
}

void Led::turn(){
    if(this->state == 1){
        digitalWrite(pin, LOW);
        state = 0;
    } else {
        digitalWrite(pin, HIGH);
        state = 1;
    }
}
