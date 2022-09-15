#include "BluetoothTask.h"

BluetoothTask::BluetoothTask(Manifest * manifest){
    this -> manifest = manifest;
    this -> bluetooth = new BluetoothService(PIN_RX, PIN_TX);
}

void BluetoothTask::init(int period){
    Task::init(period);
    this -> bluetooth -> init();
}

void BluetoothTask::computeRead(){
    if(this->bluetooth->isMsgAvailable()){
        Serial.println("Compute read");
        this-> message = this->bluetooth->receiveMsg();
    } else {
        this->message=-1;
    }
}

void BluetoothTask::tick(){
    this->computeRead();
    int msg = message;
    switch (this -> manifest ->getGardenStatus()) {
        case AUTO:
            if(msg==10){
                this->manifest->setGardenStatus(MANUAL);
            }
        case MANUAL:
            switch (msg)
            {
            case 0:
            case 1:
                if(manifest -> getLedStatus(1+msg)==ON){
                    manifest -> setLedStatus(1+msg, OFF);
                } else {
                    manifest -> setLedStatus(1+msg, ON);
                }
                break;
            case 2:
                manifest -> setLedIntensity(3, (manifest -> getLedIntensity(3)+1));
                break;
            case 3:
                manifest -> setLedIntensity(3, (manifest -> getLedIntensity(3)-1));
                break;
            case 4:
                manifest -> setLedIntensity(4, (manifest -> getLedIntensity(4)+1));
                break;
            case 5:
                manifest -> setLedIntensity(4, (manifest -> getLedIntensity(4)-1));
                break;
            case 6:
                if(manifest -> getIrrigatorStatus()==OPEN || manifest -> getIrrigatorStatus()==READY){
                    manifest -> setIrrigatorStatus(CLOSE);
                } else {
                    manifest -> setIrrigatorStatus(OPEN);
                }
                break;
            case 7:
                manifest -> setIrrigatorIntensity((manifest -> getIrrigatorIntensity()+1));
                break;
            case 8:
                manifest -> setIrrigatorIntensity((manifest -> getIrrigatorIntensity()-1));
                break;
            case 9:
                if(manifest -> getGardenStatus() == ALARM){
                    manifest -> setGardenStatus(MANUAL);
                }
            default:
                break;
            }
    }
}

bool BluetoothTask::isMessagePresent(){
    return this->message!=-1;
}