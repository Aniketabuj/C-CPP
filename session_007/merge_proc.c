#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#define TRUE 1 

typedef long long ssize_t; 

void input(int* a, ssize_t N);
void show(int* a, ssize_t N, const char* msg); 
void merge_sort(int* a, ssize_t p, ssize_t r); 
void merge(int* a, ssize_t p, ssize_t q, ssize_t r); 

int main(int argc, char* argv[]){
    int* a = NULL; 
    ssize_t N; 
    time_t start_time, end_time, delta_time; 

    /* Commandline validation */
    if(argc != 2){
        printf("UsageError:Correct usage is %s number_of_elements_to_be_sorted\n", 
                argv[0]); 
        exit(EXIT_FAILURE); 
    }

    N = atoll(argv[1]); 

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
    //show(a, N, "Before sort:"); 
    start_time = time(0); 
    merge_sort(a, 0, N-1);
    end_time = time(0); 
    // show(a, N, "After sort:"); 
    delta_time = end_time - start_time; 
    printf("Time required by merge_sort:%lld", delta_time); 

    free(a); 
    a = NULL; 

    exit(EXIT_SUCCESS); 
}

void merge_sort(int* a, ssize_t p, ssize_t r){
    ssize_t q; 

    if(p < r){
        q = (p+r)/2; 
        merge_sort(a, p, q); 
        merge_sort(a, q+1, r); 
        merge(a, p, q, r); 
    }
}

void merge(int* a, ssize_t p, ssize_t q, ssize_t r){
    int* a1 = NULL, *a2 = NULL; 
    int N1 = q - p + 1, N2 = r - q; 
    int i, j, k; 

    a1 = (int*)malloc(N1 * sizeof(int)); 
    if(a1 == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    } 

    a2 = (int*)malloc(N2 * sizeof(int)); 
    if(a2 == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N1; ++i)
        a1[i] = a[p+i]; 

    for(i = 0; i < N2; ++i)
        a2[i] = a[q+1+i]; 

    i = 0; 
    j = 0; 
    k = 0; 

    while(TRUE){
        if(a1[i] <= a2[j]){
            a[p+k] = a1[i]; 
            i = i + 1; 
            k = k + 1; 
            if(i == N1){
                while(j < N2){
                    a[p+k] = a2[j]; 
                    j = j + 1; 
                    k = k + 1; 
                }
                break; 
            }
        }else{
            a[p+k] = a2[j]; 
            j = j + 1; 
            k = k + 1; 
            if(j == N2){
                while(i < N1){
                    a[p+k] = a1[i]; 
                    i = i + 1; 
                    k = k + 1; 
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