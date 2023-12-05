#include<stdio.h>
#include<stdlib.h>

struct Date 
{
    int day;
    int month;
    int year;
};

struct Date* get_date(void);

int main(void)
{
    struct Date* p = 0;

    p = get_date();
    printf("%d-%d-%d\n", p->day, p->month, p->year);
    free(p);
    p = 0;

    return(0);
}

struct Date* get_date(void)
{
    struct Date* pDate = 0;
    int day, month, year;

    printf("Enter day between 1 to 31 :");
    scanf("%d" , &day);

    printf("Enter Month between 1 to 12 :");
    scanf("%d", &month);

    printf("Enter Year:");
    scanf("%d", &year);

    pDate = (struct Date*)malloc(sizeof(struct Date));
    if(pDate == NULL)
    {
        puts("Error i allocating thr memory");
        exit(-1);
    }

    pDate->day = day;
    pDate->month = month;
    pDate->year = year;

    return(pDate);
}