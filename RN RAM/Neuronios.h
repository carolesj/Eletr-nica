#ifndef _NEURONIOS_H_
#define _NEURONIOS_H_

#define N_ENTRADAS 3
#define N_NEURONIOS 15
#define N_PONTOS 100
#define N_LINHAS (1 << N_ENTRADAS)
#define N_THRESHOLD 3
#define N_AMOSTRAS 100
#define N_CLASSES 7

//Cada neur�nio de um vetor de sa�da de uma tabela verdade
typedef struct neuronio {
    int * saida;
} Neuronio;

//Acessa as posi��es no vetor de sa�da do neur�nio dadas pela onda recebida e seta essas posi��es como 1
//Recebe a lista de neur�nios e o vetor processado de exemplos para treinamento
void aprendizado (Neuronio * lista, int * pontos);


//Pr� processa os dados do arquivo para poder fazer o aprendizado
//Recebe a lista de neur�nios e o nome do arquivo
void treinamento (Neuronio * lista, const char * arquivo);


//Imprime o n�mero de uns setados em cada classe
void nUns (Neuronio ** n);


//Aloca os neur�nios
Neuronio * criaNeuronios ();


//Libera os neur�nios
void liberaNeuronios (Neuronio * n);


//Passa uma entrada na rede e d� a resposta reconhecida
//Recebe a lista de neur�nios, as entradas processadas e o n�mero de entradas
int Resultado (Neuronio ** n, int *** entrada, int n_entradas);

#endif
