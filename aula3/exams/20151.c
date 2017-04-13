/*
Implemente um gerenciador de chamadas para atendimento em caixas de banco.
O sistema deve ter um método novoCliente(String nome) e novoClientePreferencial(String nome),
que sinalizam a chegada de um novo cliente ao banco. Além disso, um método String
proximoAtendimento(), que retorna o nome do próximo cliente a ser atendido. A cada três
chamadas, uma deve ser de cliente preferencial (se houver algum na espera).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    char *name;
    struct element *next;
}Element;

typedef struct queue {
    Element *front;
    Element *rear;
}Queue;

Queue *inicializaFila()
{
    Queue *created = (Queue*)malloc(sizeof(Queue));
    created->front = NULL;
    created->rear = NULL;

    return created;
}

void novoCliente(char *nome, Queue *fila)
{
    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->name = strdup(nome);
    newElement->next = NULL;

    if(fila->front == NULL) {
        fila->front = newElement;
    } else {
        fila->rear->next = newElement;
    }

    fila->rear = newElement;
}

void novoClientePreferencial(char *nome, Queue *fila)
{
    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->name = strdup(nome);
    newElement->next = NULL;

    if(fila->front == NULL) {
        fila->front = newElement;
    } else {
        fila->rear->next = newElement;
    }

    fila->rear = newElement;
}

char *proximoAtendimento(Queue *fila)
{
    Element *temp = fila->front;
    char *proxNome = temp->name;

    fila->front = temp->next;

    if(temp->next == NULL) {
        fila->rear = NULL;
    }

    return proxNome;
}

int main()
{
    Queue *fila = inicializaFila();
    Queue *filaP = inicializaFila();

    int clientesAtendidos = 0;
    char nome[100];
    int type;

    for(;;) {
        printf("1 - Preferencial;\n2 - Nao-preferencial\n3 - Atender proximo;\n\n");
        scanf("%d", &type);
        switch(type) {
        case 1:
            clientesAtendidos++;
            printf("Forneca o nome\n");
            scanf("%s", &nome);
            novoClientePreferencial(nome, filaP);
            break;
        case 2:
            clientesAtendidos++;
            printf("Forneca o nome\n");
            scanf("%s", &nome);
            novoCliente(nome, fila);
            break;
        case 3:
            if(clientesAtendidos%3 == 0) {
                nome = proximoAtendimento(filaP);
            } else {
                nome = proximoAtendimento(fila);
            }
            printf("%s saiu da fila", nome);
            break;
        default:
            printf("invalido");
            break;
        }
    }
}
