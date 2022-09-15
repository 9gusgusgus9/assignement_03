#ifndef __ILLUMINATION_TASK__
#define __ILLUMINATION_TASK__

#include "Task.h"
#include "../components/Led.h"
#include "../utils/manifest/Manifest.h"

class IlluminationTask : public Task
{

public:
    IlluminationTask(Manifest* manifest);
    void tick();
    void init(int period);

private:
    Led *led1;
    Led *led2;
    Led *led3;
    Led *led4;
    Manifest* manifest;

};

#endif 