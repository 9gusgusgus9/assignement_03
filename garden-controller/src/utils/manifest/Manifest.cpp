#include "Manifest.h"
#include "Config.h"
#include "../../components/ServoMotorImpl.h"
#include "../../components/Led.h"

Manifest::Manifest(){
    servo = new ServoMotorImpl(PIN_SERVO);
    led1 = new Led(PIN_LED1);
    led2 = new Led(PIN_LED2);
    led3 = new Led(PIN_LED3);
    led4 = new Led(PIN_LED4);
    gardenStatus = AUTO;
    irrigatorStatus = CLOSE;
    led1Status = OFF;
    led2Status = OFF;
    led3Status = OFF;
    led4Status = OFF;
    led3Intensity = 1;
    led4Intensity = 1;
    irrigatorIntensity = 1;
    pausePeriod = 5000;
    actionPeriod = 1000;
}

ServoMotorImpl* Manifest::getServoMotor(){
    return servo;
}

Led* Manifest::getLed1(){
    return led1;
}

Led* Manifest::getLed2(){
    return led2;
}

Led* Manifest::getLed3(){
    return led3;
}

Led* Manifest::getLed4(){
    return led4;
}

void Manifest::setLedStatus(int led, LedStatus status){
    switch(led){
        case 1:
            led1Status = status;
            break;
        case 2:
            led2Status = status;
            break;
        case 3:
            led3Status = status;
            break;
        case 4:
            led4Status = status;
            break;
    }
}

void Manifest::setIrrigatorStatus(IrrigatorStatus status){
    irrigatorStatus = status;
}

void Manifest::setGardenStatus(GardenStatus status){
    gardenStatus = status;
}

void Manifest::setIrrigatorIntensity(int intensity){
    irrigatorIntensity = intensity;
}

void Manifest::setLedIntensity(int led, int intensity){
    switch(led){
        case 3:
            led3Intensity = intensity;
            break;
        case 4:
            led4Intensity = intensity;
            break;
    }
}

void Manifest::setPausePeriod(int x){
    pausePeriod = x;
}


void Manifest::setActionPeriod(int y){
    actionPeriod = y;
}

LedStatus Manifest::getLedStatus(int led){
    switch(led){
        case 1:
            return led1Status;
        case 2:
            return led2Status;
        case 3:
            return led3Status;
        case 4:
            return led4Status;
    }
}

IrrigatorStatus Manifest::getIrrigatorStatus(){
    return irrigatorStatus;
}

GardenStatus Manifest::getGardenStatus(){
    return gardenStatus;
}

int Manifest::getIrrigatorIntensity(){
    return irrigatorIntensity;
}

int Manifest::getLedIntensity(int led){
    switch(led){
        case 3:
            return led3Intensity;
        case 4:
            return led4Intensity;
    }
}

int Manifest::getPausePeriod(){
    return pausePeriod;
}

int Manifest::getActionPeriod(){
    return actionPeriod;
}

String Manifest::getMessageStatus(){
    String statusGarden = "";
    String statusIrrigator = "";
    String statusLed1 = "";
    String statusLed2 = "";
    String statusLed3 = "";
    String statusLed4 = "";
    switch (gardenStatus){
        case MANUAL:
            statusGarden = "MANUAL";
            break;
        case AUTO:
            statusGarden = "AUTO";
            break;
        case ALARM:
            statusGarden = "ALARM";
            break;
    }
    switch (irrigatorStatus){
        case OPEN:
            statusIrrigator = "OPEN";
            break;
        case CLOSE:
            statusIrrigator = "CLOSE";
            break;
        case READY:
            statusIrrigator = "READY";
            break;
    }
    switch (led1Status){
        case ON:
            statusLed1 = "ON";
            break;
        case OFF:
            statusLed1 = "OFF";
            break;
    }
    switch (led2Status){
        case ON:
            statusLed2 = "ON";
            break;
        case OFF:
            statusLed2 = "OFF";
            break;
    }
    switch (led3Status){
        case ON:
            statusLed3 = "ON";
            break;
        case OFF:
            statusLed3 = "OFF";
            break;
    }
    switch (led4Status){
        case ON:
            statusLed4 = "ON";
            break;
        case OFF:
            statusLed4 = "OFF";
            break;
    }
    return statusGarden + ":" + statusLed1 + ":" + statusLed2 + ":" + statusLed3 + ":" + statusLed4 + ":" + led3Intensity + ":" + led4Intensity + ":" + statusIrrigator + ":" + irrigatorIntensity;    
}


