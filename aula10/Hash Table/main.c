#include <stdio.h>
#include <stdlib.h>

int tableFilled = 0;
int tableSize;

int *createTable(int size)
{
    int *hashTable;
    hashTable = malloc(sizeof(int*)*size);
    int i;

    for(i = 0; i < size; i++){
        hashTable[i] = 0;
    }

    tableSize = size;

    return hashTable;
}

int *checkTableSize(int *hashTable)
{
    if(0.4*tableSize > tableFilled){
        return hashTable;
    }

    int i;
    int *doubledTable = createTable(tableSize*2);

    tableFilled = 0;

    for(i=0; i<tableSize/2; i++){
        if((hashTable[i] != 0) && (hashTable[i] != -1)){
            pushElements(hashTable[i], doubledTable);
        }
    }

    free(hashTable);

    return doubledTable;
}

int findPositionToPush(int value, int *hashTable, int pos)
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

void printTable(int *hashTable)
{
    int i = 0;

    for(i = 0; i < 10; i++){
        printf("%d ", hashTable[i]);
    }
}

void pushElements(int value, int *hashTable)
{
    hashTable = checkTableSize(hashTable);

    int rule = value%10;
    int pos = findPositionToPush(value, hashTable, rule);
    hashTable[pos] = value;
    tableFilled++;
}

int main()
{
    int *hashTable = createTable(10);

    pushElements(1, hashTable);
    pushElements(11, hashTable);
    pushElements(21, hashTable);
    pushElements(31, hashTable);
    pushElements(41, hashTable);
    pushElements(51, hashTable);
    pushElements(61, hashTable);
    pushElements(71, hashTable);


    return 1;
}
