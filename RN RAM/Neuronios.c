#include "Neuronios.h"
#include "LeArquivo.h"
#include <stdlib.h>

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
	int n_pontos, n_amostras, i;
	int * pontos, ** amostras;
	pontos = digitalizaOndas(arquivo, &n_pontos);
	amostras = amostrasValidas(&n_amostras, pontos, n_pontos);
	for (i = 0; i < n_amostras; i++) {
		aprendizado(lista, *(amostras + i));
	}
	free(pontos);
	free(amostras);
}


Neuronio * criaNeuronios () {
	Neuronio * n;
	int i;
	if ((n = malloc(N_NEURONIOS * sizeof(Neuronio)))) {
		for (i = 0; i < N_NEURONIOS; i++) {
			 ((n + i)->saida) = calloc(N_ENTRADAS , sizeof(int));
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
