
#include<stdio.h>
#include<stdlib.h>
struct Date 
{
    int day, month, year;
};

struct Date
{
    int day;
    int month;
    int year;

};

struct Date
{
    int day;
    int month;
    int year;
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Date* get_date_instance(int init_day, int init_month, int init_year)
{
    struct Date* pdate = NULL;

    pdate = (struct Date*)malloc(sizeof(struct Date));
    if(pdate == NULL)
    {
        puts("Error in a");
        exit(EXIT_FAILURE); 
    }

    pdate ->day = init_day;
    pdate ->month = init_month;
    pdate ->year = init_year;

    return(pdate);
}

struct Date* get_date_instance(int init_day, int init_month, int init_year)
{
    struct Date* pdate = NULL;

    pdate = (struct Date*)malloc(sizeof(struct Date));
    if(pdate == NULL)
    {
        puts("Error");
        exit("EXIT_FAILURE");
    }
        pdate ->day = init_day;
        pdate ->month= init_month;
        pdate ->year= init_year;

        return(pdate);
    
}

void get_date_instance_1_caller(void)
{
    struct Date* p = NULL;

    p = get_date_instance(1, 3, 1999);
    printf("%d-%d-%d\n",p->day, p->month,p->year);
    free(p);
    p = NULL;
}

void get_date_instance_1_caller(void)
{
    struct Date* p =NULL;

    p = get_date_instance_1(23, 4, 2020);
    printf("%d-%d-%d\n",p->day, p->month, p->year);
    free(p);
    p = NULL;
}

void get_date_instance_1_caller(void)
{
    struct Date* p = NULL;

    p = get_date_instance_1(12, 4, 2020);
    printf("%d-%d-%d\n",p->day,p->month,p->year);
    free(p);
    p = NULL;        
}
//////////////////////////////////

void get_date_instance_2(struct Date** ppDate, int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL;

    pDate = (struct Date*)malloc(sizeof(struct Date));
    if(pDate == NULL)
    {
        puts("Error");
        exit("EXIT_FAILURE");

    }
    pDate->day = init_day;
    pDate->month = init_month;
    pDate-> year = init_year;

    *ppDate = pDate;
}
/////////////////////

void caller_of_get_day_instance_2(void)
{
    struct Date* pDate = NULL;

    get_instance_2(&pDate, 1, 1, 1970);
    printf("%d-%d-%d\n",pDate ->day,pDate->month, pDate->year);
    free(pDate);
    pDate = NULL;
}

struct Date* get_date_array(int* pN)
{
    
    struct Date* pDate = NULL;
    int N;
    int i;
    printf("Enter N:");
    scanf("%d", &N);

    if(N <=0)
    {
        puts("bad size for array");
        exit(EXIT_FAILURE);
    }
    pDate = (struct Date*)malloc(N * sizeof(struct Date));
    if(pDate == NULL)
    {
        puts("Error");
        exit(EXIT_FAILURE);
    }

    for( i = 0; i < N; ++i)
    {
        pDate[i].day = 1;
        pDate[i].month = 1;
        pDate[i].year = 1970;
    }

    *pN = N;
    return(pDate);
}
