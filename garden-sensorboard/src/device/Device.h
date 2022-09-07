#ifndef _DEVICE_
#define _DEVICE_

//#include <PubSubClient.h>

#include "../components/actuator/led/Led.h"
#include "../components/sensor/thermometer/Thermometer.h"
#include "../components/sensor/photoresistor/Photoresistor.h"

class Device {

    private:
    
    Led* led;
    Thermometer* thermometer;
    Photoresistor* photoresistor;

    public:

    Device(Led* led, Thermometer* thermometer, Photoresistor* photoresistor);

    void setup();

    void compute();

    Led* getLed();

    Thermometer* getThermometer();

    Photoresistor* getPhotoresistor();
};

#endif