#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

struct node
{
    int data;
    struct node* next;

};

struct node
{
    int data;
    struct node* next;

};

struct node
{
    int data;
    struct node* next;
};

struct node
{
    int data;
    struct node* next;

};

struct node
{
    int data;
    struct node* next;
};

struct node
{
    int data;
    struct node* next;
};

struct node
{
   int data;
   struct node* next;
};

struct node* get_node(int new_data)
{
    struct node* p_new_node = NULL;
    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("Error in aallocating memory");
        exit("EXIT_FAILURE");
    }

    p_new_node->data = new_data;
    p_new_node->next =NULL;

    return(p_new_node);
}

struct node* get_node(int new_data)
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

    return (p_new_node); 
}

struct node* get_node(int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node ==NULL)
    {
        puts("Error in allocating in memory");
        exit(EXIT_FAILURE);
    }

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return(p_new_node);
}