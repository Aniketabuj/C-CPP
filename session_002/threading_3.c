#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

struct inpu_data{
    int ia[5];
    double da[5];
};

sturct output_data{
    int i_sum;
    double d_sum;
};

void* compute_thread(void* args);

int main(void){

    pthread_t thread_id;
    struct input_data* input = NULL;
    struct output_data* output = NULL;

    input = (struct input_data*)malloc(sizeof(struct input_data));
    if(input == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 5; i++){
        input->arr[i] = (i +1 ) * 100;
        input->da[i] = ((i + 100) * 100)/7.0
     }
}