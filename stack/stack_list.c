#include "stack_list.h"

int main()
{
    stack *s = stack_init();
    
    for (int i = 0; i < 10; i++)
        stack_list_push(s, i);

    stack_list_print(s);
    printf("\n");

    for (int i = 0; i < 5; i++)
        printf("%d\t", stack_list_pop(s));

    printf("----------\n");
    stack_list_print(s);

    stack_list_destroy(&s);

}


stack *stack_init()
{
    stack *s = malloc(sizeof(stack));
    s->list = list_init();
    return s;
}


void stack_list_push(stack *s, STACK_VALUE_TYPE value)
{
    list_add_end(s->list, value);
}


STACK_VALUE_TYPE stack_list_pop(stack *s)
{
    return list_remove_end(s->list);
}


STACK_VALUE_TYPE stack_list_peek(stack *s)
{
    return s->list->last->value;
}


void stack_list_print(stack *s)
{
    list_print(s->list);
}


void stack_list_destroy(stack **s)
{
    list_destroy((*s)->list);
    free(*s);
    *s = NULL;
}
