#ifndef __ILLUMINATION_TASK__
#define __ILLUMINATION_TASK__

#include "Task.h"
#include "../components/Led.h"

class IlluminationTask : public Task
{

public:
    IlluminationTask(int led1, int led2, int led3, int led4);

    void tick();
    void init();

private:
    Led *led1;
    Led *led2;
    Led *led3;
    Led *led4;

};

#endif 