/////////////////////////////////////////////////////////////////////////
//Cube_Led_V4 créer par Miles White et Mathieu Corbel.                //
//Ce programme permet de faire varier les animations selon les boutons.//
/////////////////////////////////////////////////////////////////////////

int layer[4]={A1,A2,A3,A5};                                   //Definit les etage du cube LED
int column[16]={13,12,9,A0,11,10,2,A4,8,7,6,5,4,3,0,1};       //Definit les colone du cube LED
int button=A6;                                                //Definit les bouton sur la broche A6
int slider=A7;                                                //Definit le potentiometre sur la broche A7
int val=0;                    //Definit val a 0

void setup() {

  for(int i=0; i<16; i++){      //Definit toute les colomnes comme sortie
    pinMode(column[i], OUTPUT);
  }
  for(int i=0; i<4; i++){     //Definit tout les etages comme sortie
    pinMode(layer[i], OUTPUT);
  }
  pinMode(button, INPUT);  //Definit le bouton comme entree
  pinMode(slider, INPUT);  //Definit le slider comme entree
  randomSeed(analogRead(10));  //Determine un nombre aleatoire
}

void loop() {
  
  if (analogRead(button) == 128) {  //Si le bouton 1 est activer 
    val = 1;                        //Met la variable 'val' a 1
  }
  if (analogRead(button) == 1019) { //Si le bouton 2 est activer
    val = 2;                        //Met la variable 'val' a 2
  } 
  if (analogRead(button) == 561) {  //Si le bouton 3 est activer
    val = 3;                        //Met la variable 'val' a 3
  }
  if (val == 0){                    //Si val est a 0
    turnEverythingOn();             //tous allumer
  }
  if (val == 1){                   //Si val est a 1
    flickerOn();                   //faire clignoter le cube led
  }
  if (val == 2){                   //Si val est a 2
    spiralInAndOut();              //faire une spiral sur le cube led
  }
  if (val == 3){                   //Si val est a 3
    randomflicker();               //faire une clignoter aleatoirement le cube led
  }
}
//turn all off
void turnEverythingOff()           //tout eteindre
 {
   for(int i = 0; i<16; i++)        //allume toutes les cologne
   {
     digitalWrite(column[i], 1);
   }
   for(int i = 0; i<4; i++)         //eteind tout les etages
   {
     digitalWrite(layer[i], 0);
   }
 }

//turn all on
void turnEverythingOn()     //alumme tous
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);     //eteint toutes les colonnes
  }
  for(int i = 0; i<4; i++)        //allume tous les etages
  {
    digitalWrite(layer[i], 1);
  }
}
//turn columns off
void turnColumnsOff()
{
  for(int i = 0; i<16; i++)     
  {
    digitalWrite(column[i], 1);   //éteint toutes les colonnes
  }
}
//flicker on
void flickerOn()                         //partie du programme qui fait clignoter le cube entier
{
    int t = analogRead(slider)/2;

    turnEverythingOn();
    delay(t);
    turnEverythingOff();
    delay(t);
}

void randomflicker()                     //partie du programme quifait clignoter des led les unes aprrès les autres aléatoirement
{
  int t = analogRead(slider)/7;

  turnEverythingOff();
  
  int randomLayer = random(0,4);
  int randomColumn = random(0,16);
  
  digitalWrite(layer[randomLayer], 1);
  digitalWrite(column[randomColumn], 0);
  delay(t);
  digitalWrite(layer[randomLayer], 0);
  digitalWrite(column[randomColumn], 1);
  delay(t); 
  
}

void spiralInAndOut()                   //partie du programme qui créer une animation en forme de spirale
{   
 int t = analogRead(slider)/25;
 

 for(int i=0; i<4; i++){
  digitalWrite(layer[i], 1);
 }
  
    //spiral in clockwise
 digitalWrite(column[0], 1);
 delay(t);
 digitalWrite(column[0], 0);
 delay(t);
 digitalWrite(column[0], 1);
 delay(t);
 digitalWrite(column[1], 1);
 delay(t);
 digitalWrite(column[1], 0);
 delay(t);
 digitalWrite(column[1], 1);
 delay(t);
 digitalWrite(column[4], 1);
 delay(t);
 digitalWrite(column[4], 0);
 delay(t);
 digitalWrite(column[4], 1);
 delay(t);
 digitalWrite(column[2], 1);
 delay(t);
 digitalWrite(column[2], 0);
 delay(t);
 digitalWrite(column[2], 1);
 delay(t);
 digitalWrite(column[5], 1);
 delay(t);
 digitalWrite(column[5], 0);
 delay(t);
 digitalWrite(column[5], 1);
 delay(t);
 digitalWrite(column[8], 1);
 delay(t);
 digitalWrite(column[8], 0);
 delay(t);
 digitalWrite(column[8], 1);
 delay(t);
 digitalWrite(column[3], 1);
 delay(t);
 digitalWrite(column[3], 0);
 delay(t);
 digitalWrite(column[3], 1);
 delay(t);
 digitalWrite(column[6], 1);
 delay(t);
 digitalWrite(column[6], 0);
 delay(t);
 digitalWrite(column[6], 1);
 delay(t);
 digitalWrite(column[9], 1);
 delay(t);
 digitalWrite(column[9], 0);
 delay(t);
 digitalWrite(column[9], 1);
 delay(t);
 digitalWrite(column[12], 1);
 delay(t);
 digitalWrite(column[12], 0);
 delay(t);
 digitalWrite(column[12], 1);
 delay(t);
 digitalWrite(column[7], 1);
 delay(t);
 digitalWrite(column[7], 0);
 delay(t);
 digitalWrite(column[7], 1);
 delay(t);
 digitalWrite(column[10], 1);
 delay(t);
 digitalWrite(column[10], 0);
 delay(t);
 digitalWrite(column[10], 1);
 delay(t);
 digitalWrite(column[13], 1);
 delay(t);
 digitalWrite(column[13], 0);
 delay(t);
 digitalWrite(column[13], 1);
 delay(t);
 digitalWrite(column[11], 1);
 delay(t);
 digitalWrite(column[11], 0);
 delay(t);
 digitalWrite(column[11], 1);
 delay(t);
 digitalWrite(column[14], 1);
 delay(t);
 digitalWrite(column[14], 0);
 delay(t);
 digitalWrite(column[14], 1);
 delay(t);
 digitalWrite(column[15], 1);
 delay(t);
 digitalWrite(column[15], 0);
 delay(t);
 digitalWrite(column[15], 1);
 delay(t);
}
