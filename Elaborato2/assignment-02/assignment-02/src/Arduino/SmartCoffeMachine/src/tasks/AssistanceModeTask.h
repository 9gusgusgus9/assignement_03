#ifndef __ASSISTANCE__
#define __ASSISTANCE__

#include "Task.h"
#include "../utils/Manifest.h"

class AssistanceModeTask: public Task{
public:
    AssistanceModeTask(Manifest* manifest);
    void init(int period);
    void tick();

private:
    Manifest* manifest;

};

#endif