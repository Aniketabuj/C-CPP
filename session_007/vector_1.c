#include<stdio.h>
#include<stdlib.h>

#define SUCCESS              1
#define VEC_INVALID_INDEX    2
#define VEC_EMPTY            3 

struct vector_int
{
    int N;
    int* arr;
};

struct vector_int* create_vector(void);
void push_front(struct vector_int* p_vec_int, int new_data);
void push_back(struct vector_int* p_vec_int, int new_data);
int push_at_index(struct vector_int* p_vec_int, size_t index, int new_data);

int pop_back(struct vector_int* p_vec_int, int* p_beck_data);
int pop_front(struct vector_int* p_vec_int, int* p_front_data);
int pop_at_index(struct vector_int* p_vec_int, size_t index, int* data);

int get_index(struct vector_int* p_vec_int, size_t index, int* pData);