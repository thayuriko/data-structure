#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}Node;

typedef struct list{
    Node *root;
}List;

List *initializeTree()
{
    List *list = (Node*)malloc(sizeof(Node));
    list->root = NULL;

    return list;
}

void pop(int valueToBePopped, List *list)
{
    Node *parentNode = searchNode(valueToBePopped, list, list->root);
}

void readAll(Node *currentNode)
{
    if(currentNode){
        readAll(currentNode->left);
        printf("%d ", currentNode->value);
        readAll(currentNode->right);
    }

    return;
}

Node *searchNode(int valueToCompare, List *list, Node *currentNode)
{
    if(currentNode->value > valueToCompare){
        if(currentNode->left == NULL){
            return currentNode;
        }
        searchNode(valueToCompare, list, currentNode->left);
    } else {
        if(currentNode->right == NULL){
            return currentNode;
        }
        searchNode(valueToCompare, list, currentNode->right);
    }
}

void push(int valueToBePushed, List *list)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = valueToBePushed;
    newNode->right = NULL;
    newNode->left = NULL;

    if(list->root == NULL){
        list->root = newNode;
    } else {
        Node *parentNode = searchNode(valueToBePushed, list, list->root);

        if(parentNode->value > valueToBePushed){
            parentNode->left = newNode;
        } else {
            parentNode->right = newNode;
        }
    }
    return;
}

int main()
{
    List *list = initializeTree();

    push(3, list);
    push(2, list);
    push(1, list);
    push(5, list);
    push(4, list);
    push(6, list);

    readAll(list->root);

    return 0;
}
