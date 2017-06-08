#ifndef _NEURONIOS_H_
#define _NEURONIOS_H_

#define N_ENTRADAS 8
#define N_NEURONIOS 30
#define N_PONTOS (N_ENTRADAS * N_NEURONIOS)
#define N_LINHAS (1 << N_ENTRADAS)


//Cada neurônio de um vetor de saída de uma tabela verdade
typedef struct neuronio {
    int * saida;
} Neuronio;


void aprendizado (Neuronio * lista, int * pontos);


void treinamento (Neuronio * lista, const char * arquivo);


void nUns (Neuronio ** n);


Neuronio * criaNeuronios ();


void liberaNeuronios (Neuronio * n);


int Resultado (Neuronio ** n, int ** entrada, int n_entradas);

#endif
