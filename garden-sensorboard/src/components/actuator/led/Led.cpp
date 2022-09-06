#include "./Led.h"

Led::Led(uint8_t pin) {
    this->pin = pin;
}

void Led::setup() {
    pinMode(this->pin, OUTPUT);
}

void Led::setState(bool state) {
    digitalWrite(this->pin, state);
}

bool Led::getState() {
    return digitalRead(this->pin);
}