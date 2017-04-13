#include <stdio.h>
#include <stdlib.h>
 
typedef struct element {
    float info;
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
 
void push(float value, Stack *stack)
{
    Element *newElement;
    newElement = (Element *) malloc(sizeof(Element));
    newElement->info = value;
    newElement->next = stack->head;
    stack->head = newElement;
}
 
float pop(Stack *stack)
{
    float out = 0;
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
    system("clear");
    printf("Press 's' to exit...\n\n");
    Element *i = stack->head;
    while (i != NULL) {
        printf("%.2f\n", i->info);
        i = i->next;
    }
}
 
void menu(char *choice, Stack *stack)
{
    float value1, value2, value = 0.0;
    scanf("%c", choice);
  
    switch(*choice)
    {
    case '+':
        pop(stack);
        value1 = pop(stack);
        value2 = pop(stack);
        value = value1 + value2;
        
        push(value, stack);
        read(stack);
        break;
    case '-':
        pop(stack);
        value1 = pop(stack);
        value2 = pop(stack);
        value = value1 - value2;
        
        push(value, stack);
        read(stack);
        break;
    case '/':
        pop(stack);
        value1 = pop(stack);
        value2 = pop(stack);
        value = value1/value2;
        
        push(value, stack);
        read(stack);
        break;
    case '*':
        pop(stack);
        value1 = pop(stack);
        value2 = pop(stack);
        value = value1*value2;
        
        push(value, stack);
        read(stack);
        break;
    default:
        scanf("%f", &value);
        push(value, stack);
        read(stack);
        break;
    }
}
 
int main()
{
    Stack *stack = create();
    char choice;
 
    printf("Press 's' to exit...\n");
    while(choice != 's')
    {
        menu(&choice, stack);
    }
 
    return 0;
}
