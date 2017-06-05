#IFNDEF _NEURONIOS_H_
#DEFINE _NEURONIOS_H_

#define N_ENTRADAS 8
#define N_NEURONIOS 10
#define N_PONTOS 80


//Cada neur�nio � composto de uma matriz que � uma tabela verdade e um vetor de sa�da dessa tabela
typedef struct neuronio {
    //int ** tabela_verdade;
    int * saida;
} Neuronio;


void Aprendizado (Neuronio * lista, int * pontos);


#ENDIF
