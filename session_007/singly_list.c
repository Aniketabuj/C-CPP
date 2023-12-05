#include<stdio.h>
#include<stdlib.h>

#define SUCESS              1
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

struct node
{
    int data;
    struct node* next;
};

struct node* create_list(void);
void insert_end(struct node* p_head_node, int new_data);
void insert_start(struct node* p_head_node, int new_data);
int  insert_after(struct node* p_head_node, int e_data, int new_data);
int insert_before(struct node* p_head_node, int e_data, int new_data);

int main(void)
{

}

struct node* create_list(void)
{
    struct node* p_head_node = NULL;

    p_head_node = (struct node*)malloc(sizeof(struct node));
    if(p_head_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_head_node->data = 0;
    p_head_node->next = NULL;
    return(p_head_node);
}

void insert_start(struct node* p_head_node, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory");
        exit("EXIT_FAILURE");
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
    while(p_run != NULL)
    {
        p_run = p_run->next;
    }

    p_run->next = p_new_node;
}

