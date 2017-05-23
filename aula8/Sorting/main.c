#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void printSortedArray(int array[N])
{
    int i;

    for(i=0; i<N; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
}

double selection(int array[N])
{
    clock_t begin = clock();

    int lowestId = 0;
    int i, j, tmp, firstId, lowest;

    for(firstId=0; firstId<N; firstId++){
        lowest = array[firstId];
        for(i=firstId; i<N; i++){
            if(array[i] < lowest){
                tmp = lowest;
                lowest = array[i];
                lowestId = i;
            }
        }
        array[firstId] = lowest;
        array[lowestId] = tmp;
    }

    printSortedArray(array);

    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;

    return time_spent;
}

double insertion(int array[N])
{
    clock_t begin = clock();

    int i, j, tmp;

    for(i=1; i<N; i++){
        j = i-1;
        while(((array[j] > array[i]) && (j >= 0))||(j >= 0)){
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            j = j - 1;
        }
    }

    printSortedArray(array);

    clock_t end = clock();

    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;

    return time_spent;
}

void mergeArrays(arrayA[], arrayB[], sizeA, sizeB)
{
    int i;


}

int divideArray(array[N/2], beginning, ending)
{
    int aSize = ending - beginning;

    if(aSize == 1){
        return;
    }

    int i, newArray[aSize], arrayB[aSize];

    for(i=beginning; i<aSize; i++){
        newArray[i] = array[i];
    }

    divideArray(newArray, beginning, aSize);
}

void merge(array[N])
{
    divideArray(array, 0, N/2 - 1);
    divideArray(array, N/2, arraySize - 1);
    mergeArrays();
}

int main()
{
    int array[N] = {3,1,5,2,4};
    double selectionTime = selection(array);
    double insertionTime = insertion(array);

    return 0;
}
