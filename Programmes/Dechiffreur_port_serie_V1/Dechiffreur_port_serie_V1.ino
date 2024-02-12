////////////////////////////////////////////
///Dechiffreur port serie V1             ///
///Cree par Miles White                  ///
///et Mathieu Corbel                     ///
///Ce programme permet d'envoyer un      ///
///caractere et d'allumer une led si     ///
///c'est un 1 ou de l'eteindre si c'est  ///
///un 0.                                 ///
////////////////////////////////////////////

String data; 
int colonne[16]={13,12,9,A0,11,10,2,A4,8,7,6,5,4,3,0,1}; //Definit les broches des colonnes
int etage[4]={A1,A2,A3,A5}; //Definit les broche des etages

void setup() {
  Serial.begin(9600);
  for (int i=0; i<16; i++){ //Definit toutes les colonne comme sortie
    pinMode(colonne[i], OUTPUT); 
  }
  for (int i=0; i<4; i++){ //Definit tous les etages comme sortie
    pinMode(etage[i], OUTPUT);
  }
}

void loop() {
   data = Serial.readString();  //Dectect les caracactere envoyer au moniteur serie
  
    if (data[1] == '1'){  //Si un 1 est envoyer allumer la led 1 
     digitalWrite(etage[0], 1); 
     digitalWrite(colonne[1], 0);
    }
   if (data[1] == '0'){ //Si un 0 est envoyer eteindre la led 0
     digitalWrite(colonne[1], 1);
 
