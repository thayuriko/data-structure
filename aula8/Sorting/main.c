#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

double printSortedArray(int array[5])
{
    clock_t begin = clock();
    int i;

    for(i=0; i<5; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;

    return time_spent;
}

void selection(int array[5])
{
    int lowestId = 0;
    int i, j, tmp, firstId, lowest;

    for(firstId=0; firstId<5; firstId++){
        lowest = array[firstId];
        for(i=firstId; i<5; i++){
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
}

void insertion(int array[5])
{
    int i, j, tmp;

    for(i=1; i<5; i++){
        j = i-1;
        while(((array[j] > array[i]) && (j >= 0))||(j >= 0)){
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            j = j - 1;
        }
    }

    printSortedArray(array);
}

void merge()
{

}

int main()
{
    int array[5] = {3,1,5,2,4};
    double selectionTime = selection(array);
    insertion(array);

    return 0;
}
