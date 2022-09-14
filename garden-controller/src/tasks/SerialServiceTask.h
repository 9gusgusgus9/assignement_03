#ifndef __SERIALSERVICETASK__
#define __SERIALSERVICETASK__

#include "Task.h"
#include "../utils/manifest/Manifest.h"
#include "../utils/SerialService.h"

class SerialServiceTask : public Task{

public:
    SerialServiceTask(Manifest* manifest);
    void init(int period);
    void tick();
private:
    Manifest* manifest;
    SerialService* serialService;
};

#endif