#ifndef __BLUETOOTH_TASK__
#define __BLUETOOTH_TASK__

#include "Task.h"
#include "../utils/BluetoothService.h"
#include "../utils/manifest/Manifest.h"

class BluetoothTask : public Task
{
private:
    BluetoothService* bluetooth;
    int message;
    Manifest * manifest;
    bool isMessagePresent();
    
public:
    BluetoothTask(Manifest* manifest);
    void init(int period);
    void tick();
    void computeRead();
};

#endif