#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "le_afd.h"
#include "afd.h"

/* 
 * arquivo_para_afd (AFD)
 * --------------------------------------------------------------------
 * Funcao que recebe um caminho com um .txt no formato padrao de AFD e
 * retira as informacoes correspondentes para armazena-las na estrutura
 * de dados criada.
 * --------------------------------------------------------------------
 * Parametros:
 * 
 * caminho_arquivo (*char): caminho/diretorio + nome do arquivo do AFD
 * --------------------------------------------------------------------
 * Retorno:
 * 
 * afd (AFD): estrutura de dados do AFD preenchida
 */
AFD arquivo_para_afd(char *caminho_arquivo)
{
    FILE *arquivo;

    AFD afd;

    int numero_estados;
    int tamanho_alfabeto;
    int numero_transicoes;
    int numero_finais;

    int quantidade = 0;
    int lendo_quantidade = 1;
    int quantidades_lidas = 0;

    printf("\n[AFDTOOL] Lendo arquivo...");
    arquivo = fopen(caminho_arquivo, "r");

    if(arquivo == NULL)
    {
        printf("\n[AFDTOOL] Arquivo de entrada invalido!\n");
        exit(1);
    }


    printf("\n[AFDTOOL] Lendo estados, alfabeto e transicoes...");

    char linha[MAX_CARACTERES];

    int indice = 0;
    while(fgets(linha, MAX_CARACTERES, arquivo))
    {
        if(lendo_quantidade)
        {
            quantidade = atoi(linha);
            numero_estados = quantidade;
            lendo_quantidade = 0;
        }
        else if(!quantidade)
        {
            quantidades_lidas++;

            switch(quantidades_lidas)
            {
                case 1:
                    quantidade = atoi(linha);
                    tamanho_alfabeto = quantidade;
                case 2:
                    quantidade = atoi(linha);
                    numero_transicoes = quantidade;
                case 3:
                    strcpy(afd.estado_inicial, linha);
                case 4:
                    quantidade = atoi(linha);
                    numero_finais = quantidade;
            }

            indice = 0;
        }
        else
        {
            if(quantidades_lidas == 0)
            {
                strcpy(afd.estados[indice], linha);
            }
            else if(quantidades_lidas == 1)
            {
                strcpy(afd.alfabeto[indice], linha);
            }
            else if(quantidades_lidas == 2)
            {
                strcpy(afd.transicoes[indice], linha);
            }
            else
            {
                strcpy(afd.estados_finais[indice], linha);
            }

            quantidade--;
            indice++;
        }
    }

    afd.tamanhos[0] = numero_estados;
    afd.tamanhos[1] = tamanho_alfabeto;
    afd.tamanhos[2] = numero_transicoes;
    afd.tamanhos[3] = numero_finais;

    fclose(arquivo);

    printf("\n\n[AFDTOOL] AFD lido!\n");

    printf("\n[AFDTOOL] Numero de estados: %d", numero_estados);
    printf("\n[AFDTOOL] Tamanho do alfabeto: %d", tamanho_alfabeto);
    printf("\n[AFDTOOL] Numero de transicoes: %d", numero_transicoes);
    printf("\n[AFDTOOL] Numero de estados finais: %d\n", numero_finais);

    printf("\n[AFDTOOL] Estados:\n");
    for(int i = 0; i < numero_estados; i++)
        printf("\t  %s", afd.estados[i]);

    printf("\n[AFDTOOL] Alfabeto:\n");
    for(int i = 0; i < tamanho_alfabeto; i++)
        printf("\t  %s", afd.alfabeto[i]);

    printf("\n[AFDTOOL] Transicoes:\n");
    for(int i = 0; i < numero_transicoes; i++)
        printf("\t  %s", afd.transicoes[i]);

    printf("\n[AFDTOOL] Estado Inicial:\n");
    printf("\t  %s", afd.estado_inicial);

    printf("\n[AFDTOOL] Estados Finais:\n");
    for(int i = 0; i < numero_finais; i++)
        printf("\t  %s", afd.estados_finais[i]);

    return afd;
}
