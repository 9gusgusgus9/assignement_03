#ifndef __MANIFEST__
#define __MANIFEST__

#define Tback 5000
#define Tmake 10000
#define TtoTake 40000
#define TtoTest 180000
#define TtoSleep 60000
#define T_MAX 35.0
#define T_MIN 17.0
#define AVIABLE_COFFE 50
#define AVIABLE_TEA 50
#define AVIABLE_CHOCOLATE 50
#define BUP 4
#define BDOWN 2
#define BMAKE 3
#define POT 14
#define ECHO 7
#define TRIG 8
#define SERVO 9
#define TEMP 15
#define Tinit 3000
#define PIR 5

#include "Arduino.h"
#include "../manager/ServoMotorImpl.h"
#include "../manager/CoffeDisplay.h"
#include "../manager/Sensor.h"
#include "../manager/Temperature.h"
#include "../manager/Pir.h"

enum Status{
    INIT,
    MACHINE_READY,
    PRODUCT_SUGAR_SELECTION,
    MAKING_PROCESS,
    PRODUCT_READY,
    COME_BACK,
    ASSISTANCE_MODE,
    ASSISTANCE_REFILL_REQUIRED,
    CHECK_TEST,
    SLEEP_MODE
};

inline const char* toString(Product prod){
    switch(prod){
        case COFFE: return "Coffe";
        case TEA: return "Tea";
        case CHOCOLATE: return "Chocolate";
        default: return "";
    }
}

class Manifest{
    CoffeDisplay* display;
    int coffeCounter = 0;
    int teaCounter = 0;
    int chocolateCounter = 0;
    Product lastPoured;
    int sugar;
    bool testToSleep;
    Status status;
    ServoMotorImpl* servo;
    Sensor* sensor;
    Temperature* temperature;
    bool isTimeToTest;
    int testCounter;
    Pir* pir;
    unsigned long lastDetection;



public:
    Manifest();
    bool isAvailable(Product prod);
    bool someProductAvailable();
    void setLastPouredOut(Product prod);
    Product getLastPouredOut();
    void setSugar(int sugar);
    int getSugar();
    Status getStatus();
    void setStatus(Status status);
    ServoMotorImpl* getServo();
    CoffeDisplay* getDisplay();
    Sensor* getSensor();
    bool isTestBeforeSleep();
    double getTemperature();
    bool timeToTest();
    void setTimeToTest(bool value);
    Pir* getPir();
    void detection();
    unsigned long getLastDetection();
    String msgToSend();
    void refill();
    void incTest();
};

#endif