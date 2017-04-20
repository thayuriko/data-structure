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
Cada uma dessas duas listas deverá conter a metade dos elementos da lista original.
Se a quantidade de cartas da lista original for um número ímpar, uma das listas poderá ter um elemento a mais. ( 2,5 pontos)
b. Implementar uma função que, recebendo duas listas duplamente encadeadas, embaralhe essas duas listas.
A lista resultante final deverá ser o retorno da função. (2,5 pontos)

Observação importante: Não é permitido alocar novos elementos, apenas criar referências.
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














