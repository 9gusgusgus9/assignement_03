#include <Arduino.h>
#include "SoftwareSerial.h"
#include "utils/ConnectivityManager.h"
#include "utils/manifest/Manifest.h"
#include "utils/Scheduler.h"
#include "tasks/Task.h"
#include "tasks/IrrigationTask.h"
#include "tasks/IlluminationTask.h"

Scheduler *scheduler;
Task *irrigationTask;
Task *illuminationTask;

void setup() {
    Serial.begin(9600);
    scheduler = new Scheduler();
    irrigationTask = new IrrigationTask(PIN_SERVO);
    illuminationTask = new IlluminationTask(PIN_LED1, PIN_LED2, PIN_LED3, PIN_LED4);

    irrigationTask->init(100);
    illuminationTask->init(100);
    scheduler->init();

    scheduler->addTask(irrigationTask);
    scheduler->addTask(illuminationTask);
  // put your setup code here, to run once:
}

void loop() {
  scheduler->schedule();
  // put your main code here, to run repeatedly:
}