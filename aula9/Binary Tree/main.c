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

void readAll(Node *currentNode)
{
    if(currentNode){
        readAll(currentNode->left);
        printf("%d ", currentNode->value);
        readAll(currentNode->right);
    }

    return;
}

Node *searchNode(int valueToCompare, List *list, Node *parentNode, Node *currentNode)
{
    if(currentNode->value > valueToCompare){
        if(currentNode->left == NULL){
            return currentNode;
        }
        searchNode(valueToCompare, list, currentNode, currentNode->left);

    } else if (currentNode->value < valueToCompare){
        if(currentNode->right == NULL){
            return currentNode;
        }
        searchNode(valueToCompare, list, currentNode, currentNode->right);

    } else if(currentNode->value == valueToCompare){
        return parentNode;
    }
}

void pop(int valueToBePopped, List *list)
{
    Node *parentNode = searchNode(valueToBePopped, list, list->root, list->root);
    Node *toBePopped = parentNode;

    if(parentNode->value > valueToBePopped){
        toBePopped = parentNode->left;

        if(toBePopped->left){
            if(toBePopped->right){
                //...
            } else {
                parentNode->left = toBePopped->left;
            }
        } else {
            if(toBePopped->right){
                parentNode->right = toBePopped->right;
            } else {
                parentNode->left = NULL;
            }
        }
    } else if (parentNode->value < valueToBePopped){
        toBePopped = parentNode->right;

        if(toBePopped->right){
            if(toBePopped->left){
                //...
            } else {
                parentNode->right = toBePopped->right;
            }
        } else {
            if(toBePopped->left){
                parentNode->left = toBePopped->left;
            } else {
                parentNode->right = NULL;
            }
        }
    } else if (parentNode->value == valueToBePopped){
        if(toBePopped->left){
            if(toBePopped->right){
                //...
            } else {
                list->root = toBePopped->left;
            }
        } else if (toBePopped->right){
            if(toBePopped->left){
                //...
            } else {
                list->root = toBePopped->right;
            }
        } else {
            list->root = NULL;
        }
    }

    free(toBePopped);
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
        Node *parentNode = searchNode(valueToBePushed, list, list->root, list->root);

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
    printf("\n");

    pop(6, list);

    readAll(list->root);
    printf("\n");

    pop(2, list);
    readAll(list->root);
    printf("\n");

    pop(1, list);
    readAll(list->root);
    printf("\n");

    pop(3, list);
    readAll(list->root);
    return 0;
}
