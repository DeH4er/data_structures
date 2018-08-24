#ifndef BSEARCH_TREE_H
#define BSEARCH_TREE_H

#ifndef BS_VALUE_TYPE
#define BS_VALUE_TYPE int
#endif

#include <stdlib.h>
#include <stdio.h>


typedef struct _bsnode 
{
    BS_VALUE_TYPE value;
    struct _bsnode *left;
    struct _bsnode *right;
} bsnode;

void bs_add(bsnode **root, BS_VALUE_TYPE value);
void bs_add_v(bsnode **root, BS_VALUE_TYPE vertexes[], int vertexes_size);

int bs_find(bsnode *root, BS_VALUE_TYPE value);
void bs_remove(bsnode **root, BS_VALUE_TYPE value);

void bs_destroy(bsnode *root);

void bs_print(bsnode *root);
void bs_print_t(bsnode *root, int level);
#endif
