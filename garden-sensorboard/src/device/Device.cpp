#include "./Device.h"

Device::Device(Led* led, Thermometer* thermometer, Photoresistor* photoresistor){
    this->led = led;
    this->thermometer = thermometer;
    this->photoresistor = photoresistor;
}

void Device::setup(){
    this->led->setup();
    this->thermometer->setup();
    this->photoresistor->setup();
}

void Device::compute(){
    this->thermometer->compute();
    this->photoresistor->compute();
}

Led* Device::getLed(){
    return this->led;
}

Thermometer* Device::getThermometer(){
    return this->thermometer;
}

Photoresistor* Device::getPhotoresistor(){
    return this->photoresistor;
}