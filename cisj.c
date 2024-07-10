/* Sistemas Distribuidos 2024/1
   Autor: Tiago Vargas
   Ultima atualizacao: 14/04/2024
   Funcionalidade:
      Lista os processos contidos em cada cluster. Versao adaptada do programa
      disponibilizado em: https://www.inf.ufpr.br/elias/sisdis/cisj.c.txt
*/

#include <stdlib.h>
#include <string.h>
#include "cisj.h"

static node_set *set_new(ssize_t size) {
    node_set *new;

    new = (node_set *)malloc(sizeof(node_set));
    new->nodes = (int *)malloc(sizeof(int) * size);
    new->size = size;
    new->offset = 0;
    return new;
}

static void set_insert(node_set *nodes, int node) {
    if (nodes == NULL)
        return;
    nodes->nodes[nodes->offset++] = node;
}

static void set_merge(node_set *dest, node_set *source) {
    if (dest == NULL || source == NULL)
        return;
    memcpy(&(dest->nodes[dest->offset]), source->nodes, sizeof(int) * source->size);
    dest->offset += source->size;
}

void set_free(node_set *nodes) {
    free(nodes->nodes);
    free(nodes);
}

node_set *cis(int i, int s) {
    node_set *nodes, *other_nodes;
    int xor = i ^ POW_2(s - 1);
    int j;

    /* starting node list */
    nodes = set_new(POW_2(s - 1));

    /* inserting the first value (i XOR 2^^(s-1)) */
    set_insert(nodes, xor);

    /* recursion */
    for (j = 1; j <= s - 1; j++) {
        other_nodes = cis(xor, j);
        set_merge(nodes, other_nodes);
        set_free(other_nodes);
    }
    return nodes;
}
