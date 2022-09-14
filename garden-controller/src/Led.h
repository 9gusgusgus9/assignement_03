#ifndef __LED__
#define __LED__

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
    void turn();
};

#endif