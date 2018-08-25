#ifndef STACK_LIST_H
#define STACK_LIST_H

#define STACK_VALUE_TYPE int
#define LIST_VALUE_TYPE STACK_VALUE_TYPE

#include "../linked_list/linked_list.h"

typedef struct list list;

typedef struct _stack
{
    list *list;
} stack;

stack *stack_init();

void stack_list_push(stack *s, STACK_VALUE_TYPE value);
STACK_VALUE_TYPE stack_list_pop(stack *s);
STACK_VALUE_TYPE stack_list_peek(stack *s);

void stack_list_print(stack *s);

void stack_list_destroy(stack **s);

#endif
