#ifndef _NEURONIOS_H_
#define _NEURONIOS_H_

#define N_ENTRADAS 3
#define N_NEURONIOS 15
#define N_PONTOS 100
#define N_LINHAS (1 << N_ENTRADAS)
#define N_THRESHOLD 3
#define N_AMOSTRAS 100
#define N_CLASSES 7

//Cada neurônio de um vetor de saída de uma tabela verdade
typedef struct neuronio {
    int * saida;
} Neuronio;

//Acessa as posições no vetor de saída do neurônio dadas pela onda recebida e seta essas posições como 1
//Recebe a lista de neurônios e o vetor processado de exemplos para treinamento
void aprendizado (Neuronio * lista, int * pontos);


//Pré processa os dados do arquivo para poder fazer o aprendizado
//Recebe a lista de neurônios e o nome do arquivo
void treinamento (Neuronio * lista, const char * arquivo);


//Imprime o número de uns setados em cada classe
void nUns (Neuronio ** n);


//Aloca os neurônios
Neuronio * criaNeuronios ();


//Libera os neurônios
void liberaNeuronios (Neuronio * n);


//Passa uma entrada na rede e dá a resposta reconhecida
//Recebe a lista de neurônios, as entradas processadas e o número de entradas
int Resultado (Neuronio ** n, int *** entrada, int n_entradas);

#endif
