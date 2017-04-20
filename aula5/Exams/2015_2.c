#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
    struct node *previous;
}Node;

typedef struct list{
    int count;
    Node *head;
    Node *tail;
}List;

/*
a. Implementar um algoritmo que divida uma lista duplamente encadeada em duas listas.
Cada uma dessas duas listas dever� conter a metade dos elementos da lista original.
Se a quantidade de cartas da lista original for um n�mero �mpar, uma das listas poder� ter um elemento a mais. ( 2,5 pontos)
b. Implementar uma fun��o que, recebendo duas listas duplamente encadeadas, embaralhe essas duas listas.
A lista resultante final dever� ser o retorno da fun��o. (2,5 pontos)

Observa��o importante: N�o � permitido alocar novos elementos, apenas criar refer�ncias.
*/

void popAllFromTailOn(List *list)
{
    Node *tmp = list->tail;

}

void splitTheList(List *original)
{
    List *listOne = original;
    List *listTwo = original;
    Node *tmp = original->head;
    int i = 1;

    listOne->head = tmp;
    listOne->head->previous = NULL;
    while(tmp != NULL){

        while(i < original->count/2){
            tmp = tmp->next;
            i++;
        }
        listOne->count = i;
        listOne->tail = tmp;
        listOne->tail->next = NULL;

        tmp = tmp->next;
        listTwo->head = tmp;
        listTwo->head->previous = NULL;

        while(i != original->count){
            tmp = tmp->next;
            i++;
        }
        listTwo->count = i - listOne->count;
        listTwo->tail = tmp;
        listTwo->tail->next = NULL;
    }
    popAllFromTailOn(listOne);
    popAllFromTailOn(listTwo);
}

List *shuffleLists(List *listOne, List *listTwo)
{

}






