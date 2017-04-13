/*Escreva um programa para gerenciar reservas de passagens de aviсo.
O programa deve mostrar um menu com as seguintes opушes: reservar uma
passagem, cancelar uma passagem, verificar se uma passagem estр reservada
para uma determinada pessoa, e mostrar os passageiros com passagem reservada.
A informaусo deve ser armazenada em uma lista (com os nomes em ordem alfabжtica).
Assuma que cada pessoa pode reservar apenas uma passagem.
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct node{
    char *name;
    struct node *next;
}Node;
 
typedef struct list{
    int count;
    Node *head;
}List;
 
List *startList()
{
    List *newList = (List*)malloc(sizeof(List));
    newList->count = 0;
    newList->head = NULL;
 
    return newList;
}
 
int indexAtListFromName(List *list, char *name, int type)
{
    int index = 0;
 
    if(list->head == NULL){
        return index;
    }
 
    Node *tmp = list->head;
 
    while(tmp != NULL){
        if(strcmp(name, tmp->name) > 0){
            index++;
        }
        if(strcmp(name, tmp->name) == 0){
            return index;
        }
        tmp = tmp->next;
    }
 
    if(type == 1){
        return index;
    } else {
        return 3051993;
    }
}
 
void pushAtIndex(List *list, int index, char *name)
{
    if(list->count < index){
        return;
    }
 
    int i;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->name = malloc(strlen(name)+1);
    strcpy(newNode->name, name);
 
    if(index == 0){
        newNode->next = list->head;
        list->head = newNode;
        list->count++;
 
        printf("Reserva efetuada\n");
        return;
    }
 
    Node *iterator = list->head;
 
    for(i=1;i<index;i++){
        iterator = iterator->next;
    }
 
    newNode->next = iterator->next;
    iterator->next = newNode;
    list->count++;
    printf("Reserva efetuada\n");
}
 
void popAtIndex(List *list, int index)
{
    if((list->count < index)||(list->head == NULL)){
        printf("Nao existe reserva feita neste nome\n");
        return;
    }
 
    Node *tmp = list->head;
 
    if(index == 0){
        list->head = tmp->next;
        list->count--;
        free(tmp);
        printf("Reserva cancelada\n");
 
        return;
    }
 
    int i;
 
    for(i=1; i<index; i++){
        tmp = tmp->next;
    }
    
    Node *deletedNode = tmp->next;
    tmp->next = deletedNode->next;
    list->count--;
    free(deletedNode);
    printf("Reserva cancelada\n");
}
 
void popAll(List *list)
{
    while(list->head != NULL){
        Node *tmp = list->head;
        list->head = tmp->next;
        free(tmp);
        list->count--;
    }
 
    printf("Obrigada por utilizar nosso sistema de reserva de passagens :)\n");
}
 
void readAtIndex(List *list, int index)
{
    if(list->count <= index){
        printf("A passagem nao esta reservada para este passageiro\n");
        return;
    }
 
    int i;
    Node *tmp = list->head;
 
    for(i=0; i<index; i++){
        tmp = tmp->next;
    }
 
    printf("Reserva ja efetuada\n");
}
 
void readAll(List *list)
{
    Node *tmp = list->head;
    int index = 0;
 
    while(tmp != NULL){
        printf("Codigo %d - %s \n", index, tmp->name);
        tmp = tmp->next;
        index++;
    }
    printf("\n");
}
 
int main()
{
    List *list = startList();
    int type, index, value;
    char name[100];
 
    for(;;){
        system("cls");
        printf("\nEscolha uma das opcoes\n1 - Reservar uma passagem;\n2 - Cancelar uma passagem;\n3 - Verificar se uma passagem esta reservada;\n4 - Mostrar os passageiros com passagem reservada;\n5 - Sair;\n\n");
        scanf("%d",&type);
 
        switch(type) {
        case 1:
            printf("\nInforme o nome do passageiro:");
            scanf("%s",name);
            index = indexAtListFromName(list, name, 1);
            pushAtIndex(list, index, name);
            system("pause");
            break;
 
        case 2:
            printf("\nInforme o nome do passageiro:");
            scanf("%s",name);
            index = indexAtListFromName(list, name, 2);
            popAtIndex(list, index);
            system("pause");
            break;
 
        case 3:
            printf("\nInforme o nome do passageiro:");
            scanf("%s",name);
            index = indexAtListFromName(list, name, 2);
            readAtIndex(list, index);
            system("pause");
            break;
 
        case 4:
            if(list->count > 0){
                printf("Estes passageiros estao com a passagem reservada:\n");
                readAll(list);
            }else{
                printf("Nenhum passageiro efetuou uma reserva ainda :( \n");
            }
            system("pause");
            break;
 
        case 5:
            popAll(list);
            return 0;
 
        default:
            printf("Opcao invalida\n");
            system("pause");
            break;
        }
    }
}