#include<stdio.h>
#include<stdlib.h>

#define SUCCESS              1
#define VEC_INVALID_INDEX   2
#define VEC_EMPTY           3

struct vector_int{
        int N;
        int* arr;
};

struct vector_int* create_vector(void);
void push_front(struct vector_int* p_vec_int, int new_data);
void push_back(struct vector_int* p_vec_int, int new_data);
int push_at_index(struct vector_int* p_vec_int, int new_data, int index);

int pop_front(struct vector_int* p_vec_int, int* p_front_data);
int pop_beck(struct vector_int* p_vec_int, int* p_beck_data);
int pop_at_index(struct vector_int* p_vec_int, int index, int* data);

int get_index(struct vector_int* p_vec_int,int index, int* data);
int set_index(struct vector_int* p_vec_int,int index, int new_data);
int get_length(struct vector_int* p_vec_int);

void show(struct vector_int* p_vec_int, const char* msg);
void destroy_vector(struct vector_int* p_vec_int);

int main(void)
{
    
    int data; 
    int status; 
    struct vector_int* p_vec = NULL; 

    p_vec = create_vector(); 

    show(p_vec, "Initial state:"); 

    for(data = 5; data <= 20; data = data + 5)
        push_back(p_vec, data); 

    show(p_vec, "After pushing back 5, 10, 15, 20"); 

    for(data = 25; data <= 40; data = data + 5)
        push_front(p_vec, data); 

    show(p_vec, "After pushing to front:25, 30, 35, 40");

    status = pop_back(p_vec, &data); 
    if(status == SUCCESS)
    {
        printf("Poped back data = %d\n", data); 
        show(p_vec, "After pop_back():"); 
    }

    status = pop_front(p_vec, &data); 
    if(status == SUCCESS)
    {
        printf("Poped front data = %d\n", data); 
        show(p_vec, "After pop_front():"); 
    }

    show(p_vec, "Before push_at_index(p_vec, 3, 500)"); 
    status = push_at_index(p_vec, 3, 500); 
    if(status == SUCCESS)   
        show(p_vec, "After push_at_index(p_vec, 3, 500):"); 

    status = pop_at_index(p_vec, 3, &data); 
    if(status == SUCCESS)
    {
        printf("Poped at index data=%d\n", data);  
    }
    show(p_vec, "After pop_index(p_vec, 3, &data)");

    status = set_index(p_vec, 3, 425);
    if(status == SUCCESS)
    {
        puts("Setting index at 3->425");
        show(p_vec, "After setting the index:");
    }

    status = get_index(p_vec,  4, &data);
    if(status == SUCCESS)
    {
        printf("get_index(4) = %d\n",data);
    }

    destroy_vector(p_vec); 
    p_vec = NULL; 

    return (EXIT_SUCCESS);
}

struct vector_int* create_vector(void)
{
    struct vector_int* p_vec = NULL;

    p_vec = (struct vector_int*)malloc(sizeof(struct vector_int));
    if(p_vec == NULL)
    {
        puts("Error in allocating the memory");
        exit(EXIT_FAILURE);
    }
    p_vec->arr = NULL;
    p_vec->N = 0;

    return(p_vec);
}

void push_back(struct vector_int* p_vec_int, int new_data){

    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N + 1) * sizeof(int));
    p_vec_int->N  += 1;

    p_vec_int->arr[p_vec_int->N-1] = new_data;
}

void push_front(struct vector_int* p_vec_int, int new_data)
{
    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N + 1) * sizeof(int));

    p_vec_int->N += 1;

    for(int i = p_vec_int->N-1; i>0; i--)
        p_vec_int->arr[i] = p_vec_int->arr[i-1];
    
    p_vec_int->arr[0] = new_data;
}

int push_at_index(struct vector_int* p_vec_int, int index, int new_data)
{
    if(index >= p_vec_int->N)
        return(VEC_INVALID_INDEX);
    
    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N+1) * sizeof(int));

    p_vec_int->N += 1;

    for(int i = p_vec_int->N-1; i > index; i--)
        p_vec_int->arr[i] = p_vec_int->arr[i-1];
    
    p_vec_int->arr[index] = new_data;
    return(SUCCESS);
}

int pop_back(struct vector_int* p_vec_int, int* p_back_data)
{
    if(p_vec_int->arr == NULL)
        return(VEC_EMPTY);
    
    *p_back_data = p_vec_int->arr[p_vec_int->N-1];

    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N-1) * sizeof(int));
    p_vec_int->N -=1;
    return(SUCCESS);
}

int pop_front(struct vector_int* p_vec_int, int* p_front_data)
{
    if(p_vec_int->arr == NULL)
        return(VEC_EMPTY);
    
    *p_front_data = p_vec_int->arr[0];
    for(int i = 1; i < p_vec_int->N; i++)
        p_vec_int->arr[i-1] = p_vec_int->arr[i];
    
    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N-1) * sizeof(int));
    p_vec_int->N -= 1;
    return(SUCCESS);
}

int pop_at_index(struct vector_int* p_vec_int, int index, int* data){
    if(index >= p_vec_int->N)
        return(VEC_INVALID_INDEX);
    
    *data = p_vec_int->arr[index];
    for(int i =index+1; i > p_vec_int->N; i--)
        p_vec_int->arr[i-1] = p_vec_int->arr[i];
    
    p_vec_int->arr= (int*)realloc(p_vec_int->arr, (p_vec_int->N-1) * sizeof(int));
    p_vec_int->N -= 1;
    return(SUCCESS);
}

int get_index(struct vector_int* p_vec_int, int index, int* data){
    if(index >= p_vec_int->N)
        return(VEC_INVALID_INDEX);
    
    *data = p_vec_int->arr[index];
    return(SUCCESS);
}

int set_index(struct vector_int* p_vec_int, int index, int new_data)
{
    if(index >= p_vec_int->N)
        return(VEC_INVALID_INDEX);
    
    p_vec_int->arr[index] = new_data;
    return(SUCCESS);
}

int get_length(struct vector_int* p_vec){
    return(p_vec->N);
}

void show(struct vector_int* p_vec_int, const char* msg)
{
    int i;
        if(msg != NULL)
            puts(msg);

    for(i = 0; i < p_vec_int->N; i++)
        printf("p_vec_int->arr[%d]:%d\n", i, p_vec_int->arr[i]);
}


void destroy_vector(struct vector_int* p_vec_int)
{
    free(p_vec_int->arr); 
    free(p_vec_int); 
    p_vec_int = NULL; 
}

