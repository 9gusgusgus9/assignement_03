#ifndef _SENSOR_
#define _SENSOR_

class Sensor {

    public:
    
    virtual void setup() = 0;

    virtual void compute() = 0;
};

#endif