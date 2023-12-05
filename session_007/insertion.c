#include<stdio.h>
#include<stdlib.h>

int arr[8] = {25, 45, 50, 80, 70, 95, 100, 10};

int main(void)
{
    int i, j, key;

    puts("Before sorting the array:");
    for(i = 0; i < 8; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    
    for(j = 1; j < 8; j++)
    {
        key = arr[j];
        i = j - 1;
        while(i > -1 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i + 1 ] = key;
    }

    puts("Array after sort:");
    for(i = 0; i < 8; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    
    exit(-1);
}