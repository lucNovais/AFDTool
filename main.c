#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "to_graphviz.h"
#include "le_afd.h"
#include "afd.h"

#define DOT "--dot"
#define OUTPUT "--output"

int main(int argc, char *argv[])
{
    char *caminho_arquivo = NULL;
    char *caminho_saida = NULL;

    /* Este laco verifica quais flags foram usadas para rodar o programa e chama as funcoes adequadas */
    for(int i = 0; i < argc; i++)
    {
        if(strcmp(argv[i], DOT) == 0)
        {
            caminho_arquivo = argv[i + 1];
        }
        if(strcmp(argv[i], OUTPUT) == 0)
        {
            caminho_saida = argv[i + 1];
        }
    }

    AFD afd = arquivo_para_afd(caminho_arquivo);
    afd_para_dot(afd, caminho_saida);

    return 0;
}
