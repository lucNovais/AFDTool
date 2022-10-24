#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "to_graphviz.h"
#include "le_afd.h"
#include "afd.h"
#include "reconhecer.h"

#define DOT "--dot"
#define RECONHECER "--reconhecer"
#define OUTPUT "--output"

int main(int argc, char *argv[])
{
    char *caminho_arquivo = NULL;
    char *caminho_saida = NULL;
    char *caminho_palavras = NULL;
    char *operacao = NULL;

    /* Este laco verifica quais flags foram usadas para rodar o programa e chama as funcoes adequadas */
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], DOT) == 0)
        {
            caminho_arquivo = argv[i + 1];
            operacao = DOT;
        }
        else if (strcmp(argv[i], RECONHECER) == 0)
        {
            caminho_arquivo = argv[i + 1];
            caminho_palavras = argv[i + 2];

            operacao = RECONHECER;
        }
        else if (strcmp(argv[i], OUTPUT) == 0)
        {
            caminho_saida = argv[i + 1];
        }
    }

    AFD afd = arquivo_para_afd(caminho_arquivo);

    if (strcmp(operacao, DOT) == 0)
        afd_para_dot(afd, caminho_saida);
    else if (strcmp(operacao, RECONHECER) == 0)
        reconhecer_palavra(afd, caminho_palavras, caminho_saida);

    return 0;
}
