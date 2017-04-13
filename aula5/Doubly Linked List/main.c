#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *previous;
    struct node *next;
}Node;

typedef struct list{
    int size;
    Node *head;
    Node *tail;
}List;

List *startList()
{
    List *newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;

    return newList;
}

void push(List *list, int position, int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;

    if(list->size == 0){
        newNode->next = NULL;
        newNode->previous = NULL;
        list->tail = newNode;
        list->head = newNode;
        list->size++;

        return;
    }

    int i;
    Node *tmp;

    if(list->size/2 >= position){
        tmp = list->head;

        if(position == 1){
            newNode->next = tmp;
            newNode->previous = NULL;
            tmp->previous = newNode;
            list->head = newNode;
            list->size++;

            return;
        }

        for(i=0; i<position; i++){
            tmp = tmp->next;
        }

        newNode->next = tmp->next;
        newNode->previous = tmp;
        tmp->next->previous = newNode;
        tmp->next = newNode;
        list->size++;

        return;
    } else {
        tmp = list->tail;

        if(position == list->size){
            newNode->previous = tmp;
            newNode->next = NULL;
            tmp->next = newNode;
            list->tail = newNode;
            list->size++;

            return;
        }

        for(i=list->size; i==position; i--){
            tmp = tmp->previous;
        }

        newNode->previous = tmp->previous;
        newNode->next = tmp;
        tmp->previous->next = newNode;
        tmp->previous = newNode;

        list->size++;

        return;
    }
}














