#include <stdio.h>
#include <stdlib.h>
 
typedef struct element {
    int info;
    struct element *next;
} Element;
  
Element *create()
{
    Element *head = (Element *)malloc(sizeof(Element));
    head->next = NULL;
    head->info = 0;
 
    return head;
}
 
void push(int value, Element *head)
{
    Element *newElement;
    newElement = (Element *)malloc(sizeof(Element));
    newElement->next = head->next;
    newElement->info = value;
    head->next = newElement;
}
 
void pop(Element *head)
{
    if (head->next == NULL) {
        return;
    }

    Element *temp = head->next;
    head->next = temp->next;
    free(temp);
}
 
void read(Element *head)
{
    Element *i = head->next;
    while (i != NULL) {
        printf("\n%i", i->info);
        i = i->next;
    }
}
 
void menu(char *choice, Element *head)
{
    int value = 0;
    printf("\n\nEscolha qual acao realizar:\n1 - Inserir 1 elemento no topo;\n2 - Remover o elemento do topo;\n3 - Imprimir a ordem dos elementos;\n4 - Sair\n");
    scanf("%c", choice);
  
    switch(*choice)
    {
    case '+':
        printf("Insira o valor:\n");
        scanf("%d", &value);
        push(value, head);
        read(head);
        break;
    case 2:
        pop(head);
        break;
    case 3:
        read(head);
        break;
    case 's':
        break;
    default:
        printf("Opcao invalida\n\n");
        break;
    }
}
 
int main()
{
    Element *head = create();
    char choice;
 
    while(choice != 's')
    {
        menu(&choice, head);
    }
 
    return 0;
}
