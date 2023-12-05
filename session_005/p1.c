#include<stdio.h>
#include<stdlib.h>

void fill_array(int* p, size_t N);
void show_array(int* p, size_t N);

int main(void)
{
    int* p_arr = 0;
    size_t N ;

    printf("Enter the array size user want:\n");
    scanf("%lld", &N);

    p_arr = (int*)malloc(N * sizeof(int));
    if(p_arr == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    fill_array(p_arr, N);
    show_array(p_arr, N);

    free(p_arr);
    p_arr = 0;

    return(0);
}

void fill_array(int* p, size_t N)
{
    size_t i;

    for(i = 1; i <= N; i++)
        *(p + i) = (i) * 100;
}

void show_array(int* p, size_t N)
{
    size_t i;

    for(i = 1; i <= N ; ++i)
        printf("*(p + %lld) = %d\n", i, *(p + i));
}

