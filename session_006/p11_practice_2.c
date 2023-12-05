#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Date* allocate_array(size_t* N);
void init_array(struct Date* pDate_arr, size_t N);
void show_array(struct Date* pDate_arr, size_t N);
void free_array(struct Date** ppDate_arr);

int main(void)
{
    struct Date* pDate_arr = NULL;
    size_t N ;

    pDate_arr = allocate_array(&N);
    init_array(pDate_arr, N);
    show_array(pDate_arr, N);
    free_array(&pDate_arr);
    return(0);
}

struct Date* allocate_array(size_t* N)
{
    struct Date* pDate_arr = NULL;
    size_t pN = 5;
    printf("Enter the size of array:");
    scanf("%lld", &pN);

    pDate_arr = (struct Date*)malloc(pN * sizeof(struct Date));
    if(pDate_arr == 0)
    {
        puts("Error in allocating the memory");
        exit(EXIT_FAILURE);
    }

    *N = pN;
    return(pDate_arr);
}

void init_array(struct Date* pDate_arr, size_t N)
{
    size_t i;
    for(i = 0; i < N; ++i)
    {
        pDate_arr[i].day = 20 + i;
        pDate_arr[i].month = 5 + i;
        pDate_arr[i].year = 2020 + i;
    }

}

void show_array(struct Date* pDate_arr, size_t N)
{
    size_t i;

    for(i = 0; i < N; ++i)
    {
        printf("Date at index %llu is %d-%d-%d\n", i, pDate_arr[i].day ,
                 pDate_arr[i].month, pDate_arr[i].year);
    }
}

void free_array(struct Date** ppDate_arr)
{
    free(&ppDate_arr);
    ppDate_arr = 0;
}