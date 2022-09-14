#include "ConnectivityManager.h"

ConnectivityManager::ConnectivityManager(){
  this->btService = new BluetoothService(0,1);
}

BluetoothService* ConnectivityManager::getBluetoothService(){
  return this->btService;
}