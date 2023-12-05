#include<stdio.h>
#include<stdlib.h> 

#define SUCCESS             1
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

struct node{
    struct node* prev;
    struct node* next;
    int data;
};

struct node* get_node(int new_data);
void* xcalloc(int nr_elements, int size_per_element);

void generic_insert(struct node* beg,
                    struct node* mid,
                    struct node* end);
void generic_delete(struct node* delete_node);

void* xcalloc(int nr_elements, int size_per_element){
    void* p_node = NULL;

    p_node = calloc(nr_elements, size_per_element);
    if(p_node == NULL){
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    return(p_node);
}

struct node* get_node(int new_data){
    struct node* new_node = NULL;

    new_node = xcalloc(1, sizeof(struct node));
    new_node->data = new_data;

    return(new_node);
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

void insert_start(struct node* head_node, int new_data){
    generic_insert(
                    head_node,
                    get_node(new_data),
                    head_node->next
                );
}

void insert_end(struct node* head_node, int new_data){
    generic_insert(
                    head_node->prev,
                    get_node(new_data),
                    head_node
                 );
}

void insert_after(struct node* head_node, int e_data, int new_data){
    struct node* e_node = NULL;

    if()
        return(LIST_DATA_NOT_FOUND);
    
    e_node = generic_insert
}