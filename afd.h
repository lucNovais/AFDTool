#ifndef AFD_H
#define AFD_H

#define MAX_LINHAS 200
#define MAX_CARACTERES 100

typedef struct afd
{
    char estados[MAX_LINHAS][MAX_CARACTERES];
    char alfabeto[MAX_LINHAS][MAX_CARACTERES];
    char transicoes[MAX_LINHAS][MAX_CARACTERES];
    char estado_inicial[MAX_CARACTERES];
    char estados_finais[MAX_LINHAS][MAX_CARACTERES];
} AFD;

#endif
