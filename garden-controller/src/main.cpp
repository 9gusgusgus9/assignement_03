#include <Arduino.h>
#include "SoftwareSerial.h"
#include "utils/manifest/Manifest.h"
#include "utils/Scheduler.h"
#include "tasks/Task.h"
#include "tasks/IrrigationTask.h"
#include "tasks/IlluminationTask.h"
#include "utils/manifest/Manifest.h"
#include "utils/BluetoothService.h"
#include "tasks/SerialServiceTask.h"
#include "tasks/BluetoothTask.h"

Scheduler *scheduler;
Task *irrigationTask;
Task *illuminationTask;
Manifest *manifest;
SerialServiceTask *serialServiceTask;
BluetoothTask *bluetoothTask;

void setup() {
    Serial.begin(9600);
    manifest = new Manifest();
    scheduler = new Scheduler();
    irrigationTask = new IrrigationTask(manifest);
    illuminationTask = new IlluminationTask(manifest);
    serialServiceTask = new SerialServiceTask(manifest);
    bluetoothTask = new BluetoothTask(manifest);

    irrigationTask->init(100);
    illuminationTask->init(100);
    serialServiceTask->init(100);
    bluetoothTask->init(100);
    scheduler->init();

    scheduler->addTask(irrigationTask);
    scheduler->addTask(illuminationTask);
    scheduler->addTask(serialServiceTask);
    scheduler->addTask(bluetoothTask);
  // put your setup code here, to run once:
}

void loop() {
  scheduler->schedule();
  // put your main code here, to run repeatedly:
}