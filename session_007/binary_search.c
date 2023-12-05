#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SEARCH_FAILED -1

int binary_search(int* arr, int start_index, int end_index, int search_element);
void insertion_sort(int* a, int N);

int main(int argc, char* argv[]){
    int* a = NULL;
    int N = 0;
     int ret;

     if(argc != 2){
        printf("Usage error:%s number_of_elemnts\n", argv[0]);
        exit(EXIT_FAILURE);
     }

    N = atoi(argv[1]);
        if(N <= 0){
            printf("Bad size of array\n");
            exit(EXIT_FAILURE);
        }
    
    a = (int*)malloc(N * sizeof(int));
    if(a == NULL){
        puts("Error in allcoating memory");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0; i < N; i++){
        a[i] = rand();
       // printf("Number is a[%d] : %d\n", i, a[i]);
    }
    insertion_sort(a, N);

    int known_existing_data[5] = {a[0], a[rand()%N], a[rand()%N], a[rand()%N],a[N-1]};
    int known_non_existing_data[3] = {-500, -300, -100};

    for(i = 0; i < 5; i++){
        ret = binary_search(a, 0, N-1, known_existing_data[i]);
        assert(a >= 0);
        printf("data = %d found at index %d\n", known_existing_data[i], ret);
    }

    for(i = 0; i < 3; ++i){
        ret = binary_search(a, 0, N-1, known_non_existing_data[i]); 
        assert(ret == SEARCH_FAILED); 
        printf("%d does not exist in array\n", known_non_existing_data[i]); 
    }

    free(a); 
    a = NULL; 

    return (EXIT_SUCCESS); 

}

int binary_search(int* arr, int start_index, int end_index, int search_element){
    int mid;

    if(start_index <= end_index){
        mid = (start_index + end_index)/2;
        if(search_element == arr[mid])
            return(mid);
        else if(search_element < arr[mid])
            return(binary_search(arr, start_index, mid-1, search_element));
        else    
            return(binary_search(arr, mid + 1, end_index, search_element));
        
    }

    return(SEARCH_FAILED);
}

void insertion_sort(int* a, int N){
    int i , j ;
    int key;

    for(j = 1; j < N; j++)
    {
        key = a[j];
        i = j-1;
        while(i > -1 && a[i] > key){
            a[i+1] = a[i];
            i = i - 1;
        }

        a[i+1] = key;
    }
}