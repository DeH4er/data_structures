/*
 * WARNING:
 * If you change LIST_VALUE_TYPE, you should change format in list_print function too
 */

#include "linked_list.h"

/*
int main()
{
    struct list *linked_list = list_init();

    for (int i = 0; i < 10; i++)
        list_add_end(linked_list, i);
    
    list_print(linked_list);
    printf("%d\n", list_remove(linked_list, 0));
    printf("%d\n", list_remove(linked_list, 8));
    printf("%d\n", list_remove(linked_list, 5));
    printf("%d\n", list_remove(linked_list, 5));

    while (linked_list->length != 0)
        printf("%d\n", list_remove_end(linked_list));

    list_destroy(linked_list);
}
*/

void list_add_start(struct list *linked_list, LIST_VALUE_TYPE value)
{
    struct list_node *new_node = malloc(sizeof(struct list_node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (linked_list->first == NULL)
    {
        linked_list->first = linked_list->last = new_node;
    } else
    {
        linked_list->first->prev = new_node;
        new_node->next = linked_list->first;
        linked_list->first = new_node;
    }

    (linked_list->length)++;
}


void list_add_end(struct list *linked_list, LIST_VALUE_TYPE value)
{
    struct list_node *new_node = malloc(sizeof(struct list_node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (linked_list->first == NULL)
    {
        linked_list->first = linked_list->last = new_node;
    } else 
    {
        linked_list->last->next = new_node;
        new_node->prev = linked_list->last;
        linked_list->last = new_node;
    }
   
    (linked_list->length)++;
}


void list_add(struct list *linked_list, unsigned int position, LIST_VALUE_TYPE value)
{
    if (position == 0)
        list_add_start(linked_list, value);
    else if (position == linked_list->length)
        list_add_end(linked_list, value);
    else if (position > linked_list->length)
        return;
    else 
    {
        struct list_node *new_node = malloc(sizeof(struct list_node));
        struct list_node *iter = linked_list->first;

        for (int i = 0; i < position; i++)
            iter = iter->next;

        iter->next = new_node;
        new_node->prev = iter;

        iter->next = new_node;
        new_node->next = iter->next;

        (linked_list->length)++;
    }
}



LIST_VALUE_TYPE list_remove_start(struct list *linked_list)
{
    if (linked_list->first == NULL)
        return 0;
    else 
    {
        LIST_VALUE_TYPE value = linked_list->first->value;
        
        if (linked_list->first == linked_list->last)
        {
            free(linked_list->first);
            linked_list->first = linked_list->last = NULL;
        } else 
        {
            linked_list->first = linked_list->first->next;  
            free(linked_list->first->prev);
            linked_list->first->prev = NULL;
        }
        
        (linked_list->length)--;

        return value;
    }
}


LIST_VALUE_TYPE list_remove_end(struct list *linked_list)
{
    if (linked_list->first == NULL)
        return 0;
    else
    {
        LIST_VALUE_TYPE value = linked_list->last->value;

        if (linked_list->first == linked_list->last)
        {
            free(linked_list->first);
            linked_list->first = linked_list->last = NULL;
        } else 
        {
            linked_list->last = linked_list->last->prev;
            free(linked_list->last->next);
            linked_list->last->next = NULL;
        }

        (linked_list->length)--;

        return value;
    }
}


LIST_VALUE_TYPE list_remove(struct list *linked_list, unsigned int position)
{
    if (position == 0)
        return list_remove_start(linked_list);
    else if (position == linked_list->length - 1)
        return list_remove_end(linked_list);
    else if (position >= linked_list->length)
        return 0;
    else 
    {
        struct list_node *iter = linked_list->first;

        for (int i = 0; i < position; i++)
            iter = iter->next;
        
        LIST_VALUE_TYPE value = iter->value; 
        
        struct list_node *f = iter->prev;
        struct list_node *s = iter->next;
        f->next = s;
        s->prev = f;
        free(iter);

        (linked_list->length)--;
        return value;
    }

    
}


struct list *list_init()
{

    struct list *linked_list = malloc(sizeof(struct list));
    linked_list->first = NULL;
    linked_list->last = NULL;
    linked_list->length = 0;
    return linked_list;
}


void list_destroy(struct list *linked_list)
{
    while (linked_list->first != NULL)
        list_remove_start(linked_list);
    
    free(linked_list);
}


void list_print(struct list *linked_list)
{
    struct list_node *iter = linked_list->first;
    while (iter != NULL)
    {
        printf("%d\t", iter->value);
        iter = iter->next;
    }
}

int list_find(struct list *linked_list, LIST_VALUE_TYPE value)
{
    struct list_node *iter = linked_list->first;
    while (iter != NULL)
    {
        if (iter->value == value)
            return 1;
        iter = iter->next;
    }
    return 0;
}
