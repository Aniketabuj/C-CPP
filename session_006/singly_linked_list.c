#include<stdio.h>
#include<stdlib.h>

#define SUCCESS              1
#define LIST_DATA_NOT_FOUND  2
#define LIST_EMPTY           3

struct node
{
    int data;
    struct node* next;
};

struct node* create_list(void);
void insert_start(struct node* p_head_node, int data);
void insert_end(struct node* p_head_node, int data);
int insert_after(struct node* p_head_node, int e_data, int new_data);
int insert_before(struct node* p_head_node, int e_data, int new_data);

int get_start(struct node* p_head_node, int* p_start_node);
void show_list(struct node* p_head_node, const char* msg);
void destroy_list(struct node* p_head_node);

int main(void)
{
    struct node* my_list = NULL;
    int data;

    my_list = create_list();
    show_list(my_list, "Empty_list");

    for(data = 10; data < 50; data += 10)
        insert_end(my_list, data);
    show_list(my_list, "After insert_end()");

    for(data = 5 ; data<= 25; data += 5)
        insert_start(my_list, data);
    show_list(my_list, "After insert_start()");


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
    
    p_new_node = (struct node*)malloc(sizeof(struct node));
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
        p_run = p_run->next;
    
    p_run->next = p_new_node;
}

int insert_after(struct node* p_head_node, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* pe_node = NULL;

    pe_node = p_head_node->next;
    while(pe_node != NULL)
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

/*int insert_after(struct node* p_head_node, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* pe_node = NULL;

    pe_node = p_head_node->next;
    while(pe_node != NULL)
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
}
*/
int insert_before(struct node* p_head_node, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* pe_node_before = NULL;
    struct node* pe_node = NULL;
    
    pe_node_before = p_head_node;
    pe_node = p_head_node->next;
    while(pe_node != NULL)
    {
        if(pe_node->data == e_data)
        break;
        pe_node_before = pe_node;
        pe_node = pe_node->next;
    }

    if(pe_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node->next = pe_node_before->next;
    pe_node_before->next = p_new_node;

    return(SUCCESS);
}

void show_list(struct node* p_head_node, const char* msg)
{
    struct node* p_run = NULL;

    if(msg)
        puts(msg);
    
    printf("[START->]");
    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }

    puts("[<-END]");
}
/*
int insert_before(struct node* p_head_node, int e_data, int new_data)
{
    struct node* pe_node_prev = NULL;
    struct node* pe_node =NULL;
    struct node* p_new_node = NULL;

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
}

int insert_after(struct node* p_head_node, int e_data, int new_data)
{
    struct node* pe_node = NULL;
    struct node* p_new_node = NULL;

    pe_node = p_head_node->next;
    while(pe_node != NULL)
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
        puts("Error ina llocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node->next = pe_node->next;
    pe_node->next = p_new_node;
}

int insert_before(struct node* p_head_node, int e_data, int new_data)
{
    struct node* pe_node = NULL;
    struct node* pe_node_prev = NULL;
    struct node* p_new_node = NULL;

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
void show_list(struct node* p_head_node, const char* msg)
{
    struct node* p_run = NULL;

    if(msg)
        puts(msg);
    
    printf("[START->]");
    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }

    puts("[<-END]");
}

void destroy_list(struct node* p_head_node)
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
}

int get_start(struct node* p_head_node, int* p_start_data)
{
    if(p_head_node->next == NULL)
        return(LIST_EMPTY);
    
    *p_start_data = p_head_node->next->data;
    return(SUCCESS);
}

int insert_after(struct node* p_head_node, int e_data, int new_data)
{
    struct node* pe_node  = NULL;
    struct node* p_new_node = NULL;

    pe_node = p_head_node->next;
    while(pe_node != NULL){
        if(pe_node->data == e_data)
            break;
        pe_node = pe_node->next;
    }

    if(pe_node == NULL)
        return(LIST_DATA_NOT_FOUND);

    p_new_node = (int*)malloc(sizeof(int));
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
    struct node* pe_node_prev = NULL;
    struct node* pe_node = NULL;
    struct node* p_new_node = NULL;

    pe_node_prev = p_head_node;
    pe_node = p_head_node->next;
    while(pe_node !=NULL)
    {
        if(pe_node->data == e_data)
            break;
        pe_node_prev = pe_node;
        pe_node = pe_node->next;
    }

    if(pe_node == NULL)
        return(LIST_DATA_NOT_FOUND);

    p_new_node = (int*)malloc(sizeof(int));
    if(p_new_node == NULL)
    {
        puts("Error in alocating memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node->next = pe_node_prev->next;
    pe_node_prev->next = p_new_node;
    return(SUCCESS);
}
*/