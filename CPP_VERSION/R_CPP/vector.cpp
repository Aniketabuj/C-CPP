#include <cstdio> 
#include <cstdlib> 
#include "vector.hpp"

vector::vector() : p_array(0), N(0){
}

vector::~vector(){
    free(p_array); 
}

void vector::push_back(int new_data){
    p_array = (int*)realloc(p_array, (N+1) * sizeof(int)); 
    if(p_array == 0){
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    N = N + 1; 
    p_array[N-1] = new_data; 
}

void vector::show(const char* msg) const{
    
    if(msg != 0){
        puts(msg); 
    }

    int i; 

    for(i = 0; i < N; ++i)
        printf("p_array[%d]:%d\n", i, p_array[i]); 
}

int vector::get(int index, int* p_data) const{
    if(index < 0 || index >= N)
        return (VECTOR_INDEX_ERROR); 
    *p_data = p_array[index]; 
    return (SUCCESS); 
}

int vector::set(int index, int new_value){
    if(index < 0 || index >= N)
        return (VECTOR_INDEX_ERROR); 
    p_array[index] = new_value; 
    return (SUCCESS); 
}

int vector::size() const{
    return N; 
} 