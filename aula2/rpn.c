#include <stdio.h>
#include <stdlib.h>
 
typedef struct element {
    int info;
    struct element *next;
} Element;

typedef struct pilha {
	Element *head;
} Stack;
  
Stack *create()
{
    Stack *result = (Stack *) malloc(sizeof(Stack));
 	result->head = NULL;
    
    return result;
}
 
void push(int value, Stack *stack)
{
    Element *newElement;
    newElement = (Element *) malloc(sizeof(Element));
    newElement->info = value;
    newElement->next = stack->head;
    stack->head = newElement;
}
 
int pop(Stack *stack)
{
	int out = 0;
    if (stack->head == NULL) {
    	return 0;
    }

    Element *head = stack->head;
    out = head->info;
    stack->head = head->next;
    free(head);

    return out;
}
 
void read(Stack *stack)
{
    Element *i = stack->head;
    while (i != NULL) {
        printf("\n%i", i->info);
        i = i->next;
    }
}
 
void menu(int choice, Stack *stack)
{
    int value = 0;
    printf("\n\nEscolha qual acao realizar:\n1 - Inserir 1 elemento no topo;\n2 - Remover o elemento do topo;\n3 - Imprimir a ordem dos elementos;\n4 - Sair\n");
    scanf("%d", &choice);
  
    switch(choice)
    {
    case 1:
        printf("Insira o valor:\n");
        scanf("%d", &value);
        push(value, stack);
        break;
    case 2:
        value = pop(stack);
        printf("o valor removido foi %d", value);
        break;
    case 3:
        read(stack);
        break;
    case 4:
        break;
    default:
        printf("Opcao invalida\n\n");
        break;
    }
}
 
int main()
{
    Stack *stack = create();
    int choice = 0;
 
    while(choice != 4)
    {
        menu(choice, stack);
    }
 
    return 0;
}
