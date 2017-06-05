#ifndef _NEURONIOS_H_
#define _NEURONIOS_H_

#define N_ENTRADAS 8
#define N_NEURONIOS 10
#define N_PONTOS 80


//Cada neurônio de um vetor de saída de uma tabela verdade
typedef struct neuronio {
    int * saida;
} Neuronio;


void aprendizado (Neuronio * lista, int * pontos);


void treinamento (Neuronio * lista, const char * arquivo);


Neuronio * criaNeuronios ();


void liberaNeuronios (Neuronio * n);

#endif
