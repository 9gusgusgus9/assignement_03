#include "WelcomeMessageTask.h"
#include "Arduino.h"

WelcomeMessageTask::WelcomeMessageTask(Manifest* manifest){
    this -> manifest = manifest;
}

void WelcomeMessageTask::init(int period){
    Task::init(period);
    this -> startTime = millis();
}

void WelcomeMessageTask::tick(){
    if(manifest -> getStatus() == Status::INIT){
        if(millis() - startTime < Tinit){
            manifest -> getDisplay() -> printWelcomeMessage();
        } else {
            manifest -> setStatus(Status::MACHINE_READY);
        }
    }
}