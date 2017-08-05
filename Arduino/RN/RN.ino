#include "RN.h"

int i = 0, j = 0, k = 0, contador = 0, aux, aux2, soma;
//será usado para ler as amostras
int amostra[100];
//definirá onde começa a amostra
int * comeco;
//conta quantos aglomerados de cada valor existem
int aglomerados[100];
//conta quantas amostras já foram feitas
int n_amostras = 0;
//define o valor do primeiro bit
int inicial = 0; 
//contém a soma de coincidência para cada classe
byte notas[7] = {0, 0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
}

void le_valores (int quantidade) {
  int atual;
  if (n_amostras < 100) {
    for (int q = 0; q < quantidade; q++) {
     atual = analogRead(PIN);
     if (atual > TH_1) {
       amostra[q] = 1;
     } else {
      amostra[q] = 0; 
     }
    }
  } else if (n_amostras < 200) {
    for (int q = 0; q < quantidade; q++) {
     atual = analogRead(PIN);
     if (atual > TH_2) {
       amostra[q] = 1;
     } else {
      amostra[q] = 0; 
     }
    }
  } else {
    for (int q = 0; q < quantidade; q++) {
     atual = analogRead(PIN);
     if (atual > TH_3) {
       amostra[q] = 1;
     } else {
      amostra[q] = 0; 
     }
    }
  }
  return;
}

void reconhece () {
  
}

void loop() {
  //define o bit inicial como sendo o primeiro do vetor
  inicial = amostra[0];
  while (i < TAM_AMOSTRA) {
    //se o atual for igual ao próximo, soma um no valor atual
    if (amostra[i] == amostra[i + 1]) {
      j++;
      i++;
    } else {
      aglomerados[k] = j + 1;
      j = 0;
      k++;
      i++;
    }
  }
  //conta quantos aglomerados são maiores que o mínimo de pontos válidos
  //se existe algum 0, para de rodar porque os aglomerados acabaram
  for (i = 0; i < 100 && aglomerados[i] > 0; i++){
    if(aglomerados[i] >= MIN_PONTOS_VALIDOS) {
      contador++;
    }
  }
  //se existem ao menos três aglomerados, temos uma amostra completa
  if (contador >= 3) {
    //percorre até achar o primeiro aglomerado
    for (aux = 0; aux < i && aglomerados[aux] < MIN_PONTOS_VALIDOS; aux++);
    soma = 0;
    //soma os valores anteriores para achar qual posição no vetor amostras na qual realmente começa a amostra sem ruídos
    for (aux2 = 0; aux2 < aux; aux2++) {
      soma += aglomerados[aux];
    }
    comeco = amostra[soma + 1];
    le_valores(soma);
    reconhece();
  }
  
}
