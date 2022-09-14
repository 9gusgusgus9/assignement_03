#include <Arduino.h>
#include "SoftwareSerial.h"
#include "utils/ConnectivityManager.h"
#include "utils/manifest/Manifest.h"
#include "utils/Scheduler.h"
#include "tasks/Task.h"
#include "tasks/IrrigationTask.h"
#include "tasks/IlluminationTask.h"
#include "utils/manifest/Manifest.h"
#include "utils/BluetoothService.h"

Scheduler *scheduler;
Task *irrigationTask;
Task *illuminationTask;
Manifest *manifest;
BluetoothService *bluetoothService;



void setup() {
    Serial.begin(9600);
    manifest = new Manifest();
    scheduler = new Scheduler();
    irrigationTask = new IrrigationTask(manifest);
    illuminationTask = new IlluminationTask(manifest);

    bluetoothService->init();
    irrigationTask->init(100);
    illuminationTask->init(100);
    scheduler->init();

    scheduler->addTask(irrigationTask);
    scheduler->addTask(illuminationTask);
  // put your setup code here, to run once:
}

void loop() {
  scheduler->schedule();

  switch (manifest -> getGardenStatus)
  {
  case AUTO:

    break;
  case MANUAL:
    
    break;
  
  case ALARM:
    break;
  default:
    break;
  }
  if(manifest->getGardenStatus() == AUTO){

  }

  // put your main code here, to run repeatedly:
}