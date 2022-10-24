#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "afd.h"

/*
 * complemento_afd (VOID)
 * --------------------------------------------------------------------
 * Funcao que recebe um AFD no formato padrao, e retorna um AFD que
 * reconheça o complemento da linguagem reconhecida no autômato de
 * entrada.
 * --------------------------------------------------------------------
 * Parametros:
 *
 * afd (AFD): Autômato de entrada
 * --------------------------------------------------------------------
 * Retorno:
 *
 * afd_c (AFD): Complemento do autômato de entrada (.txt)
 */

void complemento_afd(AFD afd_entr, char *caminho_saida)
{
    char novos_estados_finais[MAX_LINHAS][MAX_CARACTERES];
    /* flag aponta os casos em que um valor deve ir para o novo vetor de estados finais */
    int flag;
    /* contador referencia as posições no novo vetor de estados finais */
    int contador = 0;
    FILE *arquivo;

    /* Armazenando os novos estados finais(que antes eram não finais) em um novo array */
    for (int i = 0; i < afd_entr.tamanhos[0]; i++)
    {
        flag = 1;
        for (int j = 0; j < afd_entr.tamanhos[3]; j++)
        {
            if (strcmp(afd_entr.estados[i], afd_entr.estados_finais[j]) == 0)
            {
                flag = 0;
            }
        }
        if (flag = 1) /*Estado não se encontra no conjunto de estados finais. Ou seja, agora será estado final*/
        {
            strcpy(novos_estados_finais[contador], afd_entr.estados[i]);
        }
    }

    afd_entr.tamanhos[3] = sizeof(novos_estados_finais) / sizeof(char);

    arquivo = fopen(caminho_saida, "w");
    fputs(afd_entr.tamanhos[0], arquivo);

    for (int i = 0; i < afd_entr.tamanhos[0]; i++)
    {
        fputs(afd_entr.estados[i], arquivo);
    }

    fputs(afd_entr.tamanhos[1], arquivo);
    for (int i = 0; i < afd_entr.tamanhos[1]; i++)
    {
        fputs(afd_entr.alfabeto[i], arquivo);
    }

    fputs(afd_entr.tamanhos[2], arquivo);
    for (int i = 0; i < afd_entr.tamanhos[2]; i++)
    {
        fputs(afd_entr.transicoes[i], arquivo);
    }

    fputs(afd_entr.tamanhos[3], arquivo);
    for (int i = 0; i < afd_entr.tamanhos[3]; i++)
    {
        fputs(novos_estados_finais[i], arquivo);
    }

    return 0;
}
