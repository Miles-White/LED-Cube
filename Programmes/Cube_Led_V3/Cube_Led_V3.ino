////////////////////////////////////////////
///Cube Led V3                           ///
///Cree par Miles White                  ///
///et Mathieu Corbel                     ///
///Ce programme permet de l'ancer des    ///
///animations grace aux boutons ainsi    ///
///que de faire clignoter 2 etage et     ///
///de faire varier la vitesse grace a    ///
///un potentiometre.                     ///
////////////////////////////////////////////
 
int etage[4]={A1,A2,A3,A5}; //Definit les broche des etages
int colonne[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A0,A4};//Definit les broches des colonnes
int button=A6; //Definit le bouton sur la broche A6
int slider=A7; //Definit le potentiometre sur la broche A7
int val = 0;  //Met val a 0

void setup() {
  for (int i=0; i<16; i++){ //Definit toutes les colonne comme sortie
    pinMode(colonne[i], OUTPUT);
  }
  for (int i=0; i<4; i++){ //Definit tous les etages comme sortie
    pinMode(etage[i], OUTPUT);
  }
  pinMode(button, INPUT); //Definit le bouton comme entree
  pinMode(slider, INPUT); //Definit le potentiometre comme entree
  led_off();

}

void loop() {
  int t = analogRead(slider) / 3 * 2; //calcul de la vitesse grace au potientiometre
  if (analogRead(button) == 128) { //si bouton 1 acitiver
    val = 0; //affecter 0 a la variable val
  } 
  if (analogRead(button) == 1019) { //si bouton 2 acitiver
    val = 1; //affecter 1 a la variable val
  } 
  if (analogRead(button) == 561 ){  //si bouton 2 acitiver
    val = 2; //affecter 2 a la variable val
  }
  while (val == 0){ //Si val = 0
    led_etape_1(); //allumer l'etage 1
  }
  while (val == 1){ //Si val = 1
    led_etape_2(); //allumer l'etage 1
  }
  
  while (val == 2){ //Si val = 2
    led_etape_1();  //faire clignote avec un intervale de temps variable
    delay(t);
    led_etape_2();
    delay(t);
    led_etape_1();
    delay(t);
    led_etape_2();
    delay(t);
  }
}

void colonne_on(){ //Allumer toutes les colonne
  for(int i=0; i<16; i++){
    digitalWrite(colonne[i], LOW); 
  }
}
void led_etape_1(){ //Eteindre tout les etages sauf l'etage 2
  colonne_on();
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
}

void led_etape_2(){ //Eteindre tout les etages sauf l'etage 3
  colonne_on();
  for(int i=0; i<3; i++){
    digitalWrite(etage[i],LOW);
  }
  digitalWrite(A3,HIGH);
 }
