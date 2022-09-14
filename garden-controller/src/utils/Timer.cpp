#include "Timer.h"
#include "Arduino.h"

volatile bool timerFlag;

ISR(TIMER2_COMPA_vect){
  timerFlag = true;
}

Timer::Timer(){
  timerFlag = false;  
}

void Timer::setupFreq(int freq){
  
  // disabling interrupt
  cli();

  TCCR2A = 0; // set entire TCCR1A register to 0
  TCCR2B = 0; // same for TCCR1B
  TCNT2  = 0; //initialize counter value to 0
  
  /* 
   * set compare match register
   * 
   * OCR1A = (16*2^20) / (100*PRESCALER) - 1 (must be < 65536)
   *
   * assuming a prescaler = 1024 => OCR1A = (16*2^10)/freq 
   */
  OCR2A = 16*1024/freq; 
  // turn on CTC mode
  TCCR2B |= (1 << WGM12);
  // Set CS11 for 8 prescaler
  TCCR2B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE1A);

  // enabling interrupt
  sei();
  
}

/* period in ms */
void Timer::setupPeriod(int period){
  
  // disabling interrupt
  cli();

  TCCR2A = 0; // set entire TCCR1A register to 0
  TCCR2B = 0; // same for TCCR1B
  TCNT2  = 0; //initialize counter value to 0
  
  /* 
   * set compare match register
   * 
   * OCR1A = (16*2^20) / (100*PRESCALER) - 1 (must be < 65536)
   *
   * assuming a prescaler = 1024 => OCR1A = (16*2^10)* period/1000 (being in ms) 
   */
  OCR2A = 16.384*period; 
  // turn on CTC mode
  TCCR2B |= (1 << WGM12);
  // Set CS11 for 8 prescaler
  TCCR2B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE1A);

  // enabling interrupt
  sei();
  
}

void Timer::waitForNextTick(){
  /* wait for timer signal */
  while (!timerFlag){}
  timerFlag = false;
  
}
