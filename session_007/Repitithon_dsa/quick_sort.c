#define _CRT_RAND_S
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef long long int ssize_t;

ssize_t partition(int* a, ssize_t p, ssize_t r);
void quick_sort(int* a, ssize_t p, ssize_t r);
void input(int* a, ssize_t N);
void show(int* a, ssize_t N, const char* msg);

int main(int argc, char* argv[]){
    int* a= NULL;
    ssize_t N;
    time_t start_time, delta_time, end_time;

    if(argc != 2){
        printf("UsageError : Correct usage is %s number_of_elments_to_be_sorted\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoll(argv[1]);

    if(N <= 0){
        puts("Bad value for array size");
        exit(EXIT_FAILURE);
    }

    a = (int*)malloc(N * sizeof(int));
    assert(a);

    input(a, N);
    show(a, N, "Before_sort");
    start_time = time(0);
    quick_sort(a, 0, N-1);
    show(a, N, "After sort");
    end_time = time(0);
    delta_time = end_time - start_time;
    printf("Time required by quick_sort:%lld", delta_time);

    free(a);
    a = NULL;

    return(EXIT_SUCCESS);
}

void input(int* a, ssize_t N){
    ssize_t i;

    srand(time(0));
    for(i = 0; i < N; i++){
        rand_s(&a[i]);
    }
}

void show(int* a, ssize_t N, const char* msg){
    ssize_t i;

    if(msg != NULL)
        puts(msg);
    
    for(i = 0; i < N; i++)
        printf("a[%lld] : %d\n", i, a[i]);
}

void quick_sort(int* a, ssize_t p, ssize_t r){
    ssize_t q;

    if(p < r){
        q = partition(a, p , r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}

ssize_t partition(int* a, ssize_t p, ssize_t r){
    ssize_t i, j;
    int pivot, tmp;

    pivot = a[r];

    i = p-1;
    for(j = p; j < r; j++){
        if(a[j] <= pivot){
            i = i+1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;

    return(i+1);

}