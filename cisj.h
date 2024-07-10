/* Sistemas Distribuidos 2024/1
   Autor: Tiago Vargas
   Ultima atualizacao: 14/04/2024
   Funcionalidade:
      Lista os processos contidos em cada cluster. Versao adaptada do programa
      disponibilizado em: https://www.inf.ufpr.br/elias/sisdis/cisj.c.txt
*/

#ifndef CISJ_H
#define CISJ_H

#include <sys/types.h>

#define POW_2(num) (1 << (num))
#define VALID_J(j, s) ((POW_2(s - 1)) >= j)

typedef struct node_set {
    int *nodes;
    ssize_t size;
    ssize_t offset;
} node_set;

node_set *cis(int i, int s);
void set_free(node_set *nodes);

#endif
