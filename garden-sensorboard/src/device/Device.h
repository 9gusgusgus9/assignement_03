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

    const char* ssid = "Nome_WIFI";
    const char* password = "password";

    Device(Led* led, Thermometer* thermometer, Photoresistor* photoresistor){
        this->led = led;
        this->thermometer = thermometer;
        this->photoresistor = photoresistor;
    }

    void setup(){
        this->led->setup();
        this->thermometer->setup();
        this->photoresistor->setup();
    }

    void compute(){
        this->thermometer->compute();
        this->photoresistor->compute();
    }

    Led* getLed(){
        return this->led;
    }

    Thermometer* getThermometer(){
        return this->thermometer;
    }

    Photoresistor* getPhotoresistor(){
        return this->photoresistor;
    }
};

#endif