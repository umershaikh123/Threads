#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to be executed by each thread
void *thread_function(void *arg)
{
    int thread_id = *((int *)arg);
    printf("Thread %d is running\n", thread_id);
    // Perform some task
    printf("Thread %d is exiting\n", thread_id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    // Create threads
    for (i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;
        int result = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
        if (result)
        {
            printf("Error: pthread_create() failed with code %d\n", result);
            return -1;
        }
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have exited\n");

    return 0;
}
