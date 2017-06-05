#include "Neuronios.h"

void Aprendizado (Neuronio * lista, int * pontos) {
    int atual, i, j;

    for (i = 0; i < N_NEURONIOS; i++) {
        atual = 0;
        for (j = 0; j < N_ENTRADAS; j++) {
            atual <<= 1;
            atual |= *(ponto + (N_ENTRADAS * i) + j);
        }
        *(*(lista + i)->saida + atual) = 1;
    }
}


