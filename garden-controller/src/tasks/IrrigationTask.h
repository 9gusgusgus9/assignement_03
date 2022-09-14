#ifndef __IRRIGATION_TASK__
#define __IRRIGATION_TASK__

#include "Task.h"
#include "../components/ServoMotorImpl.h"
class IrrigationTask : public Task {

    public:
        IrrigationTask(int servo);

        void tick();
        void init();

    private:
        ServoMotorImpl* servo;
};

#endif