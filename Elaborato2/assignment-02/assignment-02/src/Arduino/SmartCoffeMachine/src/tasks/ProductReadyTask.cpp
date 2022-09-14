#include "ProductReadyTask.h"
#include "Arduino.h"

ProductReadyTask::ProductReadyTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductReadyTask::init(int period){
    Task::init(period);
    this -> isTheFirstRound = true;
}

void ProductReadyTask::tick(){
    if(this -> manifest -> getStatus() == Status::PRODUCT_READY){
        this -> manifest -> getDisplay() -> printProductReady(this -> manifest -> getLastPouredOut());
        if(isTheFirstRound){
            isTheFirstRound = false;
            timeFromReady = millis();
        }
        if(this -> manifest -> getSensor() -> getDistance() >= 0.40 || millis() - timeFromReady > TtoTake){
            isTheFirstRound = true;
            this -> manifest -> getServo() -> on();
            this -> manifest -> getServo() -> setPosition(0);
            if(this -> manifest -> someProductAvailable()){
                this -> manifest -> setStatus(Status::MACHINE_READY);
            } else {
                this -> manifest -> setStatus(Status::ASSISTANCE_REFILL_REQUIRED);
            }
            
        }
    }
}