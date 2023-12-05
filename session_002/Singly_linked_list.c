#include<stdio.h>
#include<stdlib.h>

#define SUCCESS             1
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3
#define TRUE                1
#define FALSE               0

struct node{
    int data;
    struct node* next;
};

struct node* create_list(void);
void insert_start(struct node* p_head_node, int new_data);
void insert_end(struct node* p_head_node, int new_data);
int insert_before(struct node* p_head_node, int e_data, int new_data);
int insert_after(struct node* p_head_node, int e_data, int new_data);

int pop_start(struct node* p_head_node, int* p_start_data);
int pop_end(struct node* p_head_node, int* p_end_data);
int get_end(struct node* p_head_node, int* end_data);
int get_front(struct node* p_head_node, int* front_data);


int remove_start(struct node* p_head_node);
int remove_end(struct node* p_head_node);
int remove_data(struct node* p_head_node, int r_data);
size_t get_length(struct node* p_head_node);

int find(struct node* p_head_node, int f_data);
int is_list_empty(struct node* p_head_node);

void show_list(struct node* p_head_node, const char* msg);
void destroy_list(struct node* p_head_node);

int main(void)
{
    struct node* my_list = NULL;
    int data = 0;
    int status;

    my_list = create_list();
    show_list(my_list, "Empty_list");

    for(data = 10; data < 50; data = data + 10)
        insert_end(my_list, data);
    show_list(my_list, "After insert_end");

    
    for(data = 5 ; data<= 25; data += 5)
        insert_start(my_list, data);
    show_list(my_list, "After insert_start()");

    status =  get_start(my_list, &data);
    printf("start = %d\n", data);

    status =  get_end(my_list, &data);
    printf("end = %d\n", data);

    puts("Call to find to find 50");
    status = find(my_list, 50);
    printf("Status = %d\n", status);
    
    status = insert_after(my_list, 30, 50);
    if(status == SUCCESS)
        show_list(my_list, "After call to insert_after");

    status = insert_after(my_list, 40, 60);
    if(status == SUCCESS)
        show_list(my_list, "After call to insert_after");
     
    puts("Call to find to find 50");
    status = find(my_list, 50);
    printf("Status = %d\n", status);

    status = insert_before(my_list, 70, 35);
    if(status == SUCCESS)
        show_list(my_list, "After call to insert_before");
        
    return(0);
}

struct node* create_list(void)
{
    struct node* head_node = NULL;

    head_node = (struct node*)malloc(sizeof(struct node));
    if(head_node == NULL)
    {
        puts("Error in allocating memmory");
        exit(EXIT_FAILURE);
    }

    head_node->next = NULL;
    head_node->data = 0;

    return(head_node);
}

void insert_start(struct node* p_head_node, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(int));
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node->next = p_head_node->next;
    p_head_node->next = p_new_node;
}

void insert_end(struct node* p_head_node, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_run = p_head_node;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    p_run->next = p_new_node;
}

int insert_after(struct node* p_head_node, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* pe_node = NULL;

    pe_node = p_head_node;
    while(pe_node->next != NULL)
    {
        if(pe_node->data == e_data)
            break;
        pe_node = pe_node->next;
    }

    if(pe_node == NULL)
    {
        return(LIST_DATA_NOT_FOUND);
    }

    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node->next = pe_node->next;
    pe_node->next = p_new_node;

    return(SUCCESS);
}

int insert_before(struct node* p_head_node, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* pe_node_prev = NULL;
    struct node* pe_node = NULL;

    pe_node_prev = p_head_node;
    pe_node = p_head_node->next;

    while(pe_node != NULL)
    {
        if(pe_node->data == e_data)
            break;
        pe_node_prev = pe_node;
        pe_node = pe_node->next;
    }

    if(pe_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    p_new_node = (struct node*)malloc(sizeof(int));
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node = pe_node_prev->next;
    pe_node_prev->next = p_new_node;
    
    return(SUCCESS);
}

int get_start(struct node* p_head_node, int* p_start)
{
    if(p_head_node == NULL)
        return(LIST_EMPTY);
    
    *p_start = p_head_node->next->data;
    return(SUCCESS);
}

int get_end(struct node* p_head_node, int* p_end)
{
    struct node* p_run = NULL;
    if(p_head_node->next == NULL)
    return(LIST_EMPTY);

    p_run = p_head_node->next;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    *p_end = p_run->data;
    return(SUCCESS);
}


int pop_start(struct node* p_head_node, int* p_start_data)
{
    struct node* p_node = NULL;
    if(p_head_node->next == NULL)
        return(LIST_EMPTY);
    
    *p_start_data = p_head_node->next->data;

    p_node= p_head_node->next;
    p_head_node->next = p_node->next;

    free(p_start_data);
    p_start_data = NULL;

    return(SUCCESS);
}

int pop_end(struct node* p_head_node, int* p_end_data)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;

    if(p_head_node->next == NULL)
        return(LIST_EMPTY);
    
    p_run_prev = p_head_node;
    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    
    *p_end_data = p_run->data;
    free(p_end_data);
    p_end_data = NULL;

    p_run_prev->next = NULL;
    return(SUCCESS);
}

int remove_start(struct node* p_head_node)
{
    struct node* p_run = NULL;

    if(p_head_node->next == NULL)
        return(LIST_EMPTY);
    
    p_run = p_head_node->next;
    p_head_node->next = p_run->next;

    free(p_run);
    p_run = NULL;
    return(SUCCESS);
}

int remove_end(struct node* p_head_node)
{
    struct node* p_end_node = NULL;
    struct node* p_end_node_prev;

    if(p_head_node->next == NULL)
        return(LIST_EMPTY);
    
    p_end_node_prev = p_head_node;
    p_end_node = p_head_node->next;
    while(p_end_node != NULL)
    {
        p_end_node_prev = p_end_node;
        p_end_node = p_end_node->next;
    }

    free(p_end_node);
    p_end_node = NULL;

    p_end_node_prev->next = NULL;
    return(SUCCESS);
}

int remove_data(struct node* p_head_node, int r_data)
{
    struct node* r_node = NULL;
    struct node* r_node_prev = NULL;

    r_node_prev = p_head_node;
    r_node = p_head_node->next;

    while(r_node != NULL)
    {
        if(r_node->data == r_data)
            break;
        r_node_prev = r_node;
        r_node = r_node->next;
    }

    if(r_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    r_node_prev->next = r_node->next;
    free(r_node);
    r_node = NULL;

    return(SUCCESS);
}

int find(struct node* p_head_node, int data)
{
    struct node* p_run = NULL;

    if(p_head_node->next == NULL)
        return(LIST_EMPTY);
    
    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        if(p_run->data == data)
            return(TRUE);
        p_run = p_run->next;
    }

    return(FALSE);
}

size_t get_length(struct node* p_head_node)
{
    size_t L = 0;
    struct node* p_run = NULL;
    if(p_head_node->next == NULL)
        return(LIST_EMPTY);
    
    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        L = L+1;
        p_run = p_run->next;
    }

    return(L);
}

void show_list(struct node* p_head_node, const char* msg)
{
    struct node* p_run = NULL;

    if(msg)
        puts(msg);
    
    printf("[START]->");

    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }

    puts("<-[END]");
}

int is_list_empty(struct node* p_head_node)
{
    return(p_head_node->next != NULL);
}

void destroy(struct node* p_head_node)
{
    struct node* p_run = NULL;
    struct node* p_run_next = NULL;

    p_run = p_head_node->next;

    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run->next;
    }

    free(p_head_node);
    p_head_node = NULL;
}