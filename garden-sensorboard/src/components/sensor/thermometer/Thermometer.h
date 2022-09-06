#ifndef _THERMOMETER_
#define _THERMOMETER_

#include <Arduino.h>
#include "../Sensor.h"
#define AREF_VOLTAGE 3.3

class Thermometer : public Sensor {

    private:

    uint8_t pin;
    uint8_t temperature;

    public:
    
    Thermometer(uint8_t pin);

    void setup();
    
    void compute();

    uint8_t getTemperature();
    
    String toString();
};



#endif