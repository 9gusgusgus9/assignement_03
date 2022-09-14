#include <Arduino.h>
#include "SoftwareSerial.h"
#include "BluetoothService.h"
#include "ConnectivityManager.h"

BluetoothService *btService;
int x;
String string = "AUTO:ON:ON:ON:ON:1:1:OPEN:1";

void setup() {
  // put your setup code here, to run once:
  ConnectivityManager* connManager = new ConnectivityManager();
  btService = connManager->getBluetoothService();

  btService->init();
  x = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  if(x==0){
    btService -> sendData(string.toInt());
    x++;
  }
}