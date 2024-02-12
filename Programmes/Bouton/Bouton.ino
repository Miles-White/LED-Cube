///////////////////////////////////////////////////////////////////////////
//Bouton créer par Milles White et Mathieu Corbel.                    //
//Ce programme permet d'indiquer dans le moniteur série l'état du bouton.//
///////////////////////////////////////////////////////////////////////////

int button=A6;            //Definit le bouton sur la broche A6
int buttonState = 0;      //Definit l'etat du bouton a 0

void setup() {
  Serial.begin(9600);     //Demare le moniteur serie
  pinMode(button, INPUT); //Definit le bouton commen entree
}

void loop() {
  if (analogRead(button) > 1000) {  //Si le bouton est appuier
    Serial.println(1);              //Afficher '1'
    delay(100);;  
  } 
  else {                           //Sinon
    Serial.println(0);             //Afficher '0'
    delay(100);

  }
}
