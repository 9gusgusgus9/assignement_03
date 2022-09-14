#include "IrrigationTask.h"

IrrigationTask::IrrigationTask(int servo) {
    this->servo = new ServoMotorImpl(servo);
}



