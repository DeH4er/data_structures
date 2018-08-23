/*
 * WARNING:
 * If you change LIST_VALUE_TYPE, you should change format in list_print function too
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdlib.h>
#include <stdio.h>

#ifndef LIST_VALUE_TYPE
#define LIST_VALUE_TYPE int
#endif

struct list_node
{
    LIST_VALUE_TYPE value;                 
    struct list_node *next;
    struct list_node *prev;
};

struct list
{
    struct list_node *first;
    struct list_node *last;
    unsigned int length;
};

void list_add_start(struct list *linked_list, LIST_VALUE_TYPE value);
void list_add_end(struct list *linked_list, LIST_VALUE_TYPE value);
void list_add(struct list *linked_list, unsigned int position, LIST_VALUE_TYPE value);


LIST_VALUE_TYPE list_remove_start(struct list *linked_list);
LIST_VALUE_TYPE list_remove_end(struct list *linked_list);
LIST_VALUE_TYPE list_remove(struct list *linked_list, unsigned int position);

struct list *list_init();
void list_destroy(struct list *linked_list);
void list_print(struct list *linked_list);

int list_find(struct list *linked_list, LIST_VALUE_TYPE value);

#endif
