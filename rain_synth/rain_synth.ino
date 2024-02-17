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
  audioShield.volume(0.5);
  rain.setParamValue("rainIntensity",0);
  rain.setParamValue("volumeGoutte",0);
}

void loop() {
  
  int sensorValue2= analogRead(A0);
  float rainIntensity= (sensorValue2/1024.0);
  rain.setParamValue("rainIntensity",rainIntensity);
  if ((millis()- changedrop)> wait) {
    rain.setParamValue("gate",1);
    delay(25);
    rain.setParamValue("gate",0);
    changedrop= millis();
    wait = random(500,600 + 3000*(1-rainIntensity));//
  }
  
  if ((millis()- change)> periode) {
    rain.setParamValue("volumeGoutte",random(5,10)/10.0);
    rain.setParamValue("freqDrop",random(400,600 ));
    float stereoDrop = random(0,100)/100.0;
    rain.setParamValue("output1",stereoDrop);
    rain.setParamValue("output2",1-stereoDrop);
    
    change= millis();
  }
  
}
