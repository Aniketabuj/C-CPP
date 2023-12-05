#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef struct node list;

struct node{
    int data;
    list* prev;
    list* next;
};

struct node* get_node(int new_data);
void* xcalloc(int nr_elements, int size_per_element);
void generic_insert(list* beg, list* mid, list* end);
void generic_delete(list* head_node);
struct node* search_node(list* head_node, int search_data);

struct node* create_list(void);
void destroy_list(list** pp_node);

int insert_start(list* head_node, int new_data);
int insert_end(list* head_node, int new_data);
int insert_after(list* head_node, int e_data, int new_data);
int insert_before(list* head_node, int e_data, int new_data);

int get_start(list* head_node, int* p_start_data);
int get_end(list* head_node, int* p_end_data);
int pop_start(list* head_node, int* p_start_data);
int pop_end(list* head_node, int* p_end_data);

int remove_start(list* head_node);
int remove_end(list* head_node);
int remove_data(list* head_node, int r_data);

int get_length(list* head_node);
int find(list* head_node, int find_data);
int is_list_empty(list* head_node);
void show(list* head_node, const char* msg);

int main(void){
    list* list = NULL;
    int status;
    int data;

    list = create_list();
    show(list, "Empty_list");

    for(data = 10; data < 60; data += 10)
        insert_start(list, data);
    show(list, "After insert_start");

    for(data = 5; data < 55; data += 10)
        insert_end(list, data);
    show(list, "After insert_end");

    status = insert_after(list, 35, 40);
    if(status == SUCCESS){
        show(list, "List after insert_after");
    }

    status = insert_before(list, 35, 30);
    if(status == SUCCESS)
        show(list, "List After insert_before");
    
    status = get_start(list, &data);
        printf("Data = %d\n", data);
    
    status = get_end(list, &data);
        printf("Data = %d\n" ,data);
    
    status = pop_start(list, &data);
        if(status == SUCCESS){
            show(list, "After pop_start");
        }
    status = pop_end(list, &data);
    if(status == SUCCESS){
       printf("Data = %d\n", data);
        show(list, "After pop_end");
    }

    status = remove_end(list);
        if(status == SUCCESS)
            show(list, "After remmove end");
    
    status = remove_data(list, 20);
        if(status == SUCCESS)
            show(list, "After remove_data");
    
     status = remove_start(list);
        if(status == SUCCESS)
            show(list, "After remmove end");
        
   // status = get_length(list);
    //    printf("Length of list is %d\n", status);
    
    status = find(list, 25);
        printf("data = %d\n", status);

    return(0);
}

struct node* get_node(int new_data){
    struct node* ptr = NULL;

    ptr = xcalloc(1, sizeof(struct node));
    ptr->data = new_data;
    return(ptr);
}

void* xcalloc(int nr_element, int size_per_element){
    list* ptr = NULL;

    ptr = (struct node*)calloc(nr_element, size_per_element);
    if(ptr == NULL){
        puts("Error in allocating yhe memory");
        exit(EXIT_FAILURE);
    }

    return(ptr);
}

void generic_insert(list* beg, list* mid, list* end){
    beg->next = mid;
    end->prev = mid;
    mid->next = end;
    mid->prev = beg;
}

void generic_delete(list* delete_node){
    delete_node->prev->next = delete_node->next;
    delete_node->next->prev = delete_node->prev;
    free(delete_node);
}

struct node* search_node(list* head_node, int search_data){
    list* run = NULL;

    for(run = head_node->next; run != head_node; run = run->next){
        if(run->data == search_data)
            return(run);
    }
    
    return(NULL);
}

int is_list_empty(list* head_node){
    return(head_node->next == head_node && head_node->prev == head_node);
}

struct node* create_list(void){
    list* head_node = NULL;

    head_node = get_node(-1);
    head_node->prev = head_node;
    head_node->next = head_node;

    return(head_node);
}

int insert_start(list* head_node, int new_data){
    generic_insert(head_node, get_node(new_data), head_node->next);
    return(SUCCESS);
}

int insert_end(list* head_node, int new_data){
    generic_insert(head_node->prev, get_node(new_data), head_node);
    return(SUCCESS);
}

int insert_after(list* head_node, int e_data, int new_data){
    list* e_node = NULL;
    e_node = search_node(head_node, e_data);
    if(e_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    generic_insert(e_node, get_node(new_data), e_node->next);
    return(SUCCESS);
}

int insert_before(list* head_node, int e_data, int new_data){
    list* e_node = NULL;
    e_node = search_node(head_node, e_data);
    if(e_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    generic_insert(e_node->prev, get_node(new_data), e_node);
    return(SUCCESS);
}

int get_start(list* head_node, int* get_start){
    if(is_list_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    *get_start = head_node->next->data;
    return(SUCCESS);
}

int get_end(list* head_node, int* get_end){
    if(is_list_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    *get_end = head_node->prev->data;
    return(SUCCESS);
}

int pop_start(list* head_node, int* p_start_data){
    if(is_list_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    *p_start_data = head_node->next->data;
    generic_delete(head_node->next);
    return(SUCCESS);
} 

int pop_end(list* head_node, int* p_end_data){
    if(is_list_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    *p_end_data = head_node->prev->data;
    generic_delete(head_node->prev);
    return(SUCCESS);
}

int remove_start(list* head_node){
    if(is_list_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    generic_delete(head_node->next);
    return(SUCCESS);
}

int remove_end(list* head_node){
    if(is_list_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    generic_delete(head_node->prev);
    return(SUCCESS);
}

int remove_data(list* head_node, int r_data){
    list* remove_node = NULL;

    remove_node = search_node(head_node, r_data);
    if(remove_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    generic_delete(remove_node);
    return(SUCCESS);
}

int get_length(list* head_node){
    int L;
    list* run =NULL;

    L = 0;

    run = head_node->next;
    while(run != NULL){
        ++L;
        run = run->next;
    }

    return(L);
}

int find(list* head_node, int find_data){
    list* search = NULL;
    if(is_list_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    
    search = search_node(head_node, find_data);
    if(search->data == find_data)
        return(TRUE);
    
    return(FALSE);
}

void show(list* head_node, const char* msg){
    list* run = NULL;

    if(msg)
        puts(msg);
    
    printf("[START}<->");
    run = head_node->next;
    while(run != head_node){
        printf("[%d]<->", run->data);
        run = run->next;
    }

    puts("[END]");
}

void destroy_list(list** pp_node){
    list* head_node = NULL;
    list* run = NULL;
    list* run_next = NULL;

    head_node = *pp_node;
    run = head_node->next;
    while(run != NULL){
        run = run_next;
        free(run);
        run = run->next;
    }

    free(head_node);
    head_node = NULL;
}