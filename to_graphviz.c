#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "to_graphviz.h"
#include "afd.h"
#include "utils.h"

void afd_para_dot(AFD afd, char *caminho_saida)
{
    FILE *arquivo;

    arquivo = fopen(caminho_saida, "w");

    char estados_finais_linha[MAX_CARACTERES];
    char transicao_output[MAX_CARACTERES];
    char mensagem_doublecircle[MAX_CARACTERES];
    char tab[MAX_CARACTERES];
    char aux[MAX_CARACTERES];
    char buffer[MAX_CARACTERES];
    char aux_buffer1[MAX_CARACTERES];
    char aux_buffer2[MAX_CARACTERES];

    fputs("digraph finite_state_machine {\n", arquivo);
    fputs("\tfontname=\"Helvetica,Arial,sans-serif\"\n", arquivo);
    fputs("\tnode [fontname=\"Helvetica,Arial,sans-serif\"]\n", arquivo);
    fputs("\tedge [fontname=\"Helvetica,Arial,sans-serif\"]\n", arquivo);
    fputs("\trankdir=LR;\n", arquivo);

    strcpy(estados_finais_linha, "");

    for(int i = 0; i < afd.tamanhos[3]; i++)
    {
        strcat(estados_finais_linha, " ");
        strcpy(buffer, afd.estados_finais[i]);
        buffer[strcspn(buffer, "\n")] = 0;
        strcat(estados_finais_linha, buffer);
    }

    strcpy(mensagem_doublecircle, "\tnode [shape = doublecircle];");
    strcpy(tab, "\t");

    fputs(mensagem_doublecircle, arquivo);
    fputs(estados_finais_linha, arquivo);
    fputs(";", arquivo);
    fputs("\n\tnode [shape = circle];\n", arquivo);

    char **transicoes = malloc(3 * sizeof(char*));

    for(int i = 0; i < 3; i++)
        transicoes[i] = malloc(100 * sizeof(char));

    strcpy(buffer, "");

    for(int i = 0; i < afd.tamanhos[2]; i++)
    {
        transicoes = quebra_transicoes(afd.transicoes[i]);

        strcpy(aux_buffer1, transicoes[0]);
        aux_buffer1[strcspn(aux_buffer1, "\n")] = 0;

        strcpy(aux_buffer2, transicoes[2]);
        aux_buffer2[strcspn(aux_buffer2, "\n")] = 0;

        snprintf(buffer, MAX_CARACTERES, "%s -> %s", aux_buffer1, aux_buffer2);
        strcpy(aux, buffer);
        snprintf(buffer, MAX_CARACTERES, " [label = \"%s\"];\n", transicoes[1]);
        strcat(aux, buffer);
        strcpy(transicao_output, aux);

        strcat(tab, transicao_output);
        strcpy(transicao_output, tab);

        fputs(transicao_output, arquivo);

        memset(aux, 0, MAX_CARACTERES);
        memset(aux_buffer1, 0, MAX_CARACTERES);
        memset(aux_buffer2, 0, MAX_CARACTERES);
        memset(transicao_output, 0, MAX_CARACTERES);
        memset(buffer, 0, MAX_CARACTERES);

        strcpy(tab, "\t");
    }

    fputs("}", arquivo);

    fclose(arquivo);
}
