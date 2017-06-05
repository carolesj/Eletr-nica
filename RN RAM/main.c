#include <stdio.h>
#include "Neuronios.h"
//#include "TabelaVerdade.h"

#define N_ENTRADAS 8
#define N_LINHAS 256
#define N_NEURONIOS 10


int main(int argc, char ** argv) {
    Neuronio * Do, * Re, * Mi, * Fa, * Sol, * La, * Si;
    int i, j, * entradas;

    //Aloca os vetores de neurônios
    Do = malloc(N_NEURONIOS * sizeof(Neuronio));
    Re = malloc(N_NEURONIOS * sizeof(Neuronio));
    Mi = malloc(N_NEURONIOS * sizeof(Neuronio));
    Fa = malloc(N_NEURONIOS * sizeof(Neuronio));
    Sol = malloc(N_NEURONIOS * sizeof(Neuronio));
    La = malloc(N_NEURONIOS * sizeof(Neuronio));
    Si = malloc(N_NEURONIOS * sizeof(Neuronio));

    //Aloca o vetor de saída, inicializado com zeros
    for (i = 0; i < N_NEURONIOS; i++) {
        *(Do + i)->saida = calloc(N_ENTRADAS , sizeof(int));
        *(Re + i)->saida = calloc(N_ENTRADAS , sizeof(int));
        *(Mi + i)->saida = calloc(N_ENTRADAS , sizeof(int));
        *(Fa + i)->saida = calloc(N_ENTRADAS , sizeof(int));
        *(Sol + i)->saida = calloc(N_ENTRADAS , sizeof(int));
        *(La + i)->saida = calloc(N_ENTRADAS , sizeof(int));
        *(Si + i)->saida = calloc(N_ENTRADAS , sizeof(int));
    }



    return 0;

}









