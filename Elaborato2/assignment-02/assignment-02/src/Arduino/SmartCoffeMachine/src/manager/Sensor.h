#ifndef __SENSOR__
#define __SENSOR__
#define VS (331.45+0.62*19);

class Sensor{
    int echo;
    int trig;

    public:

    Sensor(int echo, int trig);
    float getDistance();

};

#endif