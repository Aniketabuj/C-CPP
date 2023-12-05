#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void show_date(struct Date* pDate);
void get_struct(void);

int main(void)
{
    struct Date exam_date = {1, 2, 2023};
    struct Date* p_result_date = 0;

    p_result_date = (struct Date*)malloc(sizeof(struct Date));
    if(p_result_date == 0)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_result_date->day = 30;
    p_result_date->month = 3;
    p_result_date->year = 2023;

    show_date(&exam_date);
    show_date(p_result_date);

    free(p_result_date);
    p_result_date = 0;


    puts("After calling struct:");
    get_struct();
    return(EXIT_SUCCESS);

}

void show_date(struct Date* pDate)
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year);
}

void get_struct(void)
{
    struct Date p_exam_date = {23, 3, 2023};
    struct Date* p_result_date = 0;

    p_result_date = (struct Date*)malloc(sizeof(struct Date));
    if(p_result_date == 0)
    {
        puts("Error in allocating memory");
        exit(-1);
    }

    p_result_date->day = 25;
    p_result_date->month = 5;
    p_result_date->year = 2023;

    show_date(&p_exam_date);
    show_date(p_result_date);

    free(p_result_date);
    p_result_date = 0;
}

