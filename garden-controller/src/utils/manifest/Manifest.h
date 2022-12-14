#ifndef __MANIFEST__
#define __MANIFEST__

#include "Arduino.h"
#include "Config.h"
#include "../../components/ServoMotorImpl.h"
#include "../../components/Led.h"

enum IrrigatorStatus {
    OPEN,
    CLOSE,
    READY
};

enum GardenStatus {
    MANUAL,
    AUTO,
    ALARM
};

class Manifest{
    ServoMotorImpl* servo;
    Led* led1;
    Led* led2;
    Led* led3;
    Led* led4;

    GardenStatus gardenStatus;
    IrrigatorStatus irrigatorStatus;
    LedStatus led1Status;
    LedStatus led2Status;
    LedStatus led3Status;
    LedStatus led4Status;
    int led3Intensity;
    int led4Intensity;
    int irrigatorIntensity;
    int pausePeriod;
    int actionPeriod;

    public:
        Manifest();
        ServoMotorImpl* getServoMotor();
        Led* getLed1();
        Led* getLed2();
        Led* getLed3();
        Led* getLed4();
        void setLedStatus(int led, LedStatus status);
        void setIrrigatorStatus(IrrigatorStatus status);
        void setGardenStatus(GardenStatus status);
        void setIrrigatorIntensity(int intensity);
        void setLedIntensity(int led, int intensity);
        void setPausePeriod(int x);
        void setActionPeriod(int y);

        LedStatus getLedStatus(int led);
        IrrigatorStatus getIrrigatorStatus();
        GardenStatus getGardenStatus();
        int getIrrigatorIntensity();
        int getLedIntensity(int led);
        int getActionPeriod();
        int getPausePeriod();
        String getMessageStatus();
};

#endif