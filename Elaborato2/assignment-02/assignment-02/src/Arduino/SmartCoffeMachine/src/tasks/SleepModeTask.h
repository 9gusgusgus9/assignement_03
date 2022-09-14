#ifndef __SLEEP__
#define __SLEEP__

#include "Task.h"
#include "../utils/Manifest.h"

class SleepModeTask: public Task{
private:
    Manifest* manifest;

public:
    SleepModeTask(Manifest* manifest);
    void init(int period);
    void tick();
};

#endif