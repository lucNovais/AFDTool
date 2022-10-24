#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "afd.h"

/*
 * quebra_transicoes (**char)
 * ---------------------------------------------------------------------------
 * Fucao que recebe uma transicao de um AFD ({estado} {simbolo} {estado})
 * e quebra essa transicao por espacos, retornando assim um vetor de strings
 * com cada uma de suas 3 posicoes contendo um estado ou um simbolo que compoe
 * a transicao.
 * ---------------------------------------------------------------------------
 * Parametros:
 *
 * transicao (*char): string representando uma transicao de um AFD
 * ---------------------------------------------------------------------------
 * Retorno:
 *
 * retorno (**char): vetor de strings contendo as 3 componentes que formam
 *                   uma transicao.
 */
char **quebra_transicoes(char *transicao)
{
    char **retorno = malloc(3 * sizeof(char *));

    for (int i = 0; i < 3; i++)
        retorno[i] = malloc(100 * sizeof(char));

    char buffer[100];

    int contagem_espacos = 0;
    int posicionador = 0;

    for (int i = 0; i < 100; i++)
    {
        if (transicao[i] == ' ')
        {
            contagem_espacos++;

            if (contagem_espacos == 1)
            {
                strcpy(retorno[0], buffer);
                memset(buffer, 0, sizeof(buffer));

                posicionador = 0;
            }
            else if (contagem_espacos == 2)
            {
                strcpy(retorno[1], buffer);
                memset(buffer, 0, sizeof(buffer));

                posicionador = 0;
            }
            else if (contagem_espacos == 3)
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

/*
 * pega_indices_transicao (*int)
 * --------------------------------------------------------------------------------
 * Fucao que recebe uma lista de componentes de uma transicao (transicao quebrada)
 * e um AFD e retira, a partir dessa lista que representa uma transicao, os indices
 * que cada uma dessas componentes corresponde na lista de estados e simbolos de um
 * dado AFD.
 * --------------------------------------------------------------------------------
 * Parametros:
 *
 * transicao (**char): vetor de strings representando uma transicao quebrada
 *                     de um AFD
 * afd (AFD): AFD representado na estrutura de dados definida
 * --------------------------------------------------------------------------------
 * Retorno:
 *
 * indices (*int): vetor de indices contendo:
 *      - indices[0] = posicao do estado de partida na lista de estados do AFD
 *      - indices[1] = posicao do simbolo da transicao no alfabeto do AFD
 *      - indices[2] = posicao do estado alvo na lista de estados do AFD
 */
int *pega_indices_transicao(char **transicao, AFD afd)
{
    char *estado1 = malloc(100 * sizeof(char));
    char *simbolo = malloc(100 * sizeof(char));
    char *estado2 = malloc(100 * sizeof(char));

    int *indices = malloc(3 * sizeof(int));

    strcpy(estado1, transicao[0]);
    strcpy(simbolo, transicao[1]);
    strcpy(estado2, transicao[2]);

    for (int i = 0; i < afd.tamanhos[0]; i++)
    {
        if (strcmp(estado1, afd.estados[i]) == 0)
            indices[0] = i;
    }

    for (int i = 0; i < afd.tamanhos[1]; i++)
    {
        if (strcmp(simbolo, afd.estados[i]) == 0)
            indices[1] = i;
    }

    for (int i = 0; i < afd.tamanhos[0]; i++)
    {
        if (strcmp(estado2, afd.estados[i]) == 0)
            indices[2] = i;
    }

    return indices;
}
