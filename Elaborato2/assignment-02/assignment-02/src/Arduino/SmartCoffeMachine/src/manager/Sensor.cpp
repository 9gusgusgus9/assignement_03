#include "Sensor.h"
#include "Arduino.h"

Sensor::Sensor(int echo, int trig){
    this -> echo = echo;
    this -> trig = trig;
    
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

float Sensor::getDistance(){
    /* invio impulso */
    digitalWrite(trig,LOW);
    delayMicroseconds(3);
    digitalWrite(trig,HIGH);
    delayMicroseconds(5);
    digitalWrite(trig,LOW);
    
    /* ricevi l’eco */
    float tUS = pulseIn(echo, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t*VS;
    return d;
}