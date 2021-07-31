// Para usar a biblioteca VarSpeedServo
#include "VarSpeedServo.h"

// Definição dos objetos servos do braço robótico

VarSpeedServo servo1; //Base
VarSpeedServo servo2; //Extensão
VarSpeedServo servo3; //Altura
VarSpeedServo servo4; //Garra

// Definição das entradas analógicas do Joytick

// Joystick Esquerdo

int potpin1 = A0;//VRy
int potpin2 = A1;//VRx

// Joystick Direito

int potpin3 = A2;//VRx
int potpin4 = A3;//VRy

// Variáveis

int val1;
int val2;
int val3;
int val4;

//Valores iniciais de posição de cada servo

static int s1 = 70;
static int s2 = 110;
static int s3 = 100;
static int s4 = 80;

void setup()
{
Serial.begin(9600); // Inicia a porta serial, configura a taxa de dados para 9600bps

// Anexa o objeto servo ao pino

servo1.attach(9); //Base, pino digital 9
servo2.attach(6); //Extensão, pino digital 6
servo3.attach(5); //Altura, pino digital 5
servo4.attach(3); //Garra, pino digital 3

// Move todo o braço para posição inicial

servo1.write(70); //Base
servo2.write(110); //Extensão
servo3.write(100); //Altura
servo4.write(80); //Garra
}
void loop()
{
// Controle da base do braço

val1 = analogRead(potpin1); // Lê o valor do pino analógico especificado (A0VRy, joystick Esquerdo)

// Para direita

if (val1 < 100)
{
s1 = s1 - 2;
if (s1 <= 10)
{
s1 = 10;
}
servo1.write(s1); // Posição em graus para o servo
delay(50); // Espera 50 milessegundos
}

// Para esquerda

if (val1 > 900)
{
s1 = s1 + 2; // soma
if (s1 >= 170)
{
s1 = 170;
}
servo1.write(s1);
delay(50);
}

// Controle da extensão do braço

val2 = analogRead(potpin2);

// Para trás

if (val2 > 900)
{
s2 = s2 - 2;
if (s2 <= 10)
{
s2 = 10;
}
servo2.write(s2);
delay(50);
}

// Para frente

if (val2 < 100)
{
s2 = s2 + 2;
if (s2 >= 170)
{
s2 = 170;
}
servo2.write(s2);
delay(50);
}
// Controle da altura do braço

//Abaixar o braço
val3 = analogRead(potpin3);
if (val3 < 100)
{
s3 = s3 - 2;
if (s3 <= 10)
{
s3 = 10;
}
servo3.write(s3);
delay(50);
}
//Levantar o braço

if (val3 > 900)
{
s3 = s3 + 2;
if (s3 >= 170)
{
s3 = 170;
}
servo3.write(s3);
delay(50);
}
// Controle da garra do braço

val4 = analogRead(potpin4);
// Abrir a garra

if (val4 < 100)
{
s4 = s4 - 2;
if (s4 <= 80)
{
s4 = 80;
}
servo4.write(s4);
delay(50);
}
// Fechar a garra

if (val4 > 900)
{
s4 = s4 + 2;
if (s4 >= 130)
{
s4 = 130;
}
servo4.write(s4);
delay(50);
}

// Exibe os valores analogicos na tela

Serial.print(val1);
Serial.print(" : ");
Serial.print(val2);
Serial.print(" : ");
Serial.print(val3);
Serial.print(" : ");
Serial.print(val4);
Serial.println();
}
