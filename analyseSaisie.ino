

#include "variables.h"

void analyseSaisie(String chaine){
  // on cherche le symbole = dans la chaine
  int pos = chaine.indexOf('=');
  int pos1 = chaine.lastIndexOf('=');
  if (pos == -1){
      Serial.println("Erreur de syntaxe 'variable = valeur'");
      return;
  }
  //Serial.println(pos);
  if (pos != 0){
    // on a trouve le symbole = ; on decompose les deux parties de l'egalite
    if (pos1 != pos){
      // erreur deux symbole = dans la chaine
      Serial.println("Erreur : deux '=' dans votre commande");
      return;
    }
    String variable=suppBlancs(chaine.substring(0,pos));
    String valeur=suppBlancs(chaine.substring(pos+1,chaine.length()));
    if (valeur.length() == 0){
      Serial.print("erreur => manque valeur pour variable ");
      return;
    }
    char car = variable[0];
    if (car == 'D'){
      int pin = variable.substring(1,chaine.length()).toInt();
      String tmp = valeur;
      if (tmp.equals("ON")){
        Serial.print("allumage de la broche : ");
        Serial.println (pin);
        digitalWrite(pin, HIGH);
      } else if (tmp.equals("OFF")){
        Serial.print("extinction de la broche : ");
        Serial.println (pin);
        digitalWrite(pin, LOW);
      } else {
        Serial.println("Erreur de syntaxe 'DX = [ON|OFF]'");
      }
      return;
    }
    if (variable == "consigne"){
        consigne=valeur.toInt();
    }else if (variable == "read"){
        int val = analogRead(valeur.toInt());
        Serial.print("valeur lue sur entree analogique ");
        Serial.print(valeur);
        Serial.print(" = ");
        Serial.println(val);
    }else if (variable == "seuil"){
        seuil=valeur.toInt();
    }else if (variable == "seuil1"){
        seuil1=valeur.toInt();
    }else if (variable == "ledVerte"){
        ledVerte=valeur.toInt();
    }else if (variable == "ledOrange"){
        ledOrange=valeur.toInt();
    }else if (variable == "ledRouge"){
        ledRouge=valeur.toInt();
    }else if (variable == "sensorPin"){
        sensorPin=valeur.toInt();
    }else if (variable == "affiche"){
        setAffVariables(valeur);
    }else{
      Serial.print("erreur => variable inconnue : ");
      Serial.println(variable);
    }
  }
}

String suppBlancs(String chaine){
  char tmp[100]="";
  int j=0;
  char car;
  for (int i=0; i<chaine.length() ; i++){
    car=chaine[i];
    if (car != ' '){
      tmp[j++]=car;
      tmp[j]=0;
    }
  }
  return tmp;
}

