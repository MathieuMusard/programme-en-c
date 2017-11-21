#include "cardio.h"
#include "param.h"
#include <arduino.h>

void clignotsimple(){
  int i;
  for(i=2;i<=11;i++)
     {
       digitalWrite(i, HIGH);
     }
     delay(40);
     for(i=2;i<=11;i++)
     {
       digitalWrite(i, LOW);
     }
}

void chenille(){
  int tps = 20;
  int i;
  for(i=2;i<=11;i++){
    digitalWrite(i, HIGH);
    delay(tps);
    digitalWrite(i, LOW);
  }
}

void chenilleinversee(){
  int tps = 20;
  int i;
  digitalWrite(2, HIGH);
  delay(tps);
  digitalWrite(2, LOW);
  for(i=11;i>=2;i--){
    digitalWrite(i, HIGH);
    delay(tps);
    digitalWrite(i, LOW);
  }
}

void serieallume(){
  int temps = 20;
  int i;
  for(i=2;i<=11;i++){
    digitalWrite(i, HIGH);
    delay(temps);
  }
  for(i=2;i<=11;i++){
    digitalWrite(i,LOW);
    delay(temps);
  } 
}

void choixmode(){
  if (Mode==1)
  {
    clignotsimple();
  }
  if (Mode==2)
  {
    chenille();
  }
  if (Mode==3)
  {
    chenilleinversee();
  }
  else if (Mode==4)
  {
    serieallume();
  }
}

void ecriturecsv(){
  int valeur, SeuilBattement;
  long temps = 0;
  int valeurPrecedente = 0;
  long tempsPrecedent = 0;
  valeur = analogRead(0);
  SeuilBattement = 640;
  int i;
  if (valeur > SeuilBattement) 
    {  
    if (valeurPrecedente <= SeuilBattement) 
      {  
      temps = millis();
      if (temps > (tempsPrecedent + 400))
        {  
        Serial.print(temps);
        Serial.println('_');
        choixmode();
        tempsPrecedent = temps;
      }
    }
  }
  valeurPrecedente = valeur;
}

