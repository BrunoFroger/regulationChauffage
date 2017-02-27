/*
 Cree par Bruno FROGER
 creation le 26 Fev 2017
 */
 
#include "SondeTemperature.h"
#include "variables.h"
#include "serie.h"
#include "analyseSaisie.h"


void setup() {
  setupSerie();
  initVariables();

  affVariables();

}

String saisie;

void loop() {
  // read the value from the sensor:
  sensorValue = getTemperature();
  //Serial.print("temperature =  ");
  //Serial.print(sensorValue);
  //Serial.println("");

  //afficheLeds();
  
  saisie = serieRead();
  if (saisie != ""){
    //Serial.println(saisie);
    analyseSaisie(saisie);
    affVariables();
  }

  // stop the program for for <sensorValue> milliseconds:
  delay(2000);
}



void afficheLeds(){
  
  if (sensorValue < seuil){
    digitalWrite(ledVerte, HIGH);
    digitalWrite(ledOrange, LOW);
    digitalWrite(ledRouge, LOW);
  }else{
    if (sensorValue < seuil1){
      digitalWrite(ledVerte, LOW);  
      digitalWrite(ledOrange, HIGH);
      digitalWrite(ledRouge, LOW);    
    }else{
      digitalWrite(ledVerte, LOW);  
      digitalWrite(ledOrange, LOW);
      digitalWrite(ledRouge, HIGH);    
    }
  }
}

