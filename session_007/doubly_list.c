#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define SUCCESS 1
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

typedef int data_t;
typedef struct node list_t;
typedef int status_t;
typedef int len_t;
typedef list_t node_t;

void create_list(void){
    return(get_node(0));
}

void* xmalloc(data_t size_of_element){
    node_t* p = NULL;

    p = malloc(size_of_element);
    if(p == NULL){
        puts("Error in allocating in memeory");
        exit(EXIT_FAILURE);
    }

    return(p);
}

node_t* get_node(data_t new_data){
    node_t* new_node = NULL;

    new_node = (node_t*)xmalloc(sizeof(node_t));

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return(new_node);
}

status_t  insert_start(list_t* p_list, data_t new_data){
    list_t* new_node = NULL;

    new_node = get_node(new_data);

    new_node->next = p_list->next;
    p_list->next = new_node;
    new_node->prev = p_list;

    return(SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data){
    list_t* new_node = NULL;
    list_t* run = NULL;

    run = p_list->next;
    while(run != NULL){
        run = run->next;
    }

    new_node = get_node(new_data);

    new_node->next = run->next;
    new_node->prev = run;
    run->next = new_node;

    return(SUCCESS);
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data){
    list_t* new_node = NULL;
    list_t* run_prev = NULL;
    list_t* run = NULL;

    run_prev = p_list;
    run = p_list->next;
    while(run != NULL){
        if(run->data == e_data)
            break;
        run_prev = run;
        run = run->next;
    }

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    new_node = get_node(new_data);

    new_node->next = run_prev->next;
    new_node->prev = run_prev;
    run_prev->next = new_node;
    return(SUCCESS);
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data){

}