#ifndef __BLUETOOTH_TASK__
#define __BLUETOOTH_TASK__

#include "Task.h"
#include "../utils/BluetoothService.h"
#include "../utils/manifest/Manifest.h"

class BluetoothTask : public Task
{
private:
    BluetoothService* bluetooth;
    String message;
    Manifest * manifest;
    bool isMessagePresent();
    
public:
    BluetoothTask(Manifest* manifest);
    void init();
    void tick();
    void computeRead();
};

#endif