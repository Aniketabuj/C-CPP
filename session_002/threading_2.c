#include<stdio.h>
#include<pthread.h>

void* common_entry_function(void* args);

int main(void){
    pthread_t pthread_id_1, thread_id_2;

    pthread_create(
                &thread_id_1,
                NULL,
                common_entry_function,
                NULL
    );

    pthread_create(
            &thread_id_2,  
            NULL,
            common_entry_function,
            NULL
    )

    return(SUCCESS);
}

void* common_entry_function(void* args){
    while(TRUE){
        printf("Running thread = %lld\n", pthread_self());
    }
}