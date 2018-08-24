#include "bsearch_tree.h"

int main()
{
    bsnode *root = NULL;

    bs_add(&root, 8);
    bs_add(&root, 4);
    bs_add(&root, 11);
    bs_add(&root, 6);

    if (bs_find(root, 4))
        printf("4 exists\n");
    if (bs_find(root, 8))
        printf("8 exists\n");
    if (bs_find(root, 11))
        printf("11 exists\n");
    if (bs_find(root, 6))
        printf("6 exists\n");
    if (!bs_find(root, 5))
        printf("5 doesnt exist\n");

    bs_print(root);

    bs_destroy(root);
}

void bs_add(bsnode **root, BS_VALUE_TYPE value)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(bsnode));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->value = value;
    }
    else
    {
        if (value < (*root)->value)
            bs_add(&((*root)->left), value);
        else
            bs_add(&((*root)->right), value);
    }
}


void bs_print(bsnode *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->value);
        bs_print(root->left);
        bs_print(root->right);
    }
}


int bs_find(bsnode *root, BS_VALUE_TYPE value)
{
    bsnode *iter = root;
    while (iter != NULL)
    {
        if(value < iter->value)
            iter = iter->left;
        else if (value > iter->value)
            iter = iter->right;
        else
            return 1;
    }

    return 0;
}


void bs_remove(bsnode *root, BS_VALUE_TYPE value)
{
}

void bs_destroy(bsnode *root)
{
    if (root != NULL)
    {
        bs_destroy(root->left);
        bs_destroy(root->right);
        free(root);
    }
}
