#ifndef _DEVICE_BUILDER_
#define _DEVICE_BUILDER_

#include "Device.h"

class DeviceBuilder {

    private:

    Led* led;
    Thermometer* thermometer;
    Photoresistor* photoresistor;

    public:

    DeviceBuilder(){
        this->led = NULL;
        this->thermometer = NULL;
        this->photoresistor = NULL;
    }

    DeviceBuilder* concatLed(Led* led){
        this->led = led;
        return this;
    }

    DeviceBuilder* concatThermometer(Thermometer* thermometer){
        this->thermometer = thermometer;
        return this;
    }

    DeviceBuilder* concatPhotoresistor(Photoresistor* photoresistor){
        this->photoresistor = photoresistor;
        return this;
    }

    Device* build(){
        return new Device(this->led, this->thermometer, this->photoresistor);
    }
};

#endif