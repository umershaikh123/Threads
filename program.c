#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *threadFunc1()
{
    printf("Running Thread 1 \n");
    for (int i = 0; i < 1000; i++)
    {
        printf("Thread 1  count %d\n", i);
    }
}

void *threadFunc2()
{
    printf("Running Thread 2 \n");
    for (int i = 0; i < 1000; i++)
    {
        printf("Thread 2  count %d\n", i);
    }
}

/*
This program illustrates the parallelism between two threads.
however only one thread is being executed at a time but both of them are switching
*/
int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int iret1 = pthread_create(&t1, NULL, &threadFunc1, NULL);
    int iret2 = pthread_create(&t2, NULL, &threadFunc2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);
    return 0;
}