///*
//Implementar um deque (do inglês double-ended queue). Nesta estrutura de dados,
//os elementos podem ser inseridos e retirados ou no fim ou no começo da lista.
//Obs: escrever 4 funções: inserir no início, inserir no fim, retirar do início, retirar do fim.
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node{
//    int value;
//    struct node *previous;
//    struct node *next;
//}Node;
//
//typedef struct list{
//    int size;
//    Node *head;
//    Node *tail;
//}List;
//
//List *startList()
//{
//    List newList = (List)malloc(sizeof(List));
//    newList->head = NULL;
//    newList->tail = NULL;
//    newList->size = 0;
//
//    return newList;
//}
//
//void pushAtStart(List *list, int value)
//{
//    Node newNode = (Node)malloc(sizeof(Node));
//    newNode->value = value;
//
//    if(list->size == 0){
//        newNode->next = NULL;
//        newNode->previous = NULL;
//        list->tail = newNode;
//        list->head = newNode;
//        list->size++;
//
//        return;
//    }
//
//    Node *tmp = list->head;
//    newNode->next = tmp;
//    newNode->previous = NULL;
//    tmp->previous = newNode;
//    list->head = newNode;
//    list->size++;
//}
//
//void pushAtEnd(List *list, int value)
//{
//    Node newNode = (Node)malloc(sizeof(Node));
//    newNode->value = value;
//
//    if(list->head == NULL){
//        newNode->next = NULL;
//        newNode->previous = NULL;
//        list->tail = newNode;
//        list->head = newNode;
//        list->size++;
//
//        return;
//    }
//
//    Node *tmp = list->tail;
//    newNode->previous = tmp;
//    newNode->next = NULL;
//    tmp->next = newNode;
//    list->tail = newNode;
//    list->size++;
//}
//
//int popAtStart(List *list)
//{
//    Node *tmp = list->head;
//    int returnedValue = tmp->value;
//
//    if(list->size == 1){
//        list->head = NULL;
//        list->tail = NULL;
//        list->size--;
//        free(tmp);
//
//        return returnedValue;
//    }
//
//    list->head = tmp->next;
//    tmp->next->previous = NULL;
//    list->size--;
//    free(tmp);
//
//    return returnedValue;
//}
//
//int popAtEnd(List *list)
//{
//    Node *tmp = list->tail;
//    int returnedValue = tmp->value;
//
//    if(list->size == 1){
//        list->head = NULL;
//        list->tail = NULL;
//        list->size--;
//        free(tmp);
//
//        return returnedValue;
//    }
//
//    returnedValue = tmp->value;
//    list->tail = tmp->previous;
//    tmp->previous->next = NULL;
//    list->size--;
//    free(tmp);
//
//    return returnedValue;
//}
//
//void readAll(List *list)
//{
//    Node *tmp = list->head;
//
//    while(tmp != NULL){
//        printf("%d | ", tmp->value);
//        tmp = tmp->next;
//    }
//}
//
//int main()
//{
//    List *list = startList();
//    int choice, value;
//
//    for(;;){
//        system("clear");
//        readAll(list);
//        printf("\n");
//        printf("\nEscolha uma das opcoes:\n1 - Inserir elemento no inicio da fila;\n2 - Inserir elemento no fim da fila;\n3 - Remover do inicio;\n4 - Remover do fim;\n\n");
//        scanf("%d", &choice);
//        switch(choice){
//            case 1:
//                printf("Informe o valor a ser inserido: ");
//                scanf("%d", &value);
//                pushAtStart(list, value);
//                system("pause");
//                break;
//            case 2:
//                printf("Informe o valor a ser inserido: ");
//                scanf("%d", &value);
//                pushAtEnd(list, value);
//                system("pause");
//                break;
//            case 3:
//                if(list->head == NULL){
//                    printf("Nao foi possivel remover o elemento\n");
//                    system("pause");
//                    break;
//                }
//                printf("O valor removido foi de %d\n", popAtStart(list));
//                system("pause");
//                break;
//            case 4:
//                if(list->head == NULL){
//                    printf("Nao foi possivel remover o elemento\n");
//                    system("pause");
//                    break;
//                }
//                printf("O valor removido foi de %d\n", popAtEnd(list));
//                system("pause");
//                break;
//            default:
//                printf("opcao invalida");
//                break;
//        }
//    }
//
//    return 0;
//}
