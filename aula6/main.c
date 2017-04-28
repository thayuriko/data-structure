#include <stdio.h>

int binarySearch(int array[], int start, int end, int value)
{
    int half = (start+end)/2;

    if(array[half] == value){
        return half;
    } else if((start == end)&&(value != array[start])) {
        return -1;
    }

    if(array[half] > value){
        return binarySearch(array, start, half-1, value);
    } else {
        return binarySearch(array, half+1, end, value);
    }
}

int main()
{
    int array[] = {1,2,3,4,5,6,7};
    int result = binarySearch(array, 0, 6, 6);
    printf("%d", result);
    
    return 0;
}
