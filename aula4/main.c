//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node{
//    int val;
//    struct node *next;
//}Node;
//
//typedef struct list{
//    int count;
//    Node *head;
//}List;
//
//List *startList()
//{
//    List *newList = (List*)malloc(sizeof(List));
//    newList->count = 0;
//    newList->head = NULL;
//
//    return newList;
//}
//
//void pushAtIndex(List *list, int index, int value)
//{
//    if(list->count < index){
//        printf("index %d greater than items in the list %d\n", index, list->count);
//        return;
//    }
//
//    int i;
//    Node *newNode = (Node*)malloc(sizeof(Node));
//    newNode->val = value;
//
//    if(index == 0){
//        newNode->next = list->head;
//        list->head = newNode;
//        list->count++;
//
//        printf("new item in the beginning of the list\n");
//
//        return;
//    }
//
//    Node *iterator = list->head;
//
//    for(i=1;i<index;i++){
//        iterator = iterator->next;
//    }
//
//    newNode->next = iterator->next;
//    iterator->next = newNode;
//    list->count++;
//
//    printf("item added successfully\n");
//}
//
//void popAtIndex(List *list, int index)
//{
//    if((list->count < index)||(list->head == NULL)){
//        printf("not possible to pop node");
//        return;
//    }
//
//    Node *deletedNode = list->head;
//
//    if(index == 0){
//        list->head = deletedNode->next;
//        list->count--;
//        free(deletedNode);
//
//        printf("head node popped\n");
//
//        return;
//    }
//
//    int i;
//
//    for(i=1; i<index; i++){
//        deletedNode = deletedNode->next;
//    }
//
//    deletedNode->next = deletedNode->next->next;
//    list->count--;
//    free(deletedNode);
//
//    printf("node at %d popped\n", index);
//}
//
//void popAll(List *list)
//{
//    while(list->head != NULL){
//        Node *tmp = list->head;
//        list->head = tmp->next;
//        free(tmp);
//        list->count--;
//    }
//
//    printf("all nodes popped\n");
//}
//
//void readAtIndex(List *list, int index)
//{
//    if(list->count <= index){
//        printf("could not read at index\n");
//        return;
//    }
//
//    int i;
//    Node *tmp = list->head;
//
//    for(i=0; i<index; i++){
//        tmp = tmp->next;
//    }
//
//    printf("The read value is %d\n", tmp->val);
//}
//
//void readAll(List *list)
//{
//    Node *tmp = list->head;
//
//    while(tmp != NULL){
//        printf("%d | ", tmp->val);
//        tmp = tmp->next;
//    }
//    printf("\n");
//}
//
//int main()
//{
//    List *list = startList();
//    int type, index, value;
//
//    for(;;){
//        system("cls");
//        readAll(list);
//        printf("\nQual?\n1 - Insere;\n2 - Remove 1;\n3 - Ler a posicao;\n4 - Remove tudo;\n\n");
//        scanf("%d",&type);
//
//        switch(type) {
//        case 1:
//            printf("\nForneca o valor:");
//            scanf("%d",&value);
//            printf("\nForneca a posicao:");
//            scanf("%d",&index);
//            pushAtIndex(list, index, value);
//            system("pause");
//            break;
//
//        case 2:
//            printf("\nInforme a posicao:");
//            scanf("%d",&index);
//            popAtIndex(list, index);
//            system("pause");
//            break;
//
//        case 3:
//            printf("\nInforme a posicao:");
//            scanf("%d",&index);
//            readAtIndex(list, index);
//            system("pause");
//            break;
//
//        case 4:
//            popAll(list);
//            system("pause");
//            break;
//
//        default:
//            printf("Opcao invalida\n");
//            system("pause");
//            break;
//        }
//    }
//}
