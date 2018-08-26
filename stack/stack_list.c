#include "stack_list.h"

int main()
{
    stack_list *s = stack_list_init();
    
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


stack_list *stack_list_init()
{
    stack_list *s = malloc(sizeof(stack_list));
    s->list = list_init();
    return s;
}


void stack_list_push(stack_list *s, STACK_LIST_VALUE_TYPE value)
{
    list_add_end(s->list, value);
}


STACK_LIST_VALUE_TYPE stack_list_pop(stack_list *s)
{
    return list_remove_end(s->list);
}


STACK_LIST_VALUE_TYPE stack_list_peek(stack_list *s)
{
    return s->list->last->value;
}


void stack_list_print(stack_list *s)
{
    list_print(s->list);
}


void stack_list_destroy(stack_list **s)
{
    list_destroy((*s)->list);
    free(*s);
    *s = NULL;
}
