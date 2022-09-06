#ifndef _PHOTORESISTOR_
#define _PHOTORESISTOR_

#include <Arduino.h>
#include "../Sensor.h"

class Photoresistor : public Sensor {

    private:
    
    uint8_t pin;
    uint8_t light;

    public:

    Photoresistor(uint8_t pin);

    void setup();

    void compute();

    uint8_t getLight();
};

#endif