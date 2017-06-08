#include <stdio.h>
#include <stdlib.h>
#include "Neuronios.h"
#include "LeArquivo.h"

#define N_CLASSES 7

int main(int argc, char ** argv) {
	Neuronio ** notas;
    Neuronio * Do, * Re, * Mi, * Fa, * Sol, * La, * Si;
    int *pontos, **entradas, n_pontos, n_amostras, resultado;

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
	treinamento(Sol, "Sol2.raw");
	treinamento(La, "La2.raw");
	treinamento(Si, "Si2.raw");
	/*treinamento(Do, "Do3.raw");
	treinamento(Re, "Re3.raw");
	treinamento(Mi, "Mi3.raw");
	treinamento(Fa, "Fa3.raw");
	treinamento(Sol, "Sol3.raw");
	treinamento(La, "La3.raw");
	treinamento(Si, "Si3.raw");*/
	
	
	notas = malloc(sizeof(Neuronio *) * N_CLASSES);
	*(notas) = Do;
	*(notas + 1) = Re;
	*(notas + 2) = Mi;
	*(notas + 3) = Fa;
	*(notas + 4) = Sol;
	*(notas + 5) = La;
	*(notas + 6) = Si;
	
	nUns(notas);
	
	pontos = digitalizaOndas("MiTeste.raw", &n_pontos);
	entradas = amostrasValidas(&n_amostras, pontos, n_pontos);
	resultado = Resultado(notas, entradas, n_amostras);
	printf("\n%d\n", resultado);
	
	liberaNeuronios(Do);
	liberaNeuronios(Re);
	liberaNeuronios(Mi);
	liberaNeuronios(Fa);
	liberaNeuronios(Sol);
	liberaNeuronios(La);
	liberaNeuronios(Si);
	free(notas);
	liberaAmostras(entradas, n_amostras);
	free(pontos);
    
    return 0;
}









