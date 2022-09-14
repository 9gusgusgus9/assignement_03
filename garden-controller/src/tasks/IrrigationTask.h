#ifndef __IRRIGATION_TASK__
#define __IRRIGATION_TASK__

#include "Task.h"
#include "../components/ServoMotorImpl.h"
#include "../utils/manifest/Manifest.h"

class IrrigationTask : public Task {

    public:
        IrrigationTask(Manifest *manifest);

        void tick();
        void init(int period);

    private:
        Manifest *manifest;
        ServoMotorImpl *servo;
};

#endif