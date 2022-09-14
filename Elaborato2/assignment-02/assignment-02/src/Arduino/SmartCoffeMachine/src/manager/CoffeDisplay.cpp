#include "CoffeDisplay.h"
#include "Arduino.h"
#include "../utils/Manifest.h"

byte fullPin[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
};

byte squarePin[8] = {
    B11111,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B11111,
};

CoffeDisplay::CoffeDisplay(){
    display = new LiquidCrystal_I2C(0x27, 20, 4);
    display -> init();
    display -> backlight();
    display -> createChar(0, fullPin);
    display -> createChar(1, squarePin);
    lastPrint = NONE;
}

void CoffeDisplay::printMessageGiustify(String first, String second, String third, String fourth){
    display -> clear();
    display -> setCursor(0,0);
    display -> print(first);
    display -> setCursor(10,1);
    display -> print(second);
    display -> setCursor(0,2);
    display -> print(third);
    display -> setCursor(0,3);
    display -> print(fourth);
}

void CoffeDisplay::printMessageCentered(String first, String second, String third, String fourth){
    display -> clear();
    int cursor = 20;
    cursor -= first.length();
    cursor /= 2;
    display -> setCursor(cursor ,0);
    display -> print(first);
    cursor = 20;
    cursor -= second.length();
    cursor /= 2;
    display -> setCursor(cursor ,1);
    display -> print(second);
    cursor = 20;
    cursor -= third.length();
    cursor /= 2;
    display -> setCursor(cursor ,2);
    display -> print(third);
    cursor = 20;
    cursor -= fourth.length();
    cursor /= 2;
    display -> setCursor(cursor ,3);
    display -> print(fourth);
}

void CoffeDisplay::printWelcomeMessage(){
    if(lastPrint != LastPrint::WELCOME){
        printMessageCentered("", "Camera Caffe", "Welcome", "");
        lastPrint = LastPrint::WELCOME;
    }
    
}

void CoffeDisplay::printReadyMessage(){
    if(lastPrint != LastPrint::READY){
        printMessageCentered("", "Machine ready", "press one button", "");
        lastPrint = LastPrint::READY;
    }
}

void CoffeDisplay::printAssistanceMessage(){
    if(lastPrint != LastPrint::ASSISTANCE){
        printMessageCentered("", "Assistance required", "recover with GUI", "");
        lastPrint = LastPrint::ASSISTANCE;
    }
}

void CoffeDisplay::printAssistanceRefillMessage(){
    if(lastPrint != LastPrint::ASSISTANCE){
        printMessageCentered("", "Assistance required", "refill the machine...", "");
        lastPrint = LastPrint::ASSISTANCE;
    }
}

void CoffeDisplay::printProductReady(Product product){
    if(lastPrint != LastPrint::P_READY){
        String prod = toString(product);
        printMessageCentered("", "Product ready", "take your " + prod, "Thanks!");
        lastPrint = LastPrint::P_READY;
    }
}
void CoffeDisplay::printTestMessage(int status){
    if(lastPrint != LastPrint::TEST){
        printMessageCentered("", "Test in progress", "please wait", "");
        lastPrint = LastPrint::TEST;
    }
    display -> setCursor(status + 5, 3);
    display -> write(0);
}

void CoffeDisplay::printProductAndSugar(Product product, int sugar){
    if((lastPrint != LastPrint::SELECT_COFFE && product == Product::COFFE)
        || (lastPrint != LastPrint::SELECT_TEA && product == Product::TEA)
        || (lastPrint != LastPrint::SELECT_CHOCOLATE && product == Product::CHOCOLATE)){
            String prod = toString(product);
            printMessageGiustify("Product:", prod, "Sugar:", "");
            switch(product){
                case Product::COFFE:
                    lastPrint = LastPrint::SELECT_COFFE;
                    break;
                case Product::CHOCOLATE:
                    lastPrint = LastPrint::SELECT_CHOCOLATE;
                    break;
                case Product::TEA:
                    lastPrint = LastPrint::SELECT_TEA;
                    break;
            }
    }
    int cursor;
    for(cursor = 10; cursor < sugar + 10; cursor++){
        display -> setCursor(cursor, 3);
        display -> write(0);
    }
    for(; cursor < 15; cursor++){
        display -> setCursor(cursor, 3);
        display -> write(1);
    }
}

void CoffeDisplay::printMakingProcess(Product product, int status){
    String prod = toString(product);
    if(status == 0){
        printMessageCentered("", "Preparing " + prod, "", "");
    }
    display -> setCursor(status + 5, 2);
    display -> write(0);
}

void CoffeDisplay::sleepDisplay(){
    this -> display -> clear();
    this -> display -> noBacklight();
    this -> lastPrint = LastPrint::SLEEP;
}

void CoffeDisplay::wakeUpDisplay(){
    this -> display -> backlight();
}