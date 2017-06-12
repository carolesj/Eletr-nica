#ifndef _NEURONIOS_H_
#define _NEURONIOS_H_

#define N_ENTRADAS 8
#define N_NEURONIOS 38
#define N_PONTOS 100
#define N_LINHAS (1 << N_ENTRADAS)
#define N_THRESHOLD 3
#define N_AMOSTRAS 100
#define N_CLASSES 7

//Cada neurônio de um vetor de saída de uma tabela verdade
typedef struct neuronio {
    int * saida;
} Neuronio;


void aprendizado (Neuronio * lista, int * pontos);


void treinamento (Neuronio * lista, const char * arquivo);


void nUns (Neuronio ** n);


Neuronio * criaNeuronios ();


void liberaNeuronios (Neuronio * n);


int Resultado (Neuronio ** n, int *** entrada, int n_entradas);

#endif
