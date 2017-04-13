/*
4 - Crie uma fun��o push para uma pilha que apenas insira o novo valor
caso este seja menor que todos os outros elementos j� contidos na mesma.
N�o � permitida a cria��o de iteradores/andarilhos nem percorrer a pilha
com algum outro artif�cio. (1,0 pontos)
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
