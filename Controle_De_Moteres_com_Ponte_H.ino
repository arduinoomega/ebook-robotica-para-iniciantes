// declarando as portas onde os motores estão conectado 

int IN1 = 6;
int IN2 = 5;
int IN3 = 4;
int IN4 = 3;
  
void setup()
{
  
//Definindo os motores como saídas 
  
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
}
void loop()
{

//comando para girar o Motor A no sentido horário

//OBS: Lembre da tabela da Ponte H !!

 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 delay(2000); // espera 2 segundos 

 // Comando para freiar o motor A

 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 delay(1000); // espera 1 segundo 

 //Comando para girar o motor B no sentido horário

 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay(2000); // delay de 2 segundos

 // Comanda para freiar o Motor B

 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
 delay(1000); // delay de 1 segundo

 //Comando para girar o Motor A no sentido anti-horário

 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 delay(2000); // delay de 2 segundos

 //Comando para freiar o motor A

 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 delay(1000); // delay de 1 segundo

 //Comando para girar o motor B no sentido anti-horário

 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay(2000); // delay de 2 segundos

 //Freia motor B

 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
 delay(1000); //delay de 1 segundo
}
