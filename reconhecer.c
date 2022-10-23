#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "afd.h"
#include "utils.h"

void reconhecer_palavra(AFD afd, char *caminho_palavras)
{
    FILE *arquivo;

    arquivo = fopen(caminho_palavras, "r");

    if(arquivo == NULL)
    {
        printf("\n[AFDTOOL] Arquivo de palavras invalido!\n");
        exit(1);
    }

    printf("\n[AFDTOOL] Lendo palavras...");

    int numero_palavras;

    for(char c = getc(arquivo); c != EOF; c = getc(arquivo))
    {
        if(c == '\n')
            numero_palavras++;
    }

    fclose(arquivo);

    char linha[MAX_CARACTERES];
    char **palavras = malloc(numero_palavras * sizeof(char*));

    for(int i = 0; i < numero_palavras; i++)
        palavras[i] = malloc(MAX_CARACTERES * sizeof(char));

    arquivo = fopen(caminho_palavras, "r");
    int i = 0;

    while(fgets(linha, MAX_CARACTERES, arquivo))
    {
        strcpy(palavras[i], linha);
        i++;
    }

    fclose(arquivo);
    
    return;
}
