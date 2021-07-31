//Definição dos pinos de saída para os dois motores e os LEDs

#define IN1 7                      
#define IN2 6                      
#define IN3 5                      
#define IN4 4
int led1 = 2;
int led2 = 3;    

//Definindo pinos para o controle de velocidade dos motores
#define ENA 10                       
#define ENB 11                      


void setup() {

  Serial.begin(9600); // inicia a porta serial, configura a taxa de dados para 9600 bps

  // Declarando os motores e os LEDs como Saídas
  pinMode(IN1,OUTPUT);   
  pinMode(led1,OUTPUT); 
  pinMode(led2,OUTPUT);       
  pinMode(IN2,OUTPUT);              
  pinMode(IN3,OUTPUT);              
  pinMode(IN4,OUTPUT);              
  pinMode(ENA,OUTPUT);              
  pinMode(ENB,OUTPUT);     

  
// Velocidade dos Motores, Caso esteja muito lento ou muito rápido altere os números entre 0 a 255
           
  analogWrite(ENA,110);            
  analogWrite(ENB,110);            
  }
 
char cha;
 
void loop() {  
if (Serial.available() > 0) {
   cha = Serial.read();
  delay(2);
 
//Movimenta para frente

if(cha == 'F'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

//Movimenta para trás

if(cha == 'B'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
 
}

//movimenta para direita

if(cha == 'R'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

//movimenta para esquerda

if(cha == 'L'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

//Sem movimento
if(cha == '0'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

// Liga os LEDs

if(cha == '3'){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
}

//Desliga LEDs

if(cha == '4'){
 
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);

}
}
}
