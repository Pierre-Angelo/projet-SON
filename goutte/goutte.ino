#include <Audio.h>
#include "goutte.h"
float periode=500;
float change=0;
float wait =1;
float changedrop = 0;



goutte goutte;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(goutte,0,out,0);
AudioConnection patchCord1(goutte,0,out,1);

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
  
  
}

void loop() {
  int sensorValue = analogRead(A0);
  //float frequencygoutte = (sensorValue/1024.0)*9 + 1  ; 
  //goutte.setParamValue("freqGoutte",frequencygoutte);
  if ((millis()- changedrop)> wait*1000) {
    goutte.setParamValue("gate",1);
    delay(25);
    goutte.setParamValue("gate",0);
    delay(25);
    changedrop= millis();
    wait= 0.5 + random(0,sensorValue)/1024.0;
  }
  
  if ((millis()- change)> periode) {
    goutte.setParamValue("freq",random(400,1000));
    change= millis();
  }
  
}
