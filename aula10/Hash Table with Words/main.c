#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tableFilled = 0;
int tableSize;

char *createTable(int size)
{
    char **hashTable, i;
    hashTable = malloc(sizeof(char*)*size);

    for(i = 0; i < size; i++){
        hashTable[i] = (char*)malloc(1023);
        hashTable[i] = NULL;
    }

    tableSize = size;

    return hashTable;
}

char *checkTableSize(char *hashTable)
{
    if(0.4*tableSize > tableFilled){
        return hashTable;
    }

    int i;
    int *doubledTable = createTable(tableSize*2);

    tableFilled = 0;

    for(i=0; i<tableSize/2; i++){
        if((hashTable[i] != '\0') && (hashTable[i] != NULL)){
            pushElements(hashTable[i], doubledTable);
        }
    }

    free(hashTable);

    return doubledTable;
}

int findPositionToPush(int value, char *hashTable, int pos)
{
    if(hashTable[pos] == value){
        return pos;
    }

    while((hashTable[pos] != 0)&&(hashTable[pos] != -1)){
        if(pos < tableSize)
            findPositionToPush(value, hashTable, pos++);
        else
            findPositionToPush(value, hashTable, 0);
    }

    return pos;
}

void printTable(char *hashTable)
{
    int i = 0;

    for(i = 0; i < 10; i++){
        printf("%s ", hashTable[i]);
    }
}

void pushElements(char value[], char *hashTable)
{
    int rule = strlen(value);
    int pos = findPositionToPush(value, hashTable, rule);

    strcpy(hashTable[pos], value);
    tableFilled++;
}

void freeMemory(char *hashTable)
{
    int i;

    free(hashTable);
}

int main()
{
    char **hashTable = createTable(10);

    char userWord[1023];

    printf("Insira uma palavra: ");
    scanf("%s", userWord);

    hashTable = checkTableSize(hashTable);
    pushElements(userWord, hashTable);
    printTable(hashTable);

    freeMemory(hashTable);

    return 1;
}
