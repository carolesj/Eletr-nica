#include <stdio.h>
#include <stdlib.h>
#include "LeArquivo.h"
#include "Neuronios.h"

int * digitalizaOndas (const char * nomeArquivo, int * n_pontos, float threshold) {
    FILE * fp;
    int * sinais, i, tamanho;

    fp = fopen (nomeArquivo, "rb");
    if (fp == NULL) return NULL;

    fseek(fp, 0, SEEK_END);
    tamanho = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    tamanho /= sizeof(short);

    sinais = malloc(tamanho * sizeof(int));
    fread(sinais, sizeof(short), tamanho, fp);

    fclose(fp);

    //Se o valor do ponto for menor ou igual a zero, esse valor torna-se zero. Se for maior que zero, o valor torna-se um.
    for (i = 0; i < tamanho; i++) {
        if (*(sinais + i) <= threshold) {
            *(sinais + i) = 0;
        } else {
            *(sinais + i) = 1;
        }
    }

    *n_pontos = tamanho;

    return sinais;
}

int ** amostrasValidas (int * nAmostras, int * sinais, int n_pontos, int * parada) {
    int * aglomeracoes = NULL, bitAtual, i = 0, contador, nAglomeracoes = 0, acumulador = 0, anterior = -1;
    int ** amostrasValidas = NULL, n = 0;

    bitAtual = *sinais;
    //checa a quantidade de bits iguais consecutivos e atribui essa contagem a um vetor
    for (ever) {
        contador = 0;
        while (*(sinais + i) == bitAtual) {
            contador++;
            i++;
            if (i >= n_pontos) {
                goto fimDaContagem;
            }
        }
        aglomeracoes = realloc(aglomeracoes, sizeof(int) * ++nAglomeracoes);
        *(aglomeracoes + nAglomeracoes - 1) = contador;
        bitAtual = !bitAtual;
    }
fimDaContagem:
    bitAtual = *sinais;
    for (i = 0; i < nAglomeracoes; i++) {
        //verifica se é uma aglomeração de uns válida, se for, salva a posição onde começa essa aglomeração.
        //depois, verifica se existem pelo menos N_ENTRADAS * N_NEURONIOS pontos na amostra. Se existirem,
        //salva a amostra
        if (n == N_PONTOS) {
			goto cem_amostras;
		}
        if (bitAtual == 1 && *(aglomeracoes + i) >= MIN_PONTOS_VALIDOS) {
            if (anterior != -1 && (acumulador - anterior) <= N_PONTOS && anterior + N_PONTOS < n_pontos) {
                amostrasValidas = realloc(amostrasValidas, sizeof(int *) * ++n);
                *(amostrasValidas + n - 1) = (sinais + anterior);
            }
            anterior = acumulador;
        }
        acumulador += *(aglomeracoes + i);
        bitAtual = !bitAtual;
    }
cem_amostras:
    *nAmostras = n;
    *parada = acumulador;

    free(aglomeracoes);
    return amostrasValidas;
}

void liberaAmostras (int *** amostras) {
	int i;
	for (i = 0; i < N_THRESHOLD; i++) {
		free(*(amostras + i));
	}
	free(amostras);
	return;
}


