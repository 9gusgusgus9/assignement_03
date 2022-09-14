#ifndef __SERIALSERVICE__
#define __SERIALSERVICE__

#include "MsgService.h"

class SerialService{
public:
    SerialService();
    bool isMsgAvailable();
    String readDataFromSerial();
    String getCommandFromSerial();
    void sendDataOnSerial(String message);
};

#endif
