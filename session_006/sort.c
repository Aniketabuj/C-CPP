#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

typedef long long ssize_t; 

void input(int* a, ssize_t N);
void show(int* a, ssize_t N, const char* msg); 
void insertion_sort(int* a, ssize_t N); 

int main(void){
    int* a = NULL; 
    ssize_t N; 

    printf("Enter the number of elements to be sorted:");
    scanf("%lld", &N); 

    if(N <= 0){
        puts("Bad value for array size"); 
        exit(EXIT_FAILURE); 
    } 

    a = (int*)malloc(N * sizeof(int)); 
    if(a == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    input(a, N); 
    show(a, N, "Before sort:"); 
    insertion_sort(a, N);
    show(a, N, "After sort:"); 

    free(a); 
    a = NULL; 

    exit(EXIT_SUCCESS); 
}

void input(int* a, ssize_t N){
    ssize_t i; 

    srand(time(0)); 
    for(i = 0; i < N; ++i)
        a[i] = rand(); 
}

void show(int* a, ssize_t N, const char* msg){
    ssize_t i; 

    if(msg != NULL)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("a[%lld]:%d\n", i, a[i]); 
}

void insertion_sort(int* a, ssize_t N){
    ssize_t i, j; 
    int key; 

    for(j = 1; j < N; ++j){
        key = a[j]; 

        i = j- 1; 
        while(i > -1 && a[i] > key){
            a[i+1] = a[i]; 
            i = i - 1; 
        }

        a[i+1] = key; 
    }
}
