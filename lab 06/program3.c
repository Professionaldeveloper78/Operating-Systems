#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_ITERATIONS 100000
// Shared variables
int turn;
int flag[2];
int count = 0;

// Critical section function
void critical_section(int process)
{
    if (process == 0)
    {

        for (int i = 0; i < NUM_ITERATIONS; i++)
            count--;
    }
    else
    {
        for (int i = 0; i < NUM_ITERATIONS; i++)
            count++;
    }
}
void *process0(void *arg)
{
    flag[0] = 1;
    turn = 1;
    while (flag[1] == 1 && turn == 1)
    {
        // Busy wait
    }
    critical_section(0);
    flag[0] = 0;
    pthread_exit(NULL);
}
void *process1(void *arg)
{

    flag[1] = 1;
    turn = 0;
    while (flag[0] == 1 && turn == 0)
    {

    }
    critical_section(1);
    // Exit section
    flag[1] = 0;
    // sleep(1);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread0, thread1;

    // Initialize shared variables
    flag[0] = 0;
    flag[1] = 0;
    turn = 0;
    // Create threads
    pthread_create(&thread0, NULL, process0, NULL);
    pthread_create(&thread1, NULL, process1, NULL);

    // Wait for threads to finish
    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);

    printf("Final count: %d\n", count);

    return 0;
}