#include<stdio.h>
#include<stdlib.h>

#define TRUE                1
#define FALSE               0
#define SUCCESS             1
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

struct node{
    int data;
    struct node* next;
};

struct node* create_list(void);
void insert_start(struct node* p_head_node, int new_data);
void insert_end(struct node* p_head_node, int new_data);
int insert_after(struct node* p_head_node, int e_data, int new_data);
int insert_before(struct node* p_head_node, int e_data, int new_data);

int get_start(struct node* p_head_node, int* p_start);
int get_end(struct node* p_head_node, int* p_end);
int pop_start(struct node* p_head_node, int* p_start_data);
int pop_end(struct node* p_head_node, int* p_end_data);

int remove_start(struct node* p_head_node);
int remove_end(struct node* p_head_node);
int remove_data(struct node*  p_head_node, int r_data);
size_t get_length(struct node* p_head_node);

int find(struct node* p_head_node, int data);
int is_empty(struct node* p_head_node);

void show_list(struct node* p_head_node, const char* msg);
void destroy_list(struct node* p_head_node);

int main(void)
{
    struct node* my_list = NULL;
    int data;
    int* data_1 = NULL;
    int status;

    my_list = create_list();
    show_list(my_list, "Empty_List");

    for(data = 10; data < 50; data += 10)
        insert_end(my_list, data);
    show_list(my_list, "After Insert End");

    for(data = 5 ; data<= 25; data += 5)
        insert_start(my_list, data);
    show_list(my_list, "After insert_start()");

    status =  get_start(my_list, &data);
    printf("start = %d\n", data);
    
    if(status == SUCCESS)
    {
        status =  get_end(my_list, &data);
        printf("end = %d\n", data);
    }

    return(0);
}

struct node* create_list(void)
{
    struct node* p_head = NULL;

    p_head = (struct node*)malloc(sizeof(struct node));
    if(p_head == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_head->data;
    p_head->next =NULL;

    return(p_head);
}

void insert_start(struct node* p_head_node, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL){
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
        return(LIST_DATA_NOT_FOUND);
    
    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->next = pe_node->next;
    pe_node->next = p_new_node;
    return(SUCCESS);
}


int insert_before(struct node* p_head_node, int e_data, int new_data)
{
    struct node* p_new_node =NULL;
    struct node* pe_node_prev = NULL;
    struct node* pe_node =NULL;

    pe_node_prev = p_head_node;
    pe_node = p_head_node->next;
    while(pe_node != NULL)
    {
        if(pe_node->data == e_data);
          break;
        pe_node_prev = pe_node;
        pe_node = pe_node->next;
    }

    if(pe_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node->next = pe_node_prev->next;
    pe_node_prev->next = p_new_node;

    return(SUCCESS);
}

int get_start(struct node* p_head_node, int* p_start)
{
    if(p_head_node->next == NULL)
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
    while(p_run != NULL)
    {
        p_run = p_run->next;
    }

    *p_end = p_run->data;
    return(SUCCESS);
}

int pop_start(struct node* p_head_node, int* p_start_data)
{
    struct node* p_start_node = NULL;
    if(p_head_node->next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_head_node->next->data;

    p_start_node = p_head_node->next;
    p_head_node->next = p_start_node->next;
    free(p_start_node);
    return(SUCCESS);
}

int pop_end(struct node* p_head_node, int* p_end_data)
{
    struct node* end_node = NULL;
    struct node* end_node_prev = NULL;

    if(p_head_node->next == NULL)
        return(LIST_EMPTY);
    
    end_node_prev = p_head_node;
    end_node = p_head_node->next;
    while(end_node != NULL)
    {
        end_node_prev = end_node;
        end_node = end_node->next;
    }

    *p_end_data = end_node->data;
    free(end_node);
    end_node = NULL;
    end_node_prev->next = NULL;
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
    struct node* p_end_node_prev = NULL;

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

    p_end_node->next = NULL;
    return(SUCCESS);
}

int remove_data(struct node* p_head_node, int r_data)
{
    struct node* p_remove = NULL;
    struct node* p_remove_prev = NULL;

    p_remove_prev = p_head_node;
    p_remove = p_head_node->next;

    while(p_remove != NULL)
    {
        p_remove_prev = p_remove;
        p_remove = p_remove->next;
    }

    if(p_remove == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    p_remove_prev->next = p_remove->next;
    free(p_remove);
    p_remove = NULL;
    return(SUCCESS);
}

size_t get_length(struct node* p_head_node)
{
    int L = 0;
    struct node* p_run = NULL;

    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        L = L + 1;
        p_run = p_run->next;
    }

    return(L);
}

int find(struct node* p_head_node, int f_data)
{
    struct node* p_run = NULL;

    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        if(p_run->data == f_data)
            return(TRUE);
        p_run = p_run->next;
    }

    return(FALSE);
}

int is_empty(struct node* p_head_node)
{
    return(p_head_node->next != NULL);
}

void show_list(struct node* p_head_node, const char* msg)
{
    struct node* p_run = NULL;
    if(msg)
        puts(msg);

    puts("[START->]");
    p_run = p_head_node;
    while(p_run->next != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    puts("<-[END]");
}

void destroy_list(struct node* p_head_node)
{
    struct node* p_run_next = NULL;
    struct node* p_run = NULL;

    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_head_node);
    p_head_node = NULL;
}