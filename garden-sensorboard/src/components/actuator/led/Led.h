#ifndef _LED_
#define _LED_

#include <Arduino.h>
#include "../Actuator.h"

class Led: public Actuator {

    private:
    
    uint8_t pin;
    bool state;

    public:
    
    Led(uint8_t pin);

    void setup();
    
    void setState(bool state);

    bool getState();
};

#endif