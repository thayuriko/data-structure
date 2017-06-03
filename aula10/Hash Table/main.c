#include <stdio.h>
#include <stdlib.h>

int tableSize = 0;

int createTable(int size)
{
    int hashTable[size], i;

    for(i = 0; i < size; i++){
        hashTable[i] = 0;
    }

    return hashTable;
}

int findPosition(int value, int *hashTable, int pos)
{
    int i = pos;
    if(hashTable[pos] == value){
        return pos;
    }

    while((hashTable[pos] != 0)&&(hashTable[pos] != -1)){
        if(pos < 9)
            findPosition(value, hashTable, pos++);
        else
            findPosition(value, hashTable, 0);
    }

    return pos;
}

void printTable(int *hashTable)
{
    int i = 0;


}

void pushElements(int value, int *hashTable, int position)
{
    hashTable[position] = value;
    tableSize++;
}

int main()
{
    int *hashTable = createTable(10);

    int value = 1;
    int position = findPosition(value, hashTable, value%10);
    pushElements(value, hashTable, position);

    value = 50;
    position = findPosition(value, hashTable, value%10);
    pushElements(value, hashTable, position);

    value = 32;
    position = findPosition(value, hashTable, value%10);
    pushElements(value, hashTable, position);

    value = 53;
    position = findPosition(value, hashTable, value%10);
    pushElements(value, hashTable, position);

    value = 58;
    position = findPosition(value, hashTable, value%10);
    pushElements(value, hashTable, position);

    int i;
    for(i = 0; i < 10; i++){
        printf("%d ", hashTable[i]);
    }

    return 1;
}
