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
  Serial.begin(9600);
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
  goutte.setParamValue("freqgoutte",1);
  
}

void loop() {
  int sensorValue = analogRead(A0);
  //float frequencygoutte = (sensorValue/1024.0)*9 + 1  ; 
  //goutte.setParamValue("freqGoutte",frequencygoutte);
  if ((millis()- changedrop)> wait) {
    goutte.setParamValue("gate",1);
    goutte.setParamValue("gate",0);
    changedrop= millis();
    wait= 0.5 + random(0,sensorValue/1024.0);
    Serial.println(sensorValue);
    delay(100);
  }
  
  if ((millis()- change)> periode) {
    goutte.setParamValue("freq",random(400,1000));
    change= millis();
  }
  
}
