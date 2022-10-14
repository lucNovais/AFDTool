#ifndef AFD_H
#define AFD_H

#define MAX_LINHAS 200
#define MAX_CARACTERES 100

/*
 * Estrutura de dados utilizada para representar os AFDs
 * -----------------------------------------------------
 * 
 * `estados` (char[][]): vetor que representa quais os estados do AFD
 * `alfabeto` (char[][]): vetor que representa quais os símbolos do alfabeto do AFD
 * `transicoes` (char[][]): vetor que representa quais as transicoes no formato '{estado} {simbolo} {estado}'
 * `estado_inicial` (char[]): string que representa qual o estado inicial do AFD
 * `estados_finais` (char[][]): vetor que representa quais os estados finais do AFD 
 * `tamanhos` (int[]): vetor de inteiros que contem os tamanhos de cada um dos vetores acima
 *      0 -> tamanho estados
 *      1 -> tamanho alfabeto
 *      2 -> tamanho transicoes
 *      3 -> tamanho finais
 */
typedef struct afd
{
    char estados[MAX_LINHAS][MAX_CARACTERES];
    char alfabeto[MAX_LINHAS][MAX_CARACTERES];
    char transicoes[MAX_LINHAS][MAX_CARACTERES];
    char estado_inicial[MAX_CARACTERES];
    char estados_finais[MAX_LINHAS][MAX_CARACTERES];
    int tamanhos[4];
} AFD;

#endif
