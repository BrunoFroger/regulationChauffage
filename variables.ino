

int ledVerte = 3;      // select the pin for the LED
int ledOrange = 5;      // select the pin for the LED
int ledRouge = 7;      // select the pin for the LED
float sensorValue = 0;  // variable to store the value coming from the sensor
int seuil = 25;
int seuil1 = 30;
int consigne = 20;
// selection de la broche de la sonde de temperature
int sensorPin = 7;
boolean flagAffVariables = true;

void initVariables(){
  pinMode(ledVerte, OUTPUT);
  digitalWrite(ledVerte, LOW);
  pinMode(ledOrange, OUTPUT);
  digitalWrite(ledOrange, LOW);
  pinMode(ledRouge, OUTPUT);
  digitalWrite(ledRouge, LOW);
}

void setConsigne(int val){
  Serial.write("Nouvelle valeur de consigne = ");
  consigne = val;
  Serial.println(consigne);
}


int getConsigne(){
  //Serial.write("consigne = ");
  //Serial.write(consigne);
  return consigne;
}

void affVariables(){
  if (flagAffVariables){
    Serial.print("consigne =  ");
    Serial.print(consigne);
    Serial.print("; seuil = ");
    Serial.print(seuil);
    Serial.print("; seuil1 = ");
    Serial.print(seuil1);
    Serial.println("");
    Serial.print("ledVerte =  ");
    Serial.print(ledVerte);
    Serial.print("; ledOrange =  ");
    Serial.print(ledOrange);
    Serial.print("; ledRouge =  ");
    Serial.print(ledRouge);
    Serial.print("; sensorPin =  ");
    Serial.print(sensorPin);
    Serial.println("");
  }
}

void setAffVariables(String chaine){
  if (chaine.equals("ON")){
    Serial.print("activation de l'affichage");
    flagAffVariables=true;
  } else if (chaine.equals("OFF")){
    Serial.print("desactivation de l'affichage");
    flagAffVariables=false;
  } else {
    Serial.println("Erreur de syntaxe 'affichage = [ON|OFF]'");
  }
  return;
}

