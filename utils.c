#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "afd.h"

char **quebra_transicoes(char *transicao)
{
    char **retorno = malloc(3 * sizeof(char*));

    for (int i = 0; i < 3; i++)
        retorno[i] = malloc(100 * sizeof(char));

    char buffer[100];

    int contagem_espacos = 0;
    int posicionador = 0;

    for(int i = 0; i < 100; i++)
    {
        if(transicao[i] == ' ')
        {
            contagem_espacos++;

            if(contagem_espacos == 1)
            {
                strcpy(retorno[0], buffer);
                memset(buffer, 0, sizeof(buffer));

                posicionador = 0;
            }
            else if(contagem_espacos == 2)
            {
                strcpy(retorno[1], buffer);
                memset(buffer, 0, sizeof(buffer));

                posicionador = 0;               
            }
            else if(contagem_espacos == 3)
            {
                strcpy(retorno[2], buffer);
                memset(buffer, 0, sizeof(buffer));

                break;
            }
        }
        else
        {
            buffer[posicionador] = transicao[i];
            posicionador++;
        }
    }

    return retorno;
}

int *pega_indices_transicao(char **transicao, AFD afd)
{
    char *estado1 = malloc(100 * sizeof(char));
    char *simbolo = malloc(100 * sizeof(char));
    char *estado2 = malloc(100 * sizeof(char));

    int *indices = malloc(3 * sizeof(int));

    strcpy(estado1, transicao[0]);
    strcpy(simbolo, transicao[1]);
    strcpy(estado2, transicao[2]);
    
    for(int i = 0; i < afd.tamanhos[0]; i++)
    {
        if(strcmp(estado1, afd.estados[i]) == 0)
            indices[0] = i;
    }

    for(int i = 0; i < afd.tamanhos[1]; i++)
    {
        if(strcmp(simbolo, afd.estados[i]) == 0)
            indices[1] = i;
    }

    for(int i = 0; i < afd.tamanhos[0]; i++)
    {
        if(strcmp(estado2, afd.estados[i]) == 0)
            indices[2] = i;
    }

    return indices;
}
