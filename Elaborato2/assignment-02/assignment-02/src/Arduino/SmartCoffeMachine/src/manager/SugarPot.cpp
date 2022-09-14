#include "SugarPot.h"
#include "../utils/Manifest.h"
#include "Arduino.h"

SugarPot::SugarPot(int pin){
    this -> pin = pin;
    pinMode(pin, INPUT);
}

int SugarPot::getSugarValue(){
    int pot = getValue();
    if(pot < 170){
        return 0;
    } else if(pot < 340){
        return 1;
    } else if(pot < 510){
        return 2;
    } else if(pot < 680){
        return 3;
    } else if(pot < 850){
        return 4;
    } else {
        return 5;
    }
}

int SugarPot::getValue(){
    return analogRead(pin);
}