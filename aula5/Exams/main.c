/*
1) Implemente uma função para:
a) reverter uma lista duplamente encadeada. Assuma que a lista possui um ponteiro para o primeiro e para o último elemento. (​1,0 ponto)
b) reverter uma lista simplesmente encadeada. Assuma que a lista apenas possui um ponteiro para o primeiro elemento. (​1,0 ponto)
Nesta questão, deve­se trabalhar com a memória já alocada (a criação de novos elementos não é permitida).
*/

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

void reverseDoublyLinked(List *list)
{
    Node *tmp = list->head;
    Node *reversingList = list->tail;
    while(tmp != NULL){
        reversingList = tmp;
        tmp = tmp->next;
        reversingList = reversingList->previous;
    }
    tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}

void reverseSinglyLinked(List *list)
{
}




/*
2) Implemente uma função que remova os elementos duplicados de uma lista simplesmente encadeada. (​2,0 pontos)
*/

void removeDuplicates(List *list)
{
    int duplicate;
    int position = 1;
    Node *tmp = list->head;
    Node *aux = list->head;

    while(tmp != NULL){
        duplicate = tmp->value;

        while(aux != NULL){
            if(duplicate == aux->next->value){
                popAtIndex(list, position + 1);
                aux = aux->next;
                position++;
            } else {
                aux = aux->next;
                position++;
            }
        }

        tmp = tmp->next;
    }
}

/*
5) Implemente o método “insere(int valor)” de uma lista duplamente encadeada ORDENADA.
Para manter a ordem da lista coerente, este método deve inserir o novo elemento na posição correta. (​2,0 pontos)
*/

void insere(List *list, int valor)
{
    int position = 1;
    Node *newNode = (Node*)malloc(sizeof(Node));
    tmp = list->head;

    while(tmp != NULL){
        if(valor > tmp->value){
            position++;
            tmp = tmp->next;
        } else {
            newNode->value = valor;
            newNode->next = tmp->next;
            newNode->previous = tmp;
            tmp->next->previous = newNode;
            tmp->next = newNode;

            if(position == 1){
                list->head = newNode;
            } else if(position == list->count){
                list->tail = newNode;
            }

            return;
        }
    }

}
