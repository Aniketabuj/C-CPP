#include<pthread.h>

void* thread_entry_function(void* args);

int main(void)
{
    pthread_t thread_id;

    pthread_create(
                    &thread_id,
                    NULL,
                    thread_entry_function,
                    NULL
    );

    pthread_join(thread_id, NULL);
}