#include "dsp.h"

// create an array for the delay
byte array[2000]; 

//define variables
int j;
int fx;
int value50;
//int value300;
int value10000;
int delayed;

int Effect1Pin = 2;
int Effect2Pin = 7;
int Effect3Pin = 8;

void setup() {
  setupIO();
  pinMode(Effect1Pin,INPUT);
  pinMode(Effect2Pin,INPUT);
  pinMode(Effect3Pin,INPUT);
  
  //set initial values
  j = 50;
  value50 = 50;
//  value300 = 300;
  value10000 = 1000;
  delayed = 0;

  //Serial.begin(9600);
}

void loop() {
  
    //check status of the effect potentiometer and rotary switch
    readKnobs();
    //Serial.print(digitalRead(Effect1Pin));

      
    
    // Distortion
      if (digitalRead(Effect1Pin)==1) {
        value50 = 1 + ((float) fx / (float) 1000);    
        byte input = analogRead(left);
        input = (input * value50); 
        output(left, input); 
      }
      
    // Tremolo
      if (digitalRead(Effect2Pin)==1) {
        value10000 = fx * 10;  
        if(delayed > value10000) { 
          for(int i = 0; i < 2000; i ++) { // set up a loop    
            array[i] = array[i] + array[i - 1]; //removes noise and delay
            output(left, array[i]);
            array[i] = analogRead(left);
          }
          delayed = 0;
        }
        delayed++;
      }

    // Distortion Delay
      if (digitalRead(Effect3Pin)==1) {
         for(int i = 0; i < 2000; i ++) { // set up a loop    
        //array[i] = array[i] + array[i - 1]; //removes noise and some delay
          output(left, array[i]);
          array[i] = analogRead(left);
        }
      }
      


}

void readKnobs(){
    
  //reads the effects pot to adjust
  //the intensity of the effects above  
  fx = analogRead(3);

}
