/*Pega a onda gravada e a reescala para valores entre 0 e 1023*/

#include <stdio.h>
#include <limits.h>

int main(int argc, char ** argv) {
    FILE* fp = fopen("C:\\Users\\caroles\\Documents\\Audacity\\FlautaExemplo.raw", "rb");
    short int ponto;
    int i;
    long tamanho;
    //posiciona o cursor no fim do aquivo para achar o seu tamanho
    fseek(fp, 0, SEEK_END);
    tamanho = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    //percorre o arquivo até o chegar no último elemento, printando um a um
    for (i = 0; i < tamanho; i++) {
        if(fread(&ponto, sizeof(short), 1, fp) < 1) break;
        ponto = (short)((((double) ponto) / USHRT_MAX) * 1023);
        //fwrite(&ponto, sizeof(short), 1, stdout);
        if (i % 10 == 0) {
            printf("%d\n", ponto);
        }
    }

    fclose(fp);
    return 0;
}