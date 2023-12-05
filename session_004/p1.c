#include<stdio.h>
#include<stdlib.h>

void test_void(void);


int main(void)
{
    test_1();
    return(0);
}


void test_1(void)
{
    int n = 10;
    int* p = NULL;

    printf("&n = %p\n", &n);
}