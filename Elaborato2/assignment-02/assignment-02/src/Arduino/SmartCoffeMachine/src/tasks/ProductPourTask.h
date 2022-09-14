#ifndef __MAKING_PRODUCT__
#define __MAKING_PRODUCT__

#define STATUS_MAX 20

#include "Task.h"
#include "../utils/Manifest.h"

class ProductPourTask: public Task{

public:
    ProductPourTask(Manifest* manifest);
    void init(int period);
    void tick();

private:
    Manifest* manifest;
    int status;
    unsigned long lastUpdateStatus;
};

#endif