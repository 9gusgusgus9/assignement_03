#include "IlluminationTask.h"

IlluminationTask::IlluminationTask(Manifest * manifest) {
    this -> manifest = manifest;
    this -> led1 = manifest -> getLed1();
    this -> led2 = manifest -> getLed2();
    this -> led3 = manifest -> getLed3();
    this -> led4 = manifest -> getLed4();
}

void IlluminationTask::init(int period) {
    Task::init(period);
}

void IlluminationTask::tick() {
    led1->set(this -> manifest -> getLedStatus(1));
    led2->set(this -> manifest -> getLedStatus(2));
    led3->set(this -> manifest -> getLedStatus(3));
    led4->set(this -> manifest -> getLedStatus(4));
    led3->setIntensity(this -> manifest -> getLedIntensity(3));
    led4->setIntensity(this -> manifest -> getLedIntensity(4));
}