#include "Ultrasonic.h"  // Esse comando é para incluir a biblioteca no programa


Ultrasonic ultrasonic (8,9); // são as portas do sensor, Trigger na porta 5 e Echo na porta 6
 
// declarando os LEDs e o Buzzer e suas portas onde estão conectados

int ledVerde = 2;
int ledAmarelo = 3;
int ledVermelho =4;
int buzzer = 5; 

// Variáveis de controle 
 
long microsec = 0; 
float distanciaCM = 0;

void setup() {

Serial.begin(9600); // iniciando o monitor serial na velocidade 9600

// Declarando os LEDs e o Buzzer com saídas 

  pinMode(ledVerde,OUTPUT); 
  pinMode(ledAmarelo,OUTPUT);
  pinMode(ledVermelho,OUTPUT); 
  pinMode(buzzer,OUTPUT); 
}
 
void loop() { 

// lendo o sensor 
microsec = ultrasonic.timing(); 

// convertendo a distância para centímetros 

  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); 
 
  ledDistancia();

// mostrar a distância no monitor serial
Serial.print(distanciaCM); 

// unidade de medida 

Serial.println(" cm");
delay(500);
}

void ledDistancia() {

// se inicia com todos os LEDs apagados 
digitalWrite(ledVerde,LOW);  
digitalWrite(ledAmarelo,LOW);
digitalWrite(ledVermelho,LOW);

// Se a distância for menor ou igual a 30cm e maior ou igual 20
 
  if (distanciaCM <=30 and distanciaCM >= 20) {
 digitalWrite(ledVerde,HIGH); // LED Verde liga
 }

// Se a distância for menor ou igual a 20 cm e maior ou igual 10

 if (distanciaCM <=20 and distanciaCM >= 10) {

 digitalWrite(ledAmarelo,HIGH); // LED amarelo acende
 tone (buzzer, 2500, 100); // buzzer começa a emitir som
 }



 // se a distância for menor que 10cm

  if (distanciaCM < 10) { 
    digitalWrite(ledVermelho,HIGH); // LED Vermelho acende
    tone (buzzer, 2500, 1000); // Buzzer emite som mais intenso
  }
}



   
