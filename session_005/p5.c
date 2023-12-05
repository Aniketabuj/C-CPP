#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

void initialise_date(struct Date* pDate, int init_day, int init_month, int init_year); 
void show_date(struct Date* pDate); 

int main(void)
{
    struct Date exam_date; 
    struct Date* p_result_date = 0; 

    p_result_date = (struct Date*)malloc(sizeof(struct Date)); 
    if(p_result_date == 0)
    {
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    initialise_date(&exam_date, 1, 2, 2023); 
    initialise_date(p_result_date, 30, 3, 2023); 
    
    show_date(&exam_date); 
    show_date(p_result_date); 

    free(p_result_date); 
    p_result_date = 0; 

    return (0); 
}

void initialise_date(struct Date* pDate, int init_day, int init_month, int init_year)
{
    struct Date* date = NULL;
    date-> day ;
    date-> month  ;
    date->year ;
    date = pDate;
}

void show_date(struct Date* pDate)
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
}

//bug in thid code