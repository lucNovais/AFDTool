#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

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
