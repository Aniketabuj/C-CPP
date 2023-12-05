#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void init_array(struct Date* pDate_arr, size_t N);
void show_array(struct Date* pDate_arr, size_t N);

int main(void)
{
    struct Date* pDate_arr = 0;
    size_t N  = 5;

    pDate_arr = (struct Date*)malloc(N * sizeof(struct Date));
    if(pDate_arr == NULL)
    {
        puts("Error in allocating thr memory");
        exit(EXIT_FAILURE);
    }

    init_array(pDate_arr, N);
    show_array(pDate_arr, N);

    free(pDate_arr);
    pDate_arr = 0;
}

void init_array(struct Date* pDate_arr, size_t N)
{
    size_t i;

    for(i = 1; i <= N; i++)
    {
        pDate_arr[i].day = 20 + i;
        pDate_arr[i].month = 10 - i;
        pDate_arr[i].year = 2020 + i;

    }
}

void show_array(struct Date* pDate_arr, size_t N)
{
    size_t i;
    for(i = 1; i <= N; i++)
    {
        printf("Date at index %llu is %d-%d-%d\n", i,
                 pDate_arr[i].day, pDate_arr[i].month, pDate_arr[i].year);
    }
}