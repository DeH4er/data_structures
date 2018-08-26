#include "bsearch_tree.h"

int main()
{
    bsnode *root = NULL;

    int num = 0;
    /*
    printf("Add vertex:\n");
    while (num != -1)
    {
        scanf("%d", &num);
        bs_add(&root, num);
        printf("\n-----------TREE-----------\n");
        bs_print(root);
        printf("\n");
    }
    */
    int vertexes[] = {100, 9, 3, 99, 150, 127, 101};
    bs_add_v(&root, vertexes, 7);

    bs_print(root);
    
    printf("Delete vertex:\n");
    num = 0;
    while(num != -1)
    {
        scanf("%d", &num);
        bsnode *root_before = root;
        bs_remove(&root, num);
        if (root_before == root)
            printf("fuck");
        printf("\n-----------TREE-----------\n");
        bs_print(root);
        printf("\n");
    }

    bs_destroy(root);
}


void bs_add_v(bsnode **root, BS_VALUE_TYPE vertexes[], int vertexes_size)
{
    for (int i = 0; i < vertexes_size; i++)
        bs_add(root, vertexes[i]);
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
    /*if (root != NULL)
    {
        printf("%d\t", root->value);
        bs_print(root->left);
        bs_print(root->right);
    }
    */
    bs_print_t(root, 0);
}

void bs_print_t(bsnode *root, int level)
{
    if (root != NULL)
    {
        bs_print_t(root->right, level + 1);

        for (int i = 0; i < level; i++)
            printf("\t");
        printf("%d\n", root->value);

        bs_print_t(root->left, level + 1);
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


void bs_remove(bsnode **root, BS_VALUE_TYPE value)
{
    bsnode *iter = *root;
    bsnode *prev_iter = *root;
    bsnode *most_similar;
    bsnode *prev_most_similar;
    while (iter != NULL)
    {
        if (value < iter->value)
        {
            prev_iter = iter;
            iter = iter->left;
        }
        else if (value > iter->value)
        {
            prev_iter = iter;
            iter = iter->right;
        }
        else
        {
            if (iter->right != NULL)
            {
                most_similar = iter->right;

                if (most_similar->left == NULL)
                {
                    if (iter == *root)
                    {
                        most_similar->left = iter->left;
                        *root = most_similar;
                    }
                    else
                    {
                        if (iter->value < prev_iter->value)
                        {
                            prev_iter->left = most_similar;
                            most_similar->left = iter->left;
                        }
                        else
                        {
                            prev_iter->right = most_similar;
                            most_similar->right = iter->right;
                        }
                    }
                } else
                {
                    while(most_similar->left != NULL)
                    {
                        prev_most_similar = most_similar;
                        most_similar = most_similar->left;
                    }

                    if (most_similar->value < prev_most_similar->value)
                    {
                        prev_most_similar->left = most_similar->right;
                    }
                    else
                    {
                        prev_most_similar->right = most_similar->left;
                    }

                    most_similar->left = iter->left;
                    most_similar->right = iter->right;
            else if (iter->left != NULL)
            {
                most_similar = iter->left;

                if (most_similar->right == NULL)
                {
                    if (iter == *root)
                    {
                        most_similar->left = iter->left;
                        *root = most_similar;
                    }
                    else 
                    {
                        if (iter->value < prev_iter->value)
                        {
                            prev_iter->left = most_similar;
                            most_similar->left = iter->left;
                        }
                        else
                        {
                            prev_iter->right = most_similar;
                            most_similar->right = iter->right;
                        }
                    }
                } else
                {
                    while(most_similar->right != NULL)
                    {
                        prev_most_similar = most_similar;
                        most_similar = most_similar->right;
                    }


                    if (most_similar->value < prev_most_similar->value)
                    {
                        prev_most_similar->left = most_similar->right;
                    }
                    else
                    {
                        prev_most_similar->right = most_similar->left;
                    }

                    most_similar->left = iter->left;
                    most_similar->right = iter->right;
                }
            } 
            else
            {
                if (iter->value < prev_iter->value)
                    prev_iter->left = NULL;
                else
                    prev_iter->right = NULL;
            }
            if (iter == *root)
                *root = most_similar;
            iter = NULL;
            free(iter);
        }
    }
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
