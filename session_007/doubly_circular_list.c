#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define TRUE 1
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node list;

struct node* get_node(int new_data);
void* xcalloc(int nr_elements, int size_per_element);
void generic_insert(list* beg, list* mid, list* end);
void generic_delete(list* delete_node);
struct node* search_node(list* head_node, int search_data);

struct node* create_list(void);

void show(list* head_node, const char* msg);
int insert_start(list* head_node, int new_data);
int insert_end(list* head_node, int new_data);
int get_length(list* head_node);

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
        
    status = get_length(list);
        printf("Length of list is %d\n", status);
    

    return(0);
}

struct node* get_node(int new_data){
	struct node* p_node = NULL; 

	p_node = xcalloc(1, sizeof(struct node)); 
	p_node->data = new_data; 

	return (p_node); 
}

void* xcalloc(int nr_elements, int size_per_element){
	void* ptr = NULL; 

	ptr = calloc(nr_elements, size_per_element); 
	if(ptr == NULL){
		puts("Error in allocating memory"); 
		exit(EXIT_FAILURE);
	}

	return (ptr); 
}

void generic_insert(list* beg, list* mid, list* end){
    mid->next = end;
    mid->prev =beg;
    beg->next = mid;
    end->prev = mid;
}

void generic_delete(list* delete_node){
    delete_node->prev->next = delete_node->next;
    delete_node->next->prev = delete_node->prev;
    free(delete_node);
}

int is_empty(list* head_node){
    return(head_node->next == head_node && head_node->prev == head_node);
}

struct node* search_node(list* head_node, int search_data){
    list* run = NULL;

    for(run = head_node->next; run != head_node; run = run->next)
        if(run->data == search_data)
            return(run);
    
    return(NULL);
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

int get_start(list* head_node, int* p_start_data){
    if(is_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    *p_start_data = head_node->next->data;
    return(SUCCESS);
}

int get_end(list* head_node, int* p_end_data){
    if(is_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    *p_end_data = head_node->prev->data;
    return(SUCCESS);
}

int pop_start(list* head_node, int* p_start_data){
    if(is_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    *p_start_data = head_node->next->data;
    generic_delete(head_node->next);
    return(SUCCESS);
}

int pop_end(list* head_node, int* p_end_data){
    if(is_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    
    *p_end_data = head_node->prev->data;
    generic_delete(head_node->prev);
    return(SUCCESS);
}

int remove_start(list* head_node){
    if(is_empty(head_node) == TRUE)
        return(LIST_EMPTY);
    generic_delete(head_node->next);
    return(SUCCESS);
}

int remove_end(list* head_node){
    if(is_empty(head_node) == TRUE)
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
    struct node* run = NULL;

    L= 0;
    for(run = head_node->next; run != NULL; run = run->next)
        ++L;
    
    return(L);
}

void show(list* head_node, const char* msg){
    struct node* run = NULL;

    if(msg)
        puts(msg);
    
    printf("[START]<->");
    for(run = head_node->next; run != head_node; run = run->next)
        printf("[%d]<->", run->data);
    
    puts("[END]");
}

int destroy_list(struct node** pp_node){
    struct node* head_node = NULL;
    struct node* run = NULL;
    struct node* run_next = NULL;

    head_node = *pp_node;
    for(run = head_node->next; run !=  NULL; run = run_next){
        run = run->next;
        free(run);
    }

    free(head_node);
    head_node = NULL;

    return(SUCCESS);
}