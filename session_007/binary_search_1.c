#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define RESULT_FAILED -1
void binary_search(int* a, int start_index, int end_index, int search_index);
void insertion_sort(int* a, int N);

int main(int argc, char* argv[]){
    int* a = NULL;
    int N;
    int ret;
    int i;

    
    if(argc != 2){
        printf("Usage Error: usage error %s of elements_binary_search\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ret = atoi(argv[1]);
    if(N <= 0){
        puts("Bad array size");
        exit(EXIT_FAILURE);
    }
    a = (int*)malloc(N * sizeof(int));
    if(a == NULL){
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    insertion_sort(a, N);
 
}

void binary_search(int* a, int start_index, int end_index, int search_element){
    int mid;

    if(start_index <= end_index){
          mid = (start_index + end_index)/2;
    if(search_element == a[mid])
        return(mid);
    else if(search_element < a[mid])
        return(binary_search(a, start_index, mid-1, search_element));
    else
        return(binary_search(a, mid+1, end_index, search_element));
    }
    else
        return(RESULT_FAILED);
}