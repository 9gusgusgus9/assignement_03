#include "Temperature.h"
#include "Arduino.h"

Temperature::Temperature(int pin){
    this -> pin = pin;
    pinMode(pin, INPUT);
}

double Temperature::getTemperature(){
    return convertTemperature(analogRead(pin));
}