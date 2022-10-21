#ifndef UTILS_H
#define UTILS_H

#include "afd.h"

char **quebra_transicoes(char *transicao);
int *pega_indices_transicao(char **transicao, AFD afd);

#endif
