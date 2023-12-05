#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main(void)
{
    struct node* p_node = NULL;
    struct node* p_run = NULL;

    p_node = (struct node*)malloc(sizeof(struct node));
    if(p_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_node->data = 0;
    p_node->next = NULL;

    p_node->next = (struct node*)malloc(sizeof(struct node));
    if(p_node->next == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_node->next->data = 0;
    p_node->next->next = NULL;

    p_node->next->next = (struct node*)malloc(sizeof(struct node));
    if(p_node->next->next == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }
}