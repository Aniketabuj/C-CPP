#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6 , 7 , 8, 9};
    int i, j;
    
    for( i= 0; i < arr[i]; i++)
    {
        for( j = 0; j < arr[j]; j--)
        {
            arr[j] = arr[i]%10;
        }
    }

    printf("arr[%d] = %d\n", j, arr[j]);
}