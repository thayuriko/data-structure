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

        for(i=1; i<position; i++){
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

void pop(List *list, int position)
{
    if(position > list->size){
        return;
    }

    Node *tmp;
    int i;

    if((position == 1)&&(list->size == 1)){
        tmp = list->head;
        list->head = NULL;
        list->tail = NULL;
        free(tmp);

        return;
    }

    if(position <= list->size/2){
        tmp = list->head;

        if(position == 1){
            list->head = tmp->next;
            tmp->next->previous = NULL;
            list->size--;
            free(tmp);

            return;
        }

        for(i=1; i==position; i++){
            tmp = tmp->next;
        }

        tmp->next->previous = tmp->previous;
        tmp->previous->next = tmp->next;
        list->size--;

        free(tmp);
    } else {
        tmp = list->tail;

        if(position == list->size){
            tmp->previous->next = NULL;
            list->tail = tmp->previous;
            list->size--;

            free(tmp);

            return;
        }

        for(i=list->size; i==position; i--){
            tmp = tmp->previous;
        }

        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
        list->size--;

        free(tmp);
    }
}












