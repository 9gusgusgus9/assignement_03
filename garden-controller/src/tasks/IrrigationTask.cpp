#include "IrrigationTask.h"

IrrigationTask::IrrigationTask(Manifest *manifest) {
    this -> manifest = manifest;
    this -> servo = manifest -> getServoMotor();
}

void IrrigationTask::init(int period) {
    Task::init(period);
    this -> lastTime = 0;
}

void IrrigationTask::tick() {
    if(this -> manifest -> getIrrigatorStatus() == OPEN){
        if(this -> manifest -> getActionPeriod() - this -> lastTime > 0){
            if(this -> lastStatus == CLOSE) {
                this -> lastStatus = OPEN;
                this -> lastTime = millis();
            }
            this -> servo -> moveOf(this -> manifest -> getIrrigatorIntensity());
        } else {
            this -> manifest -> setIrrigatorStatus(READY);
            this -> lastTime = millis();
            this -> lastStatus = READY;
        }
    } else if (this -> manifest -> getIrrigatorStatus() == READY){
        if (this -> manifest -> getPausePeriod() - this -> lastTime <= 0){
            this -> manifest -> setIrrigatorStatus(OPEN);
            this -> lastTime = millis();
            this -> lastStatus = OPEN;
        }
    }
}