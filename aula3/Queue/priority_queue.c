/*
Escreva um programa para organizar a fila de um banco.
Nesta fila, as pessoas com mais de 60 anos, grбvidas e portadoras de necessidades especiais devem ser atendidas antes.
Ao final do processo, imprima a fila na ordem correta
(Dica: utilize no seu programa duas filas para a implementaзгo)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int info;
    struct element *next;
} Element;

typedef struct queue {
    Element *front;
    Element *rear;
    Element *rearP;
} Queue;

Queue *create()
{
    Queue *created = (Queue*)malloc(sizeof(Queue));
    created->front = NULL;
    created->rear = NULL;
    created->rearP = NULL;

    return created;
}

void enqueue(int value, Queue *queue, int isPriority)
{
    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->next = NULL;
    newElement->info = value;

    if(queue->front == NULL){ //Se a fila estiver vazia
        queue->front = newElement;
        queue->rear = newElement;

        if(isPriority == 1){ //Se o novo elemento tiver prioridade
            queue->rearP = newElement;
        }
    } else { //Se o novo elemento tiver prioridade
        if(isPriority == 1){ //Se não tiver nenhum outro elemento com prioridade na fila
            if(queue->rearP == NULL){
                newElement->next = queue->front;
                queue->front = newElement;
                queue->rearP = newElement;
            } else {
                if(queue->rearP == queue->rear){ //Se só tiver elemento com prioridade na fila
                    queue->rearP->next = newElement;
                    queue->rearP = newElement;
                    queue->rear = newElement;
                } else { //Tem elemento com prioridade e sem prioridade
                    newElement->next = queue->rearP->next;
                    queue->rearP->next = newElement;
                    queue->rearP = newElement;
                }
            }
        } else {
            queue->rear->next = newElement;
            queue->rear = newElement;
        }
    }
}

int dequeue(Queue *queue)
{
    int popped;

    if(queue->front == NULL){
        return 351993;
    }

    Element *temp = queue->front;
    if(queue->front == queue->rearP){
        queue->rearP = NULL;
    }

    queue->front = temp->next;
    popped = temp->info;
    free(temp);

    return popped;
}

void read(Queue *queue)
{
    Element *iterator = queue->front;

    while(iterator != NULL){
        printf(" %d |", iterator->info);
        iterator = iterator->next;
    }
}

int main()
{
    int type, value;
    Queue *queue = create();

    for(;;){
        system("cls");
        read(queue);
        printf("\nQual o tipo de atendimento?\n1 - Preferencial;\n2 - Nao-preferencial;\n3 - Atender;\n\n");
        scanf("%d",&type);

        switch(type) {
        case 1:
            printf("\nForneca a senha:");
            scanf("%d",&value);
            enqueue(value, queue, 1);
            system("pause");
            break;

        case 2:
            printf("\nForneca a senha:");
            scanf("%d",&value);
            enqueue(value, queue, 0);
            system("pause");
            break;

        case 3:
            value = dequeue(queue);
            if(value == 351993) {
                printf("\nNao tem ninguem na fila\n", value);
            } else {
                printf("\nA senha %d saiu da fila\n", value);
            }
            system("pause");
            break;

        default:
            printf("Opcao invalida\n");
            system("pause");
            break;
        }
    }
    return 0;
}
