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
int insert_before(struct node* p_head_node, int new_data, int e_data);
int insert_after(struct node* p_head_node, int new_data, int e_data);

int get_end(struct node* p_head_node, int* p_end_data);
int get_start(struct node* p_head_node, int* p_start_data);
int pop_start(struct node* p_head_node, int* p_start_data);
int pop_end(struct node* p_head_node, int* p_end_data);

int remove_start(struct node* p_head_node);
int remove_end(struct node* p_head_node);
int remove_data(struct node* p_head_node, int r_data);
size_t get_length(struct node* p_head_node);

int find_data(struct node* p_head_node, int data);
int is_list_empty(struct node* p_head_node);

void show_list(struct node* p_head_node, const char* msg);
void destroy_list(struct node* p_head_node);

int main(void)
{

}

struct node* create_list(void)
{
    struct node* p_head_node = NULL;

    p_head_node = (struct node*)malloc(sizeof(struct node));
    if(p_head_node == NULL)
    {
        puts("Error in allocating the memory");
        exit(EXIT_FAILURE);
    }

    p_head_node->next = NULL;
    p_head_node->data = 0;

    return(p_head_node);
}

void insert_start(struct node* p_head_node, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*) malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("Error in allocating the memory");
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

    p_new_node = (struct node*) malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("Error in allocating the memory");
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

    pe_node = p_head_node->next;
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

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node->next = pe_node->next;
    pe_node->next = p_new_node;
    return(SUCCESS);
}

int insert_before(struct node* p_head_node, int e_data, int new_data)
{
    
}