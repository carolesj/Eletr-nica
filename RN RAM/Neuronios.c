#include "Neuronios.h"
#include "LeArquivo.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void aprendizado (Neuronio * lista, int * pontos) {
    int atual, i, j;

    for (i = 0; i < N_NEURONIOS; i++) {
        atual = 0;
        for (j = 0; j < N_ENTRADAS; j++) {
            atual <<= 1;
            atual |= *(pontos + (N_ENTRADAS * i) + j);
        }
        *((lista + i)->saida + atual) = 1;
    }
    return;
}

void treinamento (Neuronio * lista, const char * arquivo) {
	int n_pontos, n_amostras, i, j, k, parada1, parada2, parada3;
	int ** pontos, *** amostras;
	pontos = malloc(sizeof(int *) * N_THRESHOLD);
	amostras = malloc(sizeof(int **) * N_THRESHOLD);
	//digitaliza a onda com o threshold no 0
	*(pontos) = digitalizaOndas(arquivo, &n_pontos, 0.0);
	//digitaliza a onda com o threshold no 2.5
	*(pontos + 1) = digitalizaOndas(arquivo, &n_pontos, 2.5);
	//digitaliza a onda com o threshold no -2.5
	*(pontos + 2) = digitalizaOndas(arquivo, &n_pontos, -2.5);
	//tira as primeiras cem amostras do vetor e recebe onde elas acabam
	*(amostras) = amostrasValidas(&n_amostras, *pontos, n_pontos, &parada1);
	printf("%s\n", arquivo);
	printf("Primeiras: %d amostras\n", n_amostras);
	//tira as próximas cem amostras a partir de onde acabaram as outras, e recebo onde estas acabam
	*(amostras + 1) = amostrasValidas(&n_amostras, (*(pontos + 1) + parada1), (n_pontos - parada1), &parada2);
	printf("Segundas: %d amostras\n", n_amostras);
	//tira as seguintes cem amostras depois do fim da anterior
	*(amostras + 2) = amostrasValidas(&n_amostras, (*(pontos + 2) + parada1 + parada2), (n_pontos - parada1 - parada2), &parada3);
	printf("Terceiras: %d amostras\n\n", n_amostras);
	for (i = 0; i < N_THRESHOLD; i++) {
		for (j = 0; j < N_AMOSTRAS; j++) {
			aprendizado(lista, *(*(amostras + i) + j));
			printf("%d - %d: ", i, j);
			for (k = 0; k < N_PONTOS; k++) {
				printf("%d ", *(*(*(amostras + i) + j) + k));
			}
			printf("\n");
		}
		free(*(amostras + i));
	}
	free(amostras);
	for (i = 0; i < N_THRESHOLD; i++) {
		free(*(pontos + i));
	}
	free(pontos);
}

int Resultado (Neuronio ** n, int *** entrada, int n_entradas) {
	int i, j, k, l, m, indice = 0, inicio, maior_valor, maior_indice;
	int * n_compatibilidades = NULL;
	
	n_compatibilidades = calloc(N_CLASSES, sizeof(int));
	
	for (m = 0; m < N_THRESHOLD; m++) {
		for (l = 0; l < n_entradas; l++) {
			//percorre a matriz de neuronios
			for (i = 0; i < N_CLASSES; i++) {
				//percorre os vetores de neuronios
				for (j = 0; j < N_NEURONIOS; j++) {
					//percorre o vetor de amostras de 8 em 8 e salva o valor numérico em indice
					inicio = j * N_ENTRADAS;
					indice = 0;
					for (k = 0; k < N_ENTRADAS; k++) {
						indice = indice + (*(*(*(entrada + m) + l) + inicio + k) * (pow(2, N_ENTRADAS - k - 1)));
					}
					//se o vetor de saída daquele neurônio na posição indice for igual a um, incrementa o número
					//de compatibilidades com aquele vetor de neurônios
					if(*((*(n + i) + j)->saida + indice) == 1) {
						*(n_compatibilidades + i) += 1; 
					}
				}
			}
		}
	}
	
	maior_valor = *n_compatibilidades;
	maior_indice = 0;
	
	for (i = 1; i < N_CLASSES; i++) {
		if (*(n_compatibilidades + i) > maior_valor) {
			maior_valor = *(n_compatibilidades + i);
			maior_indice = i;
		}
	}
	
	free(n_compatibilidades);
	return maior_indice;
}

void nUns (Neuronio ** n) {
	int i, j, k, acumulador;
	for (i = 0; i < N_CLASSES; i++) {
		acumulador = 0;
		for (k = 0; k < N_NEURONIOS; k++) {
			for (j = 0; j < N_LINHAS; j++) {
				acumulador += *((*(n + i) + k)->saida + j);
			}
		}
		printf("%d\n", acumulador);
	}
	
}

Neuronio * criaNeuronios () {
	Neuronio * n;
	int i;
	if ((n = malloc(N_NEURONIOS * sizeof(Neuronio)))) {
		for (i = 0; i < N_NEURONIOS; i++) {
			 ((n + i)->saida) = calloc(N_LINHAS , sizeof(int));
		}
	}
	return n;
}

void liberaNeuronios (Neuronio * n) {
	int i;
	
	for (i = 0; i < N_NEURONIOS; i++) {
		free((n + i)->saida);
	}
	free(n);
	
	return;
}
