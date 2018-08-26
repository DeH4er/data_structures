#ifndef STACK_LIST_H
#define STACK_LIST_H

#ifndef STACK_LIST_VALUE_TYPE 
#define STACK_LIST_VALUE_TYPE int
#endif

#define LIST_VALUE_TYPE STACK_LIST_VALUE_TYPE

#include "../linked_list/linked_list.h"

typedef struct list list;

typedef struct
{
    list *list;
} stack_list;

stack_list *stack_list_init();

void stack_list_push(stack_list *s, STACK_LIST_VALUE_TYPE value);
STACK_LIST_VALUE_TYPE stack_list_pop(stack_list *s);
STACK_LIST_VALUE_TYPE stack_list_peek(stack_list *s);

void stack_list_print(stack_list *s);

void stack_list_destroy(stack_list **s);

#endif
