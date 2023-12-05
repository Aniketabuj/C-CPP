#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Date* allocate_date_array(size_t* pN);
void init_array(struct Date* pDate_arr, size_t N);
void show_array(struct Date* pDate_arr, size_t N);
void free_date_array(struct Date** ppDate_arr);

int main(void)
{
    struct Date* pDate_arr  = 0;
    size_t N;

    pDate_arr = allocate_date_array(&N);
    init_array(pDate_arr, N);
    show_array(pDate_arr, N);
    free_date_array(&pDate_arr);

    return(0);
}

struct Date* allocate_date_array(size_t* pN)
{
    struct Date* pDate_arr = 0;
    size_t N = 5;

    pDate_arr = (struct Date*)malloc(N * sizeof(struct Date));
    if(pDate_arr == 0)
    {
        puts("Error in allocating memory");
        exit(-1);
    }

   *pN = N;
    return(pDate_arr);
}

void init_array(struct Date* pDate_arr, size_t N)
{
    size_t i;

    for(i = 1; i<=N; i++)
    {
        pDate_arr[i].day = 20 + i;
        pDate_arr[i].month = 10 - i;
        pDate_arr[i].year = 2020 + i;
    }
}

void show_array(struct Date* pDate_arr, size_t N)
{
    size_t i;
    for(i=1; i<=N; i++)
    {
        printf("Dateat index %llu is %d-%d-%d\n",i,
                 pDate_arr[i].day, pDate_arr[i].month, pDate_arr[i].year);
    }
}

void free_date_array(struct Date** ppDate_arr)
{
    free(*ppDate_arr);
    *ppDate_arr = 0;
}