#include <SoftwareSerial.h>

#ifndef __BLUETOOTHSERVICE__
#define __BLUETOOTHSERVICE__

extern int bluetoothVal;

class BluetoothService{
  private:
    int rx;
    int tx;
    SoftwareSerial* btSerial;

  public:
    BluetoothService(int rx, int tx);
    void init();
    int isSerialAvaiable();
    int readData();
    void sendData(int data);
};

#endif
