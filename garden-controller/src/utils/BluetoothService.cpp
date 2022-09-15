#include "Arduino.h"
#include "BluetoothService.h"

BluetoothService::BluetoothService(int rxPin, int txPin) {
  channel = new SoftwareSerial(rxPin, txPin);
}

void BluetoothService::init() {
  content.reserve(256);
  channel->begin(9600);
  availableMsg = NULL;
}

bool BluetoothService::sendMsg(Msg msg) {
  channel->println(msg.getContent());
}

bool BluetoothService::isMsgAvailable() {
  while (channel->available()) {
    /*Serial.println("Available");
    //char ch = (char)channel->read();
    char ch = '\n';
    Serial.println(channel-> read());
    if (ch == '\r') continue;
    if (ch == '\n') {
      availableMsg = new Msg(content);
      Serial.println(availableMsg -> getContent());
      content = "";
      return true;
    }
    else {
      content += ch;
    }*/
    Serial.println(channel -> read());
    return true;
  }
  return false;
}

int BluetoothService::receiveMsg() {
  Serial.println("Voglio ricevere");
  if (availableMsg != NULL) {
    int msg = availableMsg;
    availableMsg = NULL;
    return msg;
  }
  else {
    return NULL;
  }
}