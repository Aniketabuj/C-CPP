#include<stdio.h>
#include<stdlib.h>

#define SUCCESS                 1
#define LIST_DATA_NOT_FOUD      2
#define LIST_EMPTY              3

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* get_node(int new_data);
void* xcalloc(int nr_elements, int size_per_element);
void generic_insert(struct node* beg, 
                    struct node* mid,
                    struct node* next);
void generic_delete(struct node* delete_node);

void* xcalloc(int nr_elements, int size_per_element){
    void* ptr = NULL;

    ptr = calloc(nr_elements, size_per_element);
    if(ptr == NULL)
    {
        puts("Error in allocating memoer");
        exit(EXIT_FAILURE);
    }
    return(ptr);
}

struct node* get_node(int new_data){
    struct node* p_node = NULL;

    p_node = xcalloc(1, sizeof(struct node));

    p_node->data = new_data;

    return(p_node);
}

void generic_insert(struct node* beg,
                    struct node* mid,  
                    struct node* end){
    mid->next = end;
    mid->prev = beg;
    beg->next = mid;
    end->prev = mid;
                    }

    void generic_delete(struct node* delete_node){
        delete_node->prev->next = delete_node->next;
        delete_node->next->prev = delete_node->prev;
        free(delete_node);
    }