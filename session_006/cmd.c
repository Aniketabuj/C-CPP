#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int i;

    i = 0;
    while(argv[i] != NULL)
    {
        printf("argv[%d]:%s\n", i, argv[i]);
        i += 1;
    }
    return(0);
}