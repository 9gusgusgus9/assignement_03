#include "BluetoothTask.h"

BluetoothTask::BluetoothTask(Manifest * manifest){
    this -> manifest = manifest;
}

void BluetoothTask::init(){
    this->bluetooth->init();
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
    switch (this -> manifest ->getGardenStatus())
    {
    case AUTO:
        break;
    case MANUAL:
    
        break;
    case ALARM:
        Msg* msg = new Msg("ALARM:ON:ON:ON:ON:1:1:OPEN:1");
        this->bluetooth->sendMsg(*msg);
        delete msg;
        break;
    default:
        break;
    }
}

bool BluetoothTask::isMessagePresent(){
    return this->message.length() > 0;
}