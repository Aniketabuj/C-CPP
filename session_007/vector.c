#include<stdio.h>
#include<stdlib.h>

#define SUCCESS             1
#define VEC_INVALID_INDEX   2
#define VEC_EMPTY           3

struct vector_int 
{
    int* arr;
    size_t N;
};

struct vector_int* create_vector(void);
void push_back(struct vector_int* p_vec_int, int new_data);
void push_front(struct vector_int* p_vec_int, int new_data);
int push_at_index(struct vector_int* p_vec_int, size_t index, int new_data);

int pop_back(struct vector_int* p_vec_int, int* pback_data);
int pop_front(struct vector_int* p_vec_int, int* pfront_data);
int pop_at_index(struct vector_int* p_vec_int, size_t index, int* pdata);

int get_index(struct vector_int* p_vec_int, size_t index, int* p_data);
int set_index(struct vector_int* p_vec_int, size_t index, int new_data);
size_t get_size(struct vector_int* p_vec);

void show(struct vector_int* p_vec_int, const char* msg);
void destroy(struct vector_int* p_vec_int);


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
        show(p_vec, "After pop_index(p_vec, 3, &data)"); 
    }

    status = set_index(p_vec, 3, 425);
    if(status == SUCCESS)
    {
        printf("set at index =%d\n", data);
        show(p_vec, "After setting the index:");
    }

    status = get_index(p_vec,  4, &data);
    if(status == SUCCESS)
    {
        printf("get_index() = %d\n",data);
        show(p_vec, "After call to get_index:");
    }

    status = get_size(p_vec);
    printf("status = %d\n", status);

    destroy(p_vec); 
    p_vec = NULL; 

    return (EXIT_SUCCESS); 
}

struct vector_int* create_vector(void)
{
    struct vector_int* p_vec = NULL;

    p_vec = (struct vector_int*)malloc(sizeof(struct vector_int));
    if(p_vec == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_vec->arr = NULL;
    p_vec->N = 0;

    return(p_vec);
}

void push_back(struct vector_int* p_vec_int, int new_data)
{
    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N + 1) * sizeof(int));
    if(p_vec_int->arr == NULL)
    {
        puts("Error in allocatinfg memory");
        exit(EXIT_FAILURE);
    }

    p_vec_int->N += 1;

    p_vec_int->arr[p_vec_int->N-1] = new_data;
}

void push_front(struct vector_int* p_vec_int, int new_data)
{
    int i;
    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N+1) * sizeof(int));
    if(p_vec_int->arr == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_vec_int->N += 1;

    for(i = p_vec_int->N-1; i > 0; --i)
        p_vec_int->arr[i] = p_vec_int->arr[i-1];
    p_vec_int->arr[0] = new_data;
}

int push_at_index(struct vector_int* p_vec_int, size_t index, int new_data)
{
    if(index>=p_vec_int->N)
        return(VEC_INVALID_INDEX);

    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N + 1) * sizeof(int));
    if(p_vec_int->arr == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_vec_int->N += 1;

    for(int i=p_vec_int->N-1; i > index; --i)
        p_vec_int->arr[i] = p_vec_int->arr[i-1];
    p_vec_int->arr[index] = new_data;
    return(SUCCESS);
}

int pop_back(struct vector_int* p_vec_int, int* pback_data)
{
    if(p_vec_int->N == 0)
        return(VEC_EMPTY);
    
    *pback_data = p_vec_int->arr[p_vec_int->N-1];
    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N - 1) * sizeof(int));
    if(p_vec_int->arr == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }
    p_vec_int->N -=1;
    return(SUCCESS);
}

int pop_front(struct vector_int* p_vec_int, int* pfront_data)
{
    int i;

    if(p_vec_int->N == 0)
        return(VEC_EMPTY);
    
    *pfront_data = p_vec_int->arr[0];
    for(i = 1; i <= p_vec_int->N-1; i++)
        p_vec_int->arr[i-1] = p_vec_int->arr[i];
    
    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N-1) * sizeof(int));
    if(p_vec_int->arr == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_vec_int->N -=1;
    return(SUCCESS);
}

int pop_at_index(struct vector_int* p_vec_int, size_t index, int* pdata)
{
    int i;

    if(index > p_vec_int->N-1)
        return(VEC_INVALID_INDEX);
    
    *pdata  = p_vec_int->arr[index];
    for(i = index+1; i < p_vec_int->N; i++)
        p_vec_int->arr[i-1] = p_vec_int->arr[i];
    p_vec_int->arr = (int*)realloc(p_vec_int->arr, (p_vec_int->N-1) * sizeof(int));
    if(p_vec_int->arr == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_vec_int->N -=1;
    return(SUCCESS);
}

void show(struct vector_int* p_vec_int, const char* msg)
{
    int i;
        if(msg != NULL)
            puts(msg);

    for(i = 0; i < p_vec_int->N; i++)
        printf("p_vec_int->arr[%d]:%d\n", i, p_vec_int->arr[i]);
}


void destroy(struct vector_int* p_vec_int)
{
    free(p_vec_int->arr); 
    free(p_vec_int); 
    p_vec_int = NULL; 
}

int get_index(struct vector_int* p_vec_int, size_t index, int* p_data)
{
    if(index >= p_vec_int->N)
        return(VEC_INVALID_INDEX);
    
    *p_data = p_vec_int->arr[index];
    return(SUCCESS);
}

int set_index(struct vector_int* p_vec_int, size_t index, int new_data)
{
    if(index >= p_vec_int->N)
        return(VEC_INVALID_INDEX);
    
    p_vec_int->arr[index] = new_data;
    return(SUCCESS);
}

size_t get_size(struct vector_int* p_vec)
{
    return(p_vec->N);
}