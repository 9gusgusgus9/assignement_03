#ifndef __CONNECTIVITYMANAGER__
#define __CONNECTIVITYMANAGER__

#include "BluetoothService.h"
#include "SerialService.h"

class ConnectivityManager{
  private:
    BluetoothService* btService;
    SerialService* serialService;

  public:
    ConnectivityManager();
    BluetoothService* getBluetoothService();
    SerialService* getSerialService();

};


#endif