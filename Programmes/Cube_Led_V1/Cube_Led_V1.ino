////////////////////////////////////////////
///Cube Led V1                           ///
///Cree par Miles White                  ///
///et Mathieu Corbel                     ///
///Ce programme permet d'allumer une led ///
////////////////////////////////////////////

int a=0; //Definit la cathode sur la broche 0
int b=A1; //Definit l'anode sur la broche 1

void setup() {
  pinMode(a, OUTPUT); //Definit la broche a comment sortie
  pinMode(b, OUTPUT); //Definit la broche b comment sortie
}

void loop() {
  digitalWrite(a, 0); //Met la broche 'a' a 0 
  digitalWrite(b, 1); //Met la broche 'b' a 1
}
