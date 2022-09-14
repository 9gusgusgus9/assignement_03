#ifndef __COFFE_DISPLAY__
#define __COFFE_DISPLAY__
#include <LiquidCrystal_I2C.h>
#include "../utils/Product.h"

enum LastPrint{
    NONE,
    WELCOME,
    READY,
    ASSISTANCE,
    P_READY,
    TEST,
    SELECT_COFFE,
    SELECT_TEA,
    SELECT_CHOCOLATE,
    SLEEP,
    MAKING
};

class CoffeDisplay{
    LiquidCrystal_I2C* display;
    LastPrint lastPrint;

public:

    CoffeDisplay();
    void printMessageGiustify(String first, String second, String third, String fourth);
    void printMessageCentered(String first, String second, String third, String fourth);
    void printWelcomeMessage();
    void printReadyMessage();
    void printAssistanceMessage();
    void printAssistanceRefillMessage();
    void printProductReady(Product product);
    void printTestMessage(int status);
    void printProductAndSugar(Product product, int sugar);
    void printMakingProcess(Product product, int status);
    void sleepDisplay();
    void wakeUpDisplay();
};

#endif