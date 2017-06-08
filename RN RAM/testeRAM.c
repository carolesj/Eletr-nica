#include <stdio.h>
#include <stdlib.h>
#include "Neuronios.h"

int main (int argc, char ** argv) {
	Neuronio * zero, * um, * dois, * tres;
	int tzero[] = {0, 0}, tum[] = {0, 1}, tdois[] = {1, 0}, ttres[] = {1, 1};
	int resultado;
	
	
	zero = criaNeuronios();
	um = criaNeuronios();
	dois = criaNeuronios();
	tres = criaNeuronios();
	
	Neuronio * teste[] = {zero, um, dois, tres};
	
	aprendizado(zero, tzero);
	aprendizado(um, tum);
	aprendizado(dois, tdois);
	aprendizado(tres, ttres);
	
	resultado = Resultado(teste, tzero);
	printf("%d\n", resultado);
	resultado = Resultado(teste, tum);
	printf("%d\n", resultado);
	resultado = Resultado(teste, tdois);
	printf("%d\n", resultado);
	resultado = Resultado(teste, ttres);
	printf("%d\n", resultado);
	
	liberaNeuronios(zero);
	liberaNeuronios(um);
	liberaNeuronios(dois);
	liberaNeuronios(tres);
}
