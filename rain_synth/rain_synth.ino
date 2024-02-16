#include <Audio.h>
#include "my_rain.h"

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


}
