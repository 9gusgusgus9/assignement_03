#include "SerialServiceTask.h"

SerialServiceTask::SerialServiceTask(Manifest* manifest){
    this->manifest = manifest;
    this->serialService = new SerialService(manifest);
}

void SerialServiceTask::init(int period){
    Task::init(period);
}

void SerialServiceTask::tick(){
    if (this -> manifest -> getGardenStatus() == AUTO){
        if (this -> serialService -> isMsgAvailable()){
            String message = this -> serialService -> getCommandFromSerial();
            for(int i = 0; i < 9; i++){
                String firstString;
                String secondString;
                if(i == 8){
                    firstString = message;
                } else {
                    
                    int index = message.indexOf(":");
                    firstString = message.substring(0, index);
                    secondString = message.substring(index+1, message.length());
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
                message = secondString;
            }
        }
        this -> serialService -> sendDataOnSerial(this -> manifest -> getMessageStatus());
    }
}