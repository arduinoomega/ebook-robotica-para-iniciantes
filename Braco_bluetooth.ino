#include <Servo.h>                   // Ativa a biblioteca do Servo
Servo garra, elevar, avancar, base;  // nome dos servos
char comando;                        // Variável que recebe o comando vindo do aplicativo


void setup() {
  garra.attach(3);     // Anexar o motor 01 ao pino 03 (GARRA)
  elevar.attach(5);    // Anexar o motor 02 ao pino 05 (ELEVAÇÃO)
  avancar.attach(6);   // Anexar o motor 03 ao pino 06 (AVANÇO)
  base.attach(9);      // Anexar o motor 04 ao pino 09 (GIRO)
  Serial.begin(9600);  // Setup da conexão serial USB com o computador
  // Posição inicial do Braço
  posInicial();
}

void loop() {
  if (Serial.available() >= 0) {
    comando = Serial.read();  //Dado recebido do Aplicativo
    //Se o comando for '1', , o braço avança
    if (comando == '1') {
      elevar.write(45);
      delay(10);

      avancar.write(130);
      delay(10);
      garra.write(30);
      delay(10);
    }
    // Se o comando for '2', o braço levanta
    if (comando == '2') {
      elevar.write(120);
      delay(10);
      avancar.write(60);
      delay(10);
      garra.write(0);  //Escreve no servo o valor da posição
      delay(10);
    }
    // Se o comando for a letra 'D', de direita, o braço vira para direita
    if (comando == 'D') base.write(0);
    // Se o comando for a letra 'E', de esquerda, o braço vira para esquerda
    if (comando == 'E') base.write(180);
    // Se o comando for a letra 'I', de inicio, o braço vai para posição inicial
    if (comando == 'I') posInicial();
    // Se o comando for 'A', abrir a garra
    if (comando == 'A') garra.write(0);  // Ajuste o valor para a posição de abertura
    // Se o comando for 'F', fechar a garra
    if (comando == 'F') garra.write(90);  // Ajuste o valor para a posição de fechamento
  }
}
//Função que posiciona o braço na posição inicial
void posInicial() {
  garra.write(0);
  elevar.write(90);
  avancar.write(90);
  base.write(90);
  delay(10);
}
