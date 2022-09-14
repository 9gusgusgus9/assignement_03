#include <Arduino.h>
#include "manager/CoffeDisplay.h"
#include "tasks/ProductReadyTask.h"
#include "tasks/ProductSelectionTask.h"
#include "utils/Scheduler.h"
#include "tasks/ProductPourTask.h"
#include "manager/ServoMotorImpl.h"
#include "tasks/WelcomeMessageTask.h"
#include "tasks/AssistanceModeTask.h"
#include "tasks/SelfTestTask.h"
#include "tasks/SleepModeTask.h"
#include "tasks/CommunicatorGUITask.h"

Manifest* manifest;
ProductReadyTask* prTask;
ProductSelectionTask* psTask;
ProductPourTask* pourTask;
Scheduler* scheduler;
ServoMotorImpl* servo;
WelcomeMessageTask* welcomeTask;
AssistanceModeTask* assTask;
SelfTestTask* testTask;
SleepModeTask* sleepTask;
CommunicatorGUITask* commTask;


void setup() {
  Serial.begin(9600);
  manifest = new Manifest();
  psTask = new ProductSelectionTask(manifest);
  prTask = new ProductReadyTask(manifest);
  pourTask = new ProductPourTask(manifest);
  welcomeTask = new WelcomeMessageTask(manifest);
  assTask = new AssistanceModeTask(manifest);
  testTask = new SelfTestTask(manifest);
  sleepTask = new SleepModeTask(manifest);
  commTask = new CommunicatorGUITask(manifest);
  scheduler = new Scheduler();
  welcomeTask -> init(100);
  pourTask -> init(100);
  psTask -> init(100);
  prTask -> init(100);
  assTask -> init(100);
  testTask -> init(1000);
  sleepTask -> init(500);
  commTask -> init(500);
  scheduler -> init();
  scheduler -> addTask(welcomeTask);
  scheduler -> addTask(psTask);
  scheduler -> addTask(prTask);
  scheduler -> addTask(pourTask);
  scheduler -> addTask(assTask);
  scheduler -> addTask(testTask);
  scheduler -> addTask(sleepTask);
  scheduler -> addTask(commTask);
}

void loop() {
  scheduler -> schedule();
}