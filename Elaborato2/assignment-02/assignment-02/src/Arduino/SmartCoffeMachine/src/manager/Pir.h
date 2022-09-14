#ifndef __PIR__
#define __PIR__

#define CALIBRATING_TIME 10000

class Pir {
    int pin;
    unsigned long timeInit;

    public:

    Pir(int pin);
    void calibrate();
    int getState();

};

#endif