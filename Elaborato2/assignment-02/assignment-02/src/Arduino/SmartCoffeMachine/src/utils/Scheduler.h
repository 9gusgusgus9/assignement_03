#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Timer.h"
#include "../tasks/Task.h"

#define MAX_TASK 10

class Scheduler {

    int basePeriod;
    bool fixPeriod;
    int nTask;
    Task* tasks[MAX_TASK];
    Timer timer;

    public:

    void init();
    void init(int basePeriod);
    virtual void schedule();
    bool addTask(Task* task);
};


#endif