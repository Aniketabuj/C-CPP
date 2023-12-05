#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void get_date(struct Date** ppDate);
void show_date(struct Date* pDate);
void realease_date(struct Date** ppDate);

int main(void)
{
    struct Date* pDate = 0;
    get_date(&pDate);
    show_date(pDate);
    realease_date(&pDate);
}

void get_date(struct Date** ppDate)
{
    struct Date* pDate = 0;
    int day, month, year;

    printf("Enter day:"); 
    scanf("%d", &day); 

    printf("Enter month:"); 
    scanf("%d", &month); 

    printf("Enter year:");  
    scanf("%d", &year); 

    pDate = (struct Date*)malloc(sizeof(struct Date));
    if(pDate == NULL)
    {
        puts("EDrror in allocating memory");
        exit(-1);
    }

    pDate->day = day;
    pDate->month = month;
    pDate->year = year;

    *ppDate = pDate;
}

void show_date(struct Date* pDate)
{
    printf("%d-%d-%d\n",pDate->day, pDate->month, pDate->year);
}

void realease_date(struct Date** ppDate)
{
    free(*ppDate);
    *ppDate = 0;
}