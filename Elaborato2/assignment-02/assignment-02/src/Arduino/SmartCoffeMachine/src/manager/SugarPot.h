#ifndef __SUGARPOT__
#define __SUGARPOT__

class SugarPot{
public:
    SugarPot(int pin);
    int getSugarValue();

private:
    int getValue();
    int pin;
};

#endif