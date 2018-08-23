#include "graph.h"
/*
int main()
{
    
    struct list ** linked = create_adj_list(5);

    while(1)
    {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        add_edge_linked(linked, a, b);

        for (int i = 0; i < 5; i++)
        {
            printf("%d\t", i);
            list_print(linked[i]);
            printf("\n");
        }
    }  

    for (int i = 0; i < 5; i++)
        list_destroy(linked[i]);
    free(linked);

}
*/
void print_adj_matrix(int ** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void print_adj_list(struct list **linked, int size)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", i);
        list_print(linked[i]);
        printf("\n");
    }
}


int ** create_adj_matrix(int size)
{
    int ** adj_matrix = (int**) malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++)
        adj_matrix[i] = (int*) malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
        adj_matrix[i][j] = 0;

    return adj_matrix;
}


struct list ** create_adj_list(int size)
{
    struct list ** linked = malloc(sizeof(struct list *) * size);
    for (int i = 0; i < size; i++)
        linked[i] = list_init();

    return linked;
}


void add_edge_matrix(int **adj_matrix, int vertex_a, int vertex_b)
{

        if (adj_matrix[vertex_a][vertex_b] == 0)
        {
            adj_matrix[vertex_a][vertex_b] = 1;
            adj_matrix[vertex_b][vertex_a] = 1;
        }
        else
        {
            adj_matrix[vertex_a][vertex_b] = 0;
            adj_matrix[vertex_b][vertex_a] = 0;
        }

}


void add_edge_linked(struct list ** linked, int vertex_a, int vertex_b)
{
    if (list_find(linked[vertex_a], vertex_b))
    {
        if (list_find(linked[vertex_b], vertex_a))
        {
            return;
        } else 
        {
            list_add_end(linked[vertex_b], vertex_a);
        } 
    } else 
    {
        if (list_find(linked[vertex_b], vertex_a))
        {
            list_add_end(linked[vertex_a], vertex_b);
        }
        else 
        {
            list_add_end(linked[vertex_a], vertex_b);
            list_add_end(linked[vertex_b], vertex_a);

        }
    }
}

