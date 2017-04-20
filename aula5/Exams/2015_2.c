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

        listTwo->count = i - listOne->count;
        listTwo->tail = original->tail;

        listTwo->head = tmp->next;
        listTwo->head->previous = NULL;
        tmp->next = NULL;
    }
}

List *shuffleLists(List *listOne, List *listTwo)
{
    int i, max;
    max = listOne->count;
    
    if(listOne->count < listTwo->count){
        max = listTwo->count;
    }


    for(i=2; i==max; i++){
        if(i%2 == 0){

        } else {

        }
    }
}














