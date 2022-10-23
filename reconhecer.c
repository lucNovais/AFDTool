#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "afd.h"
#include "utils.h"

/* 
 * afd_para_dot (void)
 * ----------------------------------------------------------------------------------
 * Funcao que recebe um AFD, um caminho (arquivo) contendo palavras a serem testadas
 * e um caminho de saida para resultado da execucao. A partir das palavras no arquivo
 * de entrada, executa o AFD sob cada uma delas e diz se essa palavra e reconhecida
 * na linguagem do AFD.
 * ----------------------------------------------------------------------------------
 * Parametros:
 * 
 * afd (struct afd): afd representado na estrutura de dados definida
 * caminho_palavras (*char): string contendo o arquivo de entrada com as palavras
 * caminho_saida (*char): string contendo a pasta + nome do arquivo de saida .txt
 * ----------------------------------------------------------------------------------
 */
void reconhecer_palavra(AFD afd, char *caminho_palavras, char *caminho_saida)
{
    FILE *arquivo;

    arquivo = fopen(caminho_palavras, "r");

    if (arquivo == NULL)
    {
        printf("\n[AFDTOOL] Arquivo de palavras invalido!\n");
        exit(1);
    }

    printf("\n[AFDTOOL] Lendo palavras...\n");

    int numero_palavras;

    for (char c = getc(arquivo); c != EOF; c = getc(arquivo))
    {
        if (c == '\n')
            numero_palavras++;
    }

    numero_palavras--;

    fclose(arquivo);

    char linha[MAX_CARACTERES];
    char **palavras = malloc(numero_palavras * sizeof(char *));

    for (int i = 0; i < numero_palavras; i++)
        palavras[i] = malloc(MAX_CARACTERES * sizeof(char));
    arquivo = fopen(caminho_palavras, "r");
    int i = 0;

    while (fgets(linha, MAX_CARACTERES, arquivo))
    {
        strcpy(palavras[i], linha);
        i++;
    }

    numero_palavras = i;

    fclose(arquivo);

    char **transicao = malloc(3 * sizeof(char *));

    for (int i = 0; i < 3; i++)
        transicao[i] = malloc(MAX_CARACTERES * sizeof(char));

    char simbolo_atual;
    char *palavra_atual = palavras[0];
    char *aux = malloc(MAX_CARACTERES * sizeof(char));
    char *estado_atual = malloc(MAX_CARACTERES * sizeof(char));
    
    int tamanho_palavra = strlen(palavra_atual);

    printf("\n[AFDTOOL] Escrevendo arquivo de palavras reconhecidas...\n");

    arquivo = fopen(caminho_saida, "w");

    for (int i = 0; i < numero_palavras; i++)
    {
        strcpy(palavra_atual, palavras[i]);
        palavra_atual[strcspn(palavra_atual, "\n")] = 0;
        tamanho_palavra = strlen(palavra_atual);

        strcpy(estado_atual, afd.estado_inicial);
        estado_atual[strcspn(estado_atual, "\n")] = 0;

        for (int j = 0; j < tamanho_palavra; j++)
        {
            simbolo_atual = palavras[i][j];
            for (int k = 0; k < afd.tamanhos[2]; k++)
            {
                transicao = quebra_transicoes(afd.transicoes[k]);

                if (strcmp(estado_atual, transicao[0]) == 0 && simbolo_atual == transicao[1][0])
                {
                    strcpy(estado_atual, transicao[2]);
                    estado_atual[strcspn(estado_atual, "\n")] = 0;
                    break;
                }
            }
        }
        for (int k = 0; k < afd.tamanhos[3]; k++)
        {
            strcpy(aux, afd.estados_finais[k]);
            aux[strcspn(aux, "\n")] = 0;
            estado_atual[strcspn(estado_atual, "\n")] = 0;

            if(strcmp(estado_atual, aux) == 0)
            {
                fprintf(arquivo, "%d\n", 1);
                break;
            }

            fprintf(arquivo, "%d\n", 0);
        }
    }

    fclose(arquivo);

    return;
}
