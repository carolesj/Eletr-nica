#include <stdio.h>
#include <stdlib.h>
#include "Neuronios.h"

int main(int argc, char ** argv) {
    Neuronio * Do, * Re, * Mi, * Fa, * Sol, * La, * Si;

    Do = criaNeuronios();
    Re = criaNeuronios();
    Mi = criaNeuronios();
    Fa = criaNeuronios();
    Sol = criaNeuronios();
    La = criaNeuronios();
    Si = criaNeuronios();
	
	treinamento(Do, "Do1.raw");
	treinamento(Re, "Re1.raw");
	treinamento(Mi, "Mi1.raw");
	treinamento(Fa, "Fa1.raw");
	treinamento(Sol, "Sol1.raw");
	treinamento(La, "La1.raw");
	treinamento(Si, "Si1.raw");

	liberaNeuronios(Do);
	liberaNeuronios(Re);
	liberaNeuronios(Mi);
	liberaNeuronios(Fa);
	liberaNeuronios(Sol);
	liberaNeuronios(La);
	liberaNeuronios(Si);
    
    return 0;
}








