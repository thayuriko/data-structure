#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int info;
    struct element *next;
} Element;

typedef struct queue {
    Element *front;
    Element *rear;
} Queue;

Queue *create()
{
    Queue *created = (Queue*)malloc(sizeof(Queue));
    created->front = NULL;
    created->rear = NULL;

    return created;
}

void push(int value, Queue *queue)
{
    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->next = NULL;
    newElement->info = value;

    if(queue->front == NULL) {
        queue->front = newElement;
    } else {
        queue->rear->next = newElement;
    }

    queue->rear = newElement;
}

int pop(Queue *queue)
{
    int popped;

    if(queue->front == NULL){
        return 0;
    }

    Element *temp = queue->front;
    queue->front = temp->next;
    popped = temp->info;
    free(temp);

    return popped;
}

void read(Queue *queue)
{
    Element *iterator = queue->front;

    while(iterator != NULL){
        printf("%d\n", iterator->info);
        iterator = iterator->next;
    }
}

int main()
{
    int choice, value;
    Queue *queue = create();

    while(choice != 4){
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Insert a value\n");
            scanf("%d",&value);
            push(value, queue);
            break;
        case 2:
            value = pop(queue);
            printf("%d popped\n", value);
            break;
        case 3:
            read(queue);
            break;
        default:
            return 0;
            break;
        }
    }
    return 0;
}
