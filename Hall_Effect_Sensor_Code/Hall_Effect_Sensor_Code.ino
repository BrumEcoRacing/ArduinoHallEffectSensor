#include <math.h>
#include "Timer.h"

#define HEInput A0
#define Comparator 3

void setup() {
  // put your setup code here, to run once:
  // serial.begin(9600);
  pinMode(A0,INPUT); // input of hall effect sensor
  timer.start();
}

void loop() {
  // put your main code here, to run repeatedly:

  HEValue = analogRead(A0);
  if (HEValue > Comparator){
    timer.stop();
    uint32_t elapsed = timer.read();

    int v = (2*M_PI*r)/elapsed;

    t.start(); //start a timer
  }

    
  Serial.print(v); 
}
