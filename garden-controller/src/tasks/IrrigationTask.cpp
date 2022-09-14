#include "IrrigationTask.h"

IrrigationTask::IrrigationTask(Manifest *manifest) {
    this->manifest = manifest;
    this -> servo = manifest -> getServoMotor();
}

void IrrigationTask::init(int period) {
    Task::init(period);
    servo->on();
    servo->setPosition(0);
}

void IrrigationTask::tick() {
    
}