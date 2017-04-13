/*
4 - Crie uma função push para uma pilha que apenas insira o novo valor
caso este seja menor que todos os outros elementos já contidos na mesma.
Não é permitida a criação de iteradores/andarilhos nem percorrer a pilha
com algum outro artifício. (1,0 pontos)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int info;
    struct element *below;
}Element;

typedef struct stack {
    Element *head;
}Stack;

Stack *create()
{
    Stack *created = (Stack*)malloc(sizeof(Stack));
    created->head = NULL;

    return created;
}

void push(Stack *stack, int value)
{
    if(value >= stack->head->info) {
        return;
    }
    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->info = value;
    newElement->below = stack->head;
    stack->head = newElement;
}
