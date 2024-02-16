#include <Audio.h>
#include "my_rain.h"

float periode=500;
float change=0;
float wait =1;
float changedrop = 0;

my_rain rain;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(rain,0,out,0);
AudioConnection patchCord1(rain,1,out,1);


void setup() {
  // put your setup code here, to run once:
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.02);
  rain.setParamValue("rainIntensity",0.9);

}

void loop() {
  int sensorValue = analogRead(A0);
  //float frequencygoutte = (sensorValue/1024.0)*9 + 1  ; 
  //goutte.setParamValue("freqGoutte",frequencygoutte);
  if ((millis()- changedrop)> wait*1000) {
    rain.setParamValue("gate",1);
    delay(25);
    rain.setParamValue("gate",0);
    delay(25);
    changedrop= millis();
    wait= 0.5 + random(0,sensorValue)/1024.0;
  }
  
  if ((millis()- change)> periode) {
    rain.setParamValue("freq",random(400,1000));
    change= millis();
  }
  
}
