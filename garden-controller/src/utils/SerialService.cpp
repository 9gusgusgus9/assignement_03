#include "Arduino.h"
#include "SerialService.h"

SerialService::SerialService(){
    MsgService.init(256);    
}

bool SerialService::isMsgAvailable(){
    return MsgService.isMsgAvailable();
}

String SerialService::readDataFromSerial(){
    return MsgService.receiveMsg() -> getContent();
}

void SerialService::sendDataOnSerial(String message){
    MsgService.sendMsg(message);
}


