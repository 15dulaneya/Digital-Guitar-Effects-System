#include "dsp.h"
#include "timers.h"
#include "Arduino.h"

void setupIO() {
  // prepare left
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  waveformGenerationMode(3, fastPWM);
  timerPrescale(3, 1);
  analogWrite(3, 0);
  
  // prepare right
  waveformGenerationMode(5, fastPWM);
  timerPrescale(5, 1);
  analogWrite(5, 0);
  
  // faster input
  analogReference(INTERNAL);
  analogPrescale(analogPrescale32);
}
  
//void output(int channel, short value) {
//  if(channel == left) {
//    pwm3 = value >> 2;
//    pwm11 = (value & B11) << 6;
//  } else if(channel == right) {
//    pwm5 = value >> 2;
//    pwm6 = (value & B11) << 6;
//  }
//}

void output(int channel, short value) {
  if(channel == left) {
    analogWrite(3,value >> 2);
    analogWrite(11, (value & B11) << 6);
  } else if(channel == right) {
    analogWrite(5 , value >> 2);
    analogWrite(6 , (value & B11) << 6);
  }
}

