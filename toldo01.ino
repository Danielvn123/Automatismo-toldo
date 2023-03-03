/*
Este script activa un motor que desprega un toldo cando aumenta
a luz solar, Non é un caso real, porque non recolle o toldo.

O sensor tampouco é o máis preciso para esta funcióm.

Ao superarse un detertminado umbral luminoso, activase o relé 
que alimenta ao motor. O motor está activo durante todo o
percorrido do toldo, que se estira que se desprega en 7 segundos.

Autor: Daniel Vilas
Data: Febreiro de 2023
*/

#define RELE 12
#define LDR A0

//int pinRele = 12;
//int pulsador = A0;
int umbral = 950;
int entrada = -999;
bool releON = false;
int contador = 100;

void setup(){
  pinMode(RELE, OUTPUT);
  pinMode(LDR, INPUT);  //Non é necesario declarala, porque a entrada é analóxica.
  Serial.begin(9600);
}

void loop(){
  //LECTURA DE ENTRADAS
  entrada = analogRead(LDR); //A lectura vai estar entre 54 e 974.
  Serial.print("Entrada LDR: ");
  Serial.println(entrada);
   
  if(contador > 0 && entrada > umbral){
    Serial.print("Contador: "); Serial.println(contador);
    releON = true;
    contador--;
    delay(70);
  }
  else{
    releON = false;
  }
  digitalWrite(RELE, releON);
}
