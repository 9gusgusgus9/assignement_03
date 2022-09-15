#ifndef __LED__
#define __LED__

#include "Arduino.h"

enum LedStatus {
    OFF,
    ON
};

class Led{
private:
    int pin;
    int currentIntensity;
    LedStatus status;

public:
    Led(int pin);
    void init();
    void setIntensity(int intensity);
    int getIntensity();
    void set(LedStatus status);
};

#endif