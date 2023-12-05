// Design a function to take array from user

#include<stdio.h>
#include<stdlib.h>

int* get_array(int* pN);

int main(void)
{
    int* p = 0;
    int N  = -1;
    int i;

    p = get_array(&N);

    //fill array
    for(i = 1; i <= N; i++)
        *(p + i) = (i) * 100;
    
    //show array
    for(i = 0; i <= N; i++)
        printf("*(p + %d) = %d\n",i, *(p+i));
    
    return(0);
}

int* get_array(int* pN)
{
    int* p = 0;
    int N;

    printf("Enter size of array:");
    scanf("%d", &N);

    if(N <= 0)
    {
        puts("Array size must be positive");
        exit(-1);
    }

    p = (int*)malloc(N * sizeof(int));
    if(p == 0)
    {
        puts("Error in allocating the memory");
        exit(-1);
    }

    *pN = N;
    return(p);
}
