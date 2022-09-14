#include "Led.h"
#include "Arduino.h"
#include "../utils/manifest/Manifest.h"

Led::Led(int pin){
    this->pin = pin;
    this->currentIntensity = 0;
}

void Led::init(){
    pinMode(pin, OUTPUT);
    this->status = OFF;
}

void Led::setIntensity(int intensity){
    this->currentIntensity = intensity;
    int value = map(currentIntensity, 0, 5, 0, 255);
    analogWrite(pin, value);
}

int Led::getIntensity(){
    return this->currentIntensity;
}

void Led::set(LedStatus status){
    if(status == ON){
        digitalWrite(pin, HIGH);
        
    } else if(status == OFF){
        digitalWrite(pin, LOW);
    }
}
