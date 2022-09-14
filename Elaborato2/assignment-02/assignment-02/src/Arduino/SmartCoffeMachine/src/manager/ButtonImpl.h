#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

class ButtonImpl{ 
public: 
  ButtonImpl(int pin);
  bool isPressed();

private:
  int pin;
  int lastState;
};

#endif
