#include "BluetoothService.h"
#include "Arduino.h"

int bluetoothVal = -1;

BluetoothService::BluetoothService(int rx, int tx){
  this->rx = rx;
  this->tx = tx;
}

void BluetoothService::init(){
  btSerial = new SoftwareSerial(rx,tx);
  btSerial->begin(100);
}

int BluetoothService::readData(){
  int val = btSerial->read();
  return val;
}

int BluetoothService::isSerialAvaiable(){
  return btSerial->available();
}

void BluetoothService::sendData(int data){
  btSerial->write(data);
}
