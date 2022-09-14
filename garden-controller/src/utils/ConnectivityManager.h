#ifndef __CONNECTIVITYMANAGER__
#define __CONNECTIVITYMANAGER__

#include "BluetoothService.h"
#include "MsgService.h"

class ConnectivityManager{
  private:
    BluetoothService* btService;
    MsgService* msgService;

  public:
    ConnectivityManager();
    BluetoothService* getBluetoothService();
    MsgService* getMsgService();
    
};


#endif