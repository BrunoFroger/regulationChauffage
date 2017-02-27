

#include "variables.h"

// lecture de temperature
float getTemperature(){
  float mesure = analogRead(sensorPin);
  mesure = (mesure / 7) + 1.5;
  return mesure;
}

