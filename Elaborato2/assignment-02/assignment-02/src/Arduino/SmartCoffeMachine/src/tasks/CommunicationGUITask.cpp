#include "CommunicatorGUITask.h"
#include "../utils/MsgService.h"

CommunicatorGUITask::CommunicatorGUITask(Manifest* manifest){
    this -> manifest = manifest;
}

void CommunicatorGUITask::init(int period){
    Task::init(period);
}

void CommunicatorGUITask::tick(){
    this -> reciveMsg();
    this -> sendMsg();
}

void CommunicatorGUITask::reciveMsg(){
    Msg* msg = MsgService.receiveMsg();
    this -> lastMsg = msg -> getContent();
    if(lastMsg == "REFILL"){
        this -> manifest -> refill();
        if(this -> manifest -> getStatus() == Status::ASSISTANCE_REFILL_REQUIRED){
            this -> manifest -> setStatus(Status::MACHINE_READY);
        }
    } else if(lastMsg == "RECOVER"){
        if(this -> manifest -> getStatus() == Status::ASSISTANCE_MODE){
            this -> manifest -> setStatus(Status::MACHINE_READY);
        }
    }
}

void CommunicatorGUITask::sendMsg(){
    MsgService.sendMsg(this -> manifest -> msgToSend());
}