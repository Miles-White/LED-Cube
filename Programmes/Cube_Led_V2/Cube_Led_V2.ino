////////////////////////////////////////////
///Cube Led V2                           ///
///Cree par Miles White                  ///
///et Mathieu Corbel                     ///
///Ce programme permet d'allumer         ///
///tout le cube LED                       ///
////////////////////////////////////////////

int etage[4]={A5,A3,A2,A1}; //Definit les broche des etages
int colonne[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A4,A0}; //Definit les broches des colonnes
  
void setup(){
  for(int i = 0; i<16; i++){  //Definit toutes les colonne comme sortie
    pinMode(colonne[i], OUTPUT);  
  }
  
  for(int i = 0; i<4; i++){ //Definit tous les etages comme sortie
    pinMode(etage[i], OUTPUT); 
  }
}

void loop(){
  for(int i = 0; i<16; i++){ //Eteint toutes les colonne
    digitalWrite(colonne[i], 0);
  }
  
  for(int i = 0; i<4; i++){ //Allume tous les etages
    digitalWrite(etage[i], 1);
  }
  delay(2000);
}
