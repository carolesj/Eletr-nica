/*
Programa que lê as entradas dadas por um microfone através do pino analógico A0 e imprime o valor lido no terminal serial
*/


#define ENTRADA_ANALOGICA A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(ENTRADA_ANALOGICA));
  delay(500);
}
