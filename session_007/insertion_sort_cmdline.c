#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long ssize_t;

void input(int* a, ssize_t N);
void show(int* a, ssize_t N, const char* msg);
void insertion_sort(int* a, ssize_t N);

int main(int argc, char* argv[]){
    int* a = NULL;
    ssize_t N;
    time_t start_time, end_time, delta_time;

    if(argc != 2){
        printf("Usage error: usage is %s number_of_elements_to_be_sorted\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoll(argv[1]);

    if(N <= 0){
        puts("Bad value of array size");
        exit(EXIT_FAILURE);
    }

    a = (int*)malloc(N * sizeof(int));
    if(a == NULL){
        puts("error in allocating memory");
        exit(EXIT_FAILURE);
    }

    input(a, N);
    show(a, N, "Before sort:");
    start_time = time(0);
    insertion_sort(a, N);
    end_time = time(0);
    show(a, N, "After sort");
    delta_time = end_time - start_time;
    printf("The required time by insertion sort:%lld\n", delta_time);

    free(a);
    a = NULL;

    exit(EXIT_FAILURE);
}

void input(int* a, ssize_t N){
    ssize_t i;

    srand(time(0));
    for(i = 0; i < N; i++)
        a[i] = rand();
}

void show(int* a, ssize_t N, const char* msg){
    ssize_t i;
    if(msg != NULL)
        puts(msg);
    
    for(i = 0; i < N; i++){
        printf("a[%lld]:%d\n", i, a[i]);
    }
}

void insertion_sort(int* a, ssize_t N){
    int i, j;
    int key;

    for(j = 1; j < N; j++){
        key = a[j];
        i = j-1;

        while(i > -1 && a[i] > key){
            a[i+1] = a[i];
            i = i-1;
        }

        a[i+1] = key;
    }
}