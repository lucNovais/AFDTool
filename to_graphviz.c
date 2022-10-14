#include <stdio.h>
#include <string.h>

#include "to_graphviz.h"
#include "afd.h"

void afd_para_dot(struct afd afd, char *caminho_saida)
{
    FILE *arquivo;

    arquivo = fopen(caminho_saida, "w");

    char estados_finais_linha[MAX_CARACTERES];
    char transicao_output[MAX_CARACTERES];
    char mensagem_doublecircle[MAX_CARACTERES];
    char tab[MAX_CARACTERES];

    fputs("digraph finite_state_machine {\n", arquivo);
    fputs("\tfontname='Helvetica,Arial,sans-serif'\n", arquivo);
    fputs("\tnode [fontname='Helvetica,Arial,sans-serif']\n", arquivo);
    fputs("\tedge [fontname='Helvetica,Arial,sans-serif']\n", arquivo);
    fputs("\trankdir=LR;\n", arquivo);

    for(int i = 0; i < afd.tamanhos[3]; i++)
    {
        strcpy(estados_finais_linha, strcat(estados_finais_linha, " "));
        strcpy(estados_finais_linha, strcat(estados_finais_linha, afd.estados_finais[i]));
    }

    strcpy(mensagem_doublecircle, "\tnode [shape = doublecircle];");
    strcpy(tab, "\t");

    strcpy(estados_finais_linha, strcat(mensagem_doublecircle, estados_finais_linha));
    strcpy(estados_finais_linha, strcat(estados_finais_linha, ";"));

    fputs(estados_finais_linha, arquivo);
    fputs("\tnode [shape = circle];\n", arquivo);

    for(int i = 0; i < afd.tamanhos[2]; i++)
    {
        strcpy(transicao_output, strcat(afd.transicoes[i], " [label = 'Label'];\n"));
        strcpy(transicao_output, strcat(tab, transicao_output));
        fputs(transicao_output, arquivo);
    }

    fputs("}", arquivo);

    fclose(arquivo);
}
