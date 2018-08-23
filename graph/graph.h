#ifndef GRAPH_H
#define GRAPH_H


#include <stdlib.h>
#include <stdio.h>

#include "../linked_list/linked_list.h"

int ** create_adj_matrix(int size);
struct list ** create_adj_list(int size);

void add_edge_matrix(int **adj_matrix, int vertex_a, int vertex_b);
void add_edge_linked(struct list ** linked, int vertex_a, int vertex_b);

void print_adj_matrix(int ** matrix, int size);
void print_adj_list(struct list **linked, int size);

#endif
