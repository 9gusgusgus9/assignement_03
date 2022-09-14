#ifndef __CONNECTIVITYMANAGER__
#define __CONNECTIVITYMANAGER__

#include "BluetoothService.h"

class ConnectivityManager{
  private:
    BluetoothService* btService;


  public:
    ConnectivityManager();
    BluetoothService* getBluetoothService();

};


#endif