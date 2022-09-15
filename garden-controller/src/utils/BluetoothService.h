#ifndef __MSGSERVICEBT__
#define __MSGSERVICEBT__

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "MsgService.h"

class BluetoothService {

public:
  BluetoothService() {}
  BluetoothService(int rxPin, int txPin);
  void init();
  bool isMsgAvailable();
  int receiveMsg();
  bool sendMsg(Msg msg);

private:
  String content;
  int availableMsg;
  SoftwareSerial* channel;

};

#endif
