#include "vector.hpp"
#include <cstdio> 

int main(void){
    vector* p_vector = new vector; 
    int status; 
    int data; 
    
    p_vector->push_back(100); 
    p_vector->show("after pushing back 100"); 
    
    // vector::show(p_vector, "after pushing back 100"); 
    p_vector->push_back(200); 
    p_vector->show("after pushing back 200"); 
    p_vector->push_back(300); 
    p_vector->show("after pushing back 300"); 
    p_vector->push_back(400); 
    p_vector->show("after pushing back 400"); 
    p_vector->push_back(500); 
    p_vector->show("after pushing back 500"); 

    status = p_vector->get(p_vector->size(), &data);
    if(status == VECTOR_INDEX_ERROR)
        puts("Index bound is overridden");  

    status = p_vector->get(p_vector->size() - 1, &data); 
    if(status == SUCCESS){
        printf("Last element : %d\n", data); 
    }

    p_vector->set(p_vector->size() - 1, 1535); 
    status = p_vector->get(p_vector->size() - 1, &data); 
    if(status == SUCCESS){
        printf("Last element : %d\n", data); 
    }

    delete p_vector; 
    p_vector = 0; 

    return (0); 
}