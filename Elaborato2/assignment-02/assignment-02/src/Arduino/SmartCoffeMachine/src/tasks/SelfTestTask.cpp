#include "SelfTestTask.h"
#include "Arduino.h"

SelfTestTask::SelfTestTask(Manifest* manifest){
    this -> manifest = manifest;
    this -> lastTest = millis();
    this -> increment = 1;
    this -> angleTest = 0;
    this -> motorCompletedTest = false;
    this -> testPassed = false;
    this -> status = 0;
}

void SelfTestTask::init(int period){
    Task::init(period);
}

void SelfTestTask::tick(){
    if(millis() - this -> lastTest > TtoTest){
        this -> manifest -> setTimeToTest(true);
    }
    if(this -> manifest -> getStatus() == Status::CHECK_TEST){
        this -> manifest -> getDisplay() -> printTestMessage(status);
        if(this -> selfTest()){
            this -> status = 0;
            if(this -> testPassed){
                if(manifest -> isTestBeforeSleep()){
                    this -> manifest -> setStatus(Status::SLEEP_MODE);
                } else {
                    this -> manifest -> setStatus(Status::MACHINE_READY);
                }
            } else {
                this -> manifest -> setStatus(Status::ASSISTANCE_MODE);
            }
            this -> manifest -> setTimeToTest(false);
            this -> lastTest = millis();
        }
    }
}

bool SelfTestTask::selfTest(){
    if(!this -> motorCompletedTest){
        if(this -> angleTest %40 == 0){
            status++;
        }
        angleTest += increment;
        this -> manifest -> getServo() -> setPosition(angleTest);
        if(this -> angleTest == ANGLE_MAX){
            this -> increment = -1;
        }
        if(this -> angleTest == ANGLE_MIN){
            this -> increment = 1;
            this -> motorCompletedTest = true;
        }
        return false;
    } else {
        this -> manifest -> incTest();
        this -> status++;
        this -> motorCompletedTest = false;
        double temp = this -> manifest -> getTemperature();
        if(temp > T_MIN && temp < T_MAX){
            this -> testPassed = true;
            return true;
        } else {
            return true;
        }
    }
}