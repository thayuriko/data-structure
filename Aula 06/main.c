#include <stdio.h>

int binarySearch(int array[], int start, int end, int value)
{
    double halfDouble = ceil((double)(end+start)/2);

    int half = (int)halfDouble;

    if(array[half] == value){
        return half;
    }

    if((start == end)&&(value == start)){
        return start;
    } else if((start == end)&&(value != start)) {
        return -1;
    }

    if(array[half] > value){
        binarySearch(array, start, half-1, value);
    } else {
        binarySearch(array, half+1, end, value);
    }
}

int main()
{
    int array[] = {1,2,3,4,5,6,7};
    int result;
    result = binarySearch(array, 0, 8, 6);

    printf("a posicao eh %d e o valor dessa posicao eh %d\n\n", result, array[result]);

    result = binarySearch(array, 0, 8, 2);
    printf("a posicao eh %d e o valor dessa posicao eh %d\n\n", result, array[result]);

    result = binarySearch(array, 0, 6, 50);
    printf("a posicao eh %d e o valor dessa posicao eh %d\n\n", result, array[result]);

    result = binarySearch(array, 0, 6, 1);
    printf("a posicao eh %d e o valor dessa posicao eh %d\n\n", result, array[result]);

    return 0;
}
