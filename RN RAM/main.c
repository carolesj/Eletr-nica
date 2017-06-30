#include <stdio.h>
#include <stdlib.h>
#include "Neuronios.h"
#include "LeArquivo.h"

#define ARQUIVO_TESTE "SiTeste.raw"
#define N_CLASSES 7

int main(int argc, char ** argv) {
	Neuronio ** notas;
    Neuronio * Do, * Re, * Mi, * Fa, * Sol, * La, * Si;
    int **pontos, ***entradas;
    int n_pontos1, n_pontos2, n_pontos3, parada1, parada2, parada3, n_amostras, resultado;

    Do = criaNeuronios();
    Re = criaNeuronios();
    Mi = criaNeuronios();
    Fa = criaNeuronios();
    Sol = criaNeuronios();
    La = criaNeuronios();
    Si = criaNeuronios();
	
	/*treinamento(Do, "Do1.raw");
	treinamento(Re, "Re1.raw");
	treinamento(Mi, "Mi1.raw");
	treinamento(Fa, "Fa1.raw");
	treinamento(Sol, "Sol1.raw");
	treinamento(La, "La1.raw");
	treinamento(Si, "Si1.raw");*/
	treinamento(Do, "Do2.raw");
	treinamento(Re, "Re2.raw");
	treinamento(Mi, "Mi2.raw");
	treinamento(Fa, "Fa2.raw");
	//treinamento(Sol, "Sol2.raw");
	//treinamento(La, "La2.raw");
	//treinamento(Si, "Si2.raw");
	//treinamento(Do, "Do3.raw");
	//treinamento(Re, "Re3.raw");
	//treinamento(Mi, "Mi3.raw");
	//treinamento(Fa, "Fa3.raw");
	treinamento(Sol, "Sol3.raw");
	treinamento(La, "La3.raw");
	treinamento(Si, "Si3.raw");
	
	
	notas = malloc(sizeof(Neuronio *) * N_CLASSES);
	*(notas) = Do;
	*(notas + 1) = Re;
	*(notas + 2) = Mi;
	*(notas + 3) = Fa;
	*(notas + 4) = Sol;
	*(notas + 5) = La;
	*(notas + 6) = Si;
	
	//imprimeNoArquivo(notas);
	
	pontos = malloc(sizeof(int *) * N_THRESHOLD);
	*pontos = digitalizaOndas(ARQUIVO_TESTE, &n_pontos1, 0.0);
	*(pontos + 1) = digitalizaOndas(ARQUIVO_TESTE, &n_pontos2, 2.5);
	*(pontos + 2) = digitalizaOndas(ARQUIVO_TESTE, &n_pontos3, -2.5);
	entradas = malloc(sizeof(int **) * N_THRESHOLD);
	*entradas = amostrasValidas(&n_amostras, *pontos, n_pontos1, &parada1);
	*(entradas + 1) = amostrasValidas(&n_amostras, *(pontos + 1) + parada1, n_pontos2 - parada1, &parada2);
	*(entradas + 2) = amostrasValidas(&n_amostras, *(pontos + 2) + parada1 + parada2, n_pontos3 - parada1 - parada2, &parada3);
	resultado = Resultado(notas, entradas, N_AMOSTRAS);
	printf("\n%d\n", resultado);
	
	nUns(notas);
	
	liberaNeuronios(Do);
	liberaNeuronios(Re);
	liberaNeuronios(Mi);
	liberaNeuronios(Fa);
	liberaNeuronios(Sol);
	liberaNeuronios(La);
	liberaNeuronios(Si);
	free(notas);
	liberaAmostras(entradas);
	free(pontos);
    
    return 0;
}



