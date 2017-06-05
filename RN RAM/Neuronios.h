#IFNDEF _NEURONIOS_H_
#DEFINE _NEURONIOS_H_

#define N_ENTRADAS 8
#define N_NEURONIOS 10
#define N_PONTOS 80


//Cada neurônio é composto de uma matriz que é uma tabela verdade e um vetor de saída dessa tabela
typedef struct neuronio {
    //int ** tabela_verdade;
    int * saida;
} Neuronio;


void Aprendizado (Neuronio * lista, int * pontos);


#ENDIF
