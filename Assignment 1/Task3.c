//Abdul Rehman
//23-ntu-cs-1122
#include <stdio.h>
#include <pthread.h>

void* calculate(void* arg) {
    int num = *(int*)arg;  // Get the integer value passed to the thread

    printf("Thread: Number = %d\n", num);
    printf("Thread: Square = %d\n", num * num);
    printf("Thread: Cube   = %d\n", num * num * num);

    pthread_exit(NULL);  // end
}

int main() {
    pthread_t thread;
    int number;

    // Input from user
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Create thread
    if (pthread_create(&thread, NULL, calculate, (void*)&number) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the thread to complete
    pthread_join(thread, NULL);

    printf("Main thread: Work completed.\n");

    return 0;
}

