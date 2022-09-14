#ifndef __SELF_TEST__
#define __SELF_TEST__
#include "Task.h"
#include "../utils/Manifest.h"

#define ANGLE_MAX 180
#define ANGLE_MIN 0

class SelfTestTask: public Task{
public:
    SelfTestTask(Manifest* manifest);
    void init(int period);
    void tick();
    bool selfTest();

private:
    Manifest* manifest;
    bool isTimeToTest;
    unsigned long lastTest;
    int increment;
    int angleTest;
    bool motorCompletedTest;
    bool testPassed;
    int status;
};

#endif