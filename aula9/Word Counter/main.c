#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *textFile;

typedef struct node{
    char word[1024];
    int freq;
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
        printf("%s(%d) ", currentNode->word, currentNode->freq);
        readAll(currentNode->right);
    }

    return;
}

Node *searchNode(char valueToCompare[], List *list, Node *currentNode)
{
    int result = strcmp(valueToCompare, currentNode->word);
    if(result < 0) {
        if(currentNode->left == NULL){
            return currentNode;
        }
        searchNode(valueToCompare, list, currentNode->left);

    } else if (result > 0) {
        if(currentNode->right == NULL){
            return currentNode;
        }
        searchNode(valueToCompare, list, currentNode->right);
    } else {
        return currentNode;
    }
}

void push(char valueToBePushed[], List *list)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, valueToBePushed);
    newNode->freq = 1;
    newNode->right = NULL;
    newNode->left = NULL;

    if(list->root == NULL){
        list->root = newNode;
    } else {
        Node *parentNode = searchNode(valueToBePushed, list, list->root);
        int result = strcmp(valueToBePushed, parentNode->word);

        if(result < 0) {
            parentNode->left = newNode;
        } else if(result > 0) {
            parentNode->right = newNode;
        } else {
            parentNode->freq++;
        }
    }

    return;
}

void buildTreeFromTextFile(List *list)
{
    textFile = fopen("testFile.txt", "r");
    char word[1024];

    while(fscanf(textFile, "%s", word) == 1){
        push(word, list);
    }
    fclose(textFile);
}

int main()
{
    List *list = initializeTree();

    buildTreeFromTextFile(list);
    readAll(list->root);

    return 0;
}
