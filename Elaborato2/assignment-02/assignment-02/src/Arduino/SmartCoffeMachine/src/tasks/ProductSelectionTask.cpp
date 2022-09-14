#include "ProductSelectionTask.h"
#include "../manager/ButtonImpl.h"
#include "Arduino.h"

ProductSelectionTask::ProductSelectionTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductSelectionTask::init(int period){
    Task::init(period);
    this -> actualProduct = COFFE;
    this -> sugar = 1;
    this -> isActive = true;
    this -> bUP = new ButtonImpl(BUP);
    this -> bDOWN = new ButtonImpl(BDOWN);
    this -> bMAKE = new ButtonImpl(BMAKE);
    this -> potSugar = new SugarPot(POT);
    this -> lastPress = millis();
    this -> lastUpdateStatus = millis();
}

void ProductSelectionTask::bUp(){
    switch(actualProduct){
        case COFFE:
            actualProduct = CHOCOLATE;
            break;
        case TEA:
            actualProduct = COFFE;
            break;
        case CHOCOLATE:
            actualProduct = TEA;
            break;
    }
    if(!this -> manifest -> isAvailable(actualProduct)){
        if(this -> manifest -> someProductAvailable()){
            this -> bUp();
        }
    }
}

void ProductSelectionTask::bDown(){
    switch(actualProduct){
        case COFFE:
            actualProduct = TEA;
            break;
        case TEA:
            actualProduct = CHOCOLATE;
            break;
        case CHOCOLATE:
            actualProduct = COFFE;
            break;
    }
    if(!this -> manifest -> isAvailable(actualProduct)){
        if(this -> manifest -> someProductAvailable()){
            this -> bDown();
        }
    }
}

void ProductSelectionTask::bMake(){
    this -> isActive = false;
    manifest -> setLastPouredOut(actualProduct);
    if(!this -> manifest -> isAvailable(actualProduct)){
        if(this -> manifest -> someProductAvailable()){
            this -> bDown();
        }
    }
    manifest -> setSugar(sugar);
    manifest -> setStatus(Status::MAKING_PROCESS);
}

int ProductSelectionTask::sugarPot(){
    return this -> potSugar -> getSugarValue();
}

void ProductSelectionTask::tick(){
    if(manifest -> getStatus() == Status::PRODUCT_SUGAR_SELECTION){
        this -> manifest -> detection();
        if(this -> bUP -> isPressed()){
            this -> lastPress = millis();
            this -> bUp();
        } else if(this -> bDOWN -> isPressed()){
            this -> lastPress = millis();
            this -> bDown();
        } else if(this -> bMAKE -> isPressed()){
            this -> lastPress = millis();
            this -> bMake();
        }
        int actual = sugarPot();
        if(sugar != actual){
            this -> lastPress = millis();
            sugar = actual;
        }
        if(millis() - lastPress > Tback){
            isActive = false;
            manifest -> setStatus(Status::MACHINE_READY);
        }
        if(isActive){
            this-> manifest -> getDisplay() -> printProductAndSugar(actualProduct, sugar);
        }
    } else if(manifest -> getStatus() == Status::MACHINE_READY){
        if((millis() - this -> manifest -> getLastDetection()) > TtoSleep){
            this -> manifest -> setStatus(Status::SLEEP_MODE);
        }
        if(this -> manifest -> timeToTest()){
            this -> manifest -> setStatus(Status::CHECK_TEST);
        } else {
            if(this -> bUP -> isPressed() || this -> bDOWN -> isPressed() || this -> bMAKE -> isPressed()){
                manifest -> setStatus(Status::PRODUCT_SUGAR_SELECTION);
                isActive = true;
                this -> lastPress = millis();
            } else {
                this-> manifest -> getDisplay() -> printReadyMessage();
            }
        }
        
    }
}