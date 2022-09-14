#ifndef __LED__
#define __LED__

#include "Arduino.h"
#include "../utils/manifest/Manifest.h"

class Led
{
private:
    int pin;
    int currentIntensity;
    int state; // 0 off, 1 on


public:
    Led(int pin);
    void init();
    void setIntensity(int intensity);
    int getIntensity();
    void set(LedStatus status);
};

#endif