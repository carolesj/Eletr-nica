#ifndef _LE_ARQUIVO_H_
#define _LE_ARQUIVO_H_

#include "Neuronios.h"
//Número de pontos a partir dos quais considera-se que a onda não tem mais ruídos
#define MIN_PONTOS_VALIDOS 12
#define ever ; ;

//Transforma o valor dos pontos das ondas em zeros e uns
//Recebe o nome do arquivo e retorna por referência o tamanho da onda recebida em pontos
//Retorna um vetor contendo todos os pontos da nova onda
int * digitalizaOndas (const char * nomeArquivo, int * n_pontos, float trash_hold);

//Acha amostras regulares nas ondas digitais
//Retorna por referência o número de amostras, recebe um vetor com todos os sinais e seu tamanho
//Retorna uma matriz com todas as amostras válidas encontradas
int ** amostrasValidas (int * nAmostras, int * sinais, int n_pontos, int * parada);

//Exporta a rede neural treinada para um arquivo
void imprimeNoArquivo (Neuronio ** RN);


void liberaAmostras (int *** amostras);


#endif
