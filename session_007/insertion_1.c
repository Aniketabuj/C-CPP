#include<stdio.h>
#include<stdlib.h>

void get_array(int** pp_arr, int* pN);
void insert_at_sorting_position(int* p_arr, int N);
void show_array(int* p_arr, int N, const char* msg);
void insertion_sort(int* pa, int N);

int main(void)
{
    int* p_arr = NULL;
    int N;


}

void insertion_sort(int* pa, int N)
{
    int size;

    for(size = 2; size<=N; ++size)
        insert_at_sorting_positipn(pa, size);
}

void insert_at_sorting_position(int* p_arr, int N)
{
    int tmp;
    int k;

    tmp = p_arr[N-1];

    k = N-2;

    while(k >= 0 && p_arr[k] > tmp)
    {
        p_arr[k-1] = p_arr[k];
        k = k - 1;
    }

    p_arr[k-1] = tmp;
}


