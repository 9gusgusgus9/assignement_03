#include "IlluminationTask.h"

IlluminationTask::IlluminationTask(Manifest * manifest) {
    this->manifest = manifest;
    this -> led1 = manifest -> getLed1();
    this -> led2 = manifest -> getLed2();
    this -> led3 = manifest -> getLed3();
    this -> led4 = manifest -> getLed4();
}

void IlluminationTask::init(int period) {
    Task::init(period);
    led1->on();
    led2->on();
    led3->on();
    led4->on();
}