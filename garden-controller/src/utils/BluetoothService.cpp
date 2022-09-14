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
    char ch = (char)channel->read();
    if (ch == '\r') continue;
    if (ch == '\n') {
      availableMsg = new Msg(content);
      content = "";
      return true;
    }
    else {
      content += ch;
    }
  }
  return false;
}

Msg* BluetoothService::receiveMsg() {
  if (availableMsg != NULL) {
    Msg* msg = availableMsg;
    availableMsg = NULL;
    return msg;
  }
  else {
    return NULL;
  }
}