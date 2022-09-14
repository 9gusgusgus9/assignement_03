#include "ConnectivityManager.h"

ConnectivityManager::ConnectivityManager(){
  this->btService = new BluetoothService(0,1);
  this->serialService = new SerialService();
}

BluetoothService* ConnectivityManager::getBluetoothService(){
  return this->btService;
}

SerialService* ConnectivityManager::getSerialService(){
  return this->serialService;
}