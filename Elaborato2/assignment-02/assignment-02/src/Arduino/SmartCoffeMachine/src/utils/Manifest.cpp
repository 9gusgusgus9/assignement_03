#include "Manifest.h"

Manifest::Manifest(){
    this -> servo = new ServoMotorImpl(SERVO);
    this -> display = new CoffeDisplay();
    this -> sensor = new Sensor(ECHO, TRIG);
    this -> temperature = new Temperature(TEMP);
    this -> pir = new Pir(PIR);
    this -> status = INIT;
    this -> testToSleep = false;
    this -> testCounter = 0;
    this -> isTimeToTest = false;
    this -> lastDetection = millis();
}

bool Manifest::isAvailable(Product product){
    switch(product){
        case COFFE:
            return AVIABLE_COFFE - coffeCounter > 0;
        case TEA:
            return AVIABLE_TEA - teaCounter > 0;
        case CHOCOLATE:
            return AVIABLE_CHOCOLATE - chocolateCounter > 0;
        default: 
            return true;
    }
}

bool Manifest::someProductAvailable(){
    return isAvailable(COFFE) || isAvailable(TEA) || isAvailable(CHOCOLATE);
}

void Manifest::setLastPouredOut(Product product){
    switch(product){
        case COFFE:
            coffeCounter++;
            break;
        case TEA:
            teaCounter++;
            break;
        case CHOCOLATE:
            chocolateCounter++;
            break;
    }
    lastPoured = product;
}

Product Manifest::getLastPouredOut(){
    return this -> lastPoured;
}

void Manifest::setSugar(int sugar){
    this -> sugar = sugar;
}

int Manifest::getSugar(){
    return this -> sugar;
}

Status Manifest::getStatus(){
    return this -> status;
}

void Manifest::setStatus(Status status){
    if(status == Status::MACHINE_READY){
        this -> detection();
    }
    this -> status = status;
}

ServoMotorImpl* Manifest::getServo(){
    return this -> servo;
}

CoffeDisplay* Manifest::getDisplay(){
    return this -> display;
}

Sensor* Manifest::getSensor(){
    return this -> sensor;
}

bool Manifest::isTestBeforeSleep(){
    return this -> testToSleep;
}

double Manifest::getTemperature(){
    return this -> temperature -> getTemperature();
}

bool Manifest::timeToTest(){
    return this -> isTimeToTest;
}

void Manifest::setTimeToTest(bool value){
    this -> isTimeToTest = value;
}

Pir* Manifest::getPir(){
    return this -> pir;
}

void Manifest::detection(){
    this -> lastDetection = millis();
}

unsigned long Manifest::getLastDetection(){
    return this -> lastDetection;
}

String Manifest::msgToSend(){
    String state;
    if(getStatus() == Status::MACHINE_READY){
        state = "IDLE";
    } else if(getStatus() == Status::ASSISTANCE_MODE){
        state = "ASSISTANCE";
    } else if(getStatus() == Status::CHECK_TEST){
        state = "TESTING";
    } else if(getStatus() == Status::INIT){
        state = "INITIALIZING";
    } else {
        state = "WORKING";
    }
    return "" + state + "," + String(AVIABLE_COFFE - this -> coffeCounter) + "," + String(AVIABLE_TEA - this -> teaCounter) + "," + String(AVIABLE_CHOCOLATE - this -> chocolateCounter) + "," + String(this -> testCounter);
}

void Manifest::refill(){
    this -> chocolateCounter = 0;
    this -> coffeCounter = 0;
    this -> teaCounter = 0;
}

void Manifest::incTest(){
    this -> testCounter++;
}