#ifndef __WELCOME__
#define __WELCOME__

#include "Task.h"
#include "../utils/Manifest.h"

class WelcomeMessageTask: public Task{
    
public:
    WelcomeMessageTask(Manifest* manifest);

    void init(int period);
    void tick();
private:
    Manifest* manifest;
    int startTime;

};

#endif