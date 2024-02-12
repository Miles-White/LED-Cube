////////////////////////////////////////////
///Dechiffreur port serie V2             ///
///Cree par Miles White                  ///
///et Mathieu Corbel                     ///
///Ce programme permet d'envoyer 64      ///
///caractere et de controller les led du ///
///cube correspondante                   ///
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
   data = Serial.readString(); //Dectect les caracactere envoyer au moniteur serie
   
   for(int i=0; i<16; i++){ //Detecte les carctere envoyer a toutes les led du 1ere etage
    if (data[i] == '1'){ //Si c'est un 1 les led s'allumeront
     digitalWrite(etage[0], 1);
     digitalWrite(colonne[i], 0);
    }
   if (data[i] == '0'){ //Si c'est un 0 les led s'eteindront
     digitalWrite(colonne[i], 1);
   }
   }
   for(int i=17; i<32; i++){ //Detecte les carctere envoyer a toutes les led du 2eme etage
    if (data[i] == '1'){ //Si c'est un 1 les led s'allumeront
     digitalWrite(etage[1], 1);
     digitalWrite(colonne[i-17], 0);
    }
   if (data[i] == '0'){ //Si c'est un 0 les led s'eteindront
     digitalWrite(colonne[i-17], 1);
   }
   }
   for(int i=33; i<48; i++){ //Detecte les carctere envoyer a toutes les led du 3eme etage
    if (data[i] == '1'){ //Si c'est un 1 les led s'allumeront
     digitalWrite(etage[2], 1);
     digitalWrite(colonne[i-33], 0);
    }
   if (data[i] == '0'){ //Si c'est un 0 les led s'eteindront
     digitalWrite(colonne[i-33], 1);
   }
   }
   for(int i=49; i<64; i++){ //Detecte les carctere envoyer a toutes les led du 4eme etage
    if (data[i] == '1'){ //Si c'est un 1 les led s'allumeront
     digitalWrite(etage[3], 1);
     digitalWrite(colonne[i-49], 0);
    }
   if (data[i] == '0'){ //Si c'est un 0 les led s'eteindront
     digitalWrite(colonne[i-49], 1);
   }
   }  
}
