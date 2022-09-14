#include "BluetoothTask.h"

BluetoothTask::BluetoothTask(Manifest * manifest){
    this -> manifest = manifest;
}

void BluetoothTask::init(int period){
    Task::init(period);
    this -> bluetooth -> init();
}

void BluetoothTask::computeRead(){
    if(this->bluetooth->isMsgAvailable()){
        Msg* msg = this->bluetooth->receiveMsg();
        this->message = msg->getContent();
        delete msg;
    } else {
        this->message="";
    }
}

void BluetoothTask::tick(){
    String msg = message;
    switch (this -> manifest ->getGardenStatus()) {
        case AUTO:
            break;
        case MANUAL:
            for(int i = 0; i < 9; i++){
                String firstString;
                String secondString;
                if(i == 8){
                    firstString = msg;
                } else {
                    int index = msg.indexOf(":");
                    firstString = msg.substring(0, index-1);
                    secondString = msg.substring(index+1, msg.length());
                }
                switch(i){
                    case 0:
                        if(firstString == "AUTO"){
                            this -> manifest -> setGardenStatus(AUTO);
                        } else if (firstString == "MANUAL"){
                            this -> manifest -> setGardenStatus(MANUAL);
                        } else if (firstString == "ALARM"){
                            this -> manifest -> setGardenStatus(ALARM);
                        }
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        if(firstString == "ON"){
                            this -> manifest -> setLedStatus(i, ON);
                        } else if (firstString == "OFF"){
                            this -> manifest -> setLedStatus(i, OFF);
                        }
                        break;
                    case 5:
                    case 6:
                        this -> manifest -> setLedIntensity(i-2, secondString.toInt());
                        break;
                    case 7:
                        if(firstString == "OPEN"){
                            this -> manifest -> setIrrigatorStatus(OPEN);
                        } else if (firstString == "CLOSE"){
                            this -> manifest -> setIrrigatorStatus(CLOSE);
                        } else if (firstString == "READY"){
                            this -> manifest -> setIrrigatorStatus(READY);
                        }
                        break;
                    case 8:
                        this -> manifest -> setIrrigatorIntensity(firstString.toInt());
                        break;
                }
                msg = secondString;
            }
            break;
        case ALARM:
            Msg* text = new Msg("ALARM:ON:OFF:ON:OFF:1:1:CLOSE:1");
            this->bluetooth->sendMsg(*text);
            delete text;
            break;
        default:
            break;
    }
}

bool BluetoothTask::isMessagePresent(){
    return this->message.length() > 0;
}