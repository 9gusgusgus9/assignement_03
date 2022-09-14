#ifndef __PRODUCT_SELECTION__
#define __PRODUCT_SELECTION__

#define MAX_STATUS 10

#include "Task.h"
#include "../manager/CoffeDisplay.h"
#include "../utils/Manifest.h"
#include "../manager/ButtonImpl.h"
#include "../manager/SugarPot.h"

class ProductSelectionTask: public Task{
    
    
public:
    ProductSelectionTask(Manifest* manifest);
    void init(int period);
    void tick();
    void bUp();
    void bDown();
    void bMake();
    int sugarPot();
    
private:
    Manifest* manifest;
    Product actualProduct;
    int sugar;
    bool isActive;
    ButtonImpl* bUP, *bDOWN, *bMAKE;
    SugarPot* potSugar;
    unsigned long lastPress;
    int status;
    unsigned long lastUpdateStatus;
};

#endif