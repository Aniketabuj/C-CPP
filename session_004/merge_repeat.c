#include<stdio.h>
#include<stdlib.h>

#define TRUE 1

void merge(int* a, int p, int q, int r)
{
    int* a1 = NULL;
    int* a2 = NULL;
    int N1 = 0;
    int N2 = 0;

    N1 = q - r + 1;
    N2 = r - q;

    int k; 
    int k1;
    int k2;
    
    a1 = (int*)malloc(N1 * (sizeof(int)));
    if(a1 == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    a2 = (int*)malloc(N2 * (sizeof(int)));
    if(a2 == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    for( k = 0; k < N1; ++k)
    {
        a1[k1] = a[p + k];
    }

    for( k = 0; k < N2; ++k)
    {
        a2[k2] = a[q + 1 + k];
    }
     k = 0;
     k2 = 0;
     k1 = 0;

     while(TRUE)
     {
        if(a1[k1] <= a2[k2])
        {
            a[p + k] = a1[k1];
            k = k + 1;
            k1 = k + 1;
            if( k1 == N1)
            {
                while(k2 < N2)
                {
                    a[p + k]= a2[k2];
                    k++;
                    k2++;

                }
                break;
            }
        }
        else
        {
            a[p+k] = a2[k2];
            k2++;
            k++;
            if(k2 == N2)
            {
                while(k1 < N1)
                {
                    a[p+k] = a1[k1];
                    k1++;
                    k++;
                }
                break;
            }
        }
     }

     free(a1);
     a1 = NULL;

     free(a2);
     a2 = NULL;
}

void merge(int* a, int p, int q, int r)
{
    int N1 = q - p +1;
    int N2 = r - q;
    int* a1 = NULL;
    int* a2 = NULL;
    int k1, k2, k;

    a1 = (int*)malloc(N1 * (sizoef(int)));
    if(a1 == NULL)
    {
        puts("Error in allocating memory");
        exit("EXIT_FAILURE");
    }

}