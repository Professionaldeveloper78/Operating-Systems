//Abdul Rehman
//23-ntu-cs-1122


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Thread function
void* greet(void* arg) {
    char* name = (char*)arg;  // Receive the argument 
    printf("Thread says: Hello, %s! Welcome to the world of threads.\n", name);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    char name[50];

    // Get user name
    printf("Enter your name: ");
    scanf("%s", name);

    // Create thread
    printf("Main thread: Waiting for greeting...\n");
    if (pthread_create(&thread, NULL, greet, (void*)name) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the created thread to complete
    pthread_join(thread, NULL);

    printf("Main thread: Greeting completed.\n");
    return 0;
}
