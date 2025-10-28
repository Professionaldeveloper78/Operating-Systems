//Abdul Rehman
//23-ntu-cs-1122
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* work(void* arg) {
    int num = *(int*)arg;               // Thread number
    printf("Thread %d started (ID: %lu)\n", num, pthread_self());

    int t = rand() % 3 + 1;             // Random sleep time (1–3 sec)
    sleep(t);

    printf("Thread %d finished after %d seconds\n", num, t);
    return NULL;
}

int main() {
    pthread_t t[5];
    int i, num[5];
    srand(time(0));                     // Seed random number

    for(i = 0; i < 5; i++) {
        num[i] = i + 1;
        pthread_create(&t[i], NULL, work, &num[i]);
    }

    for(i = 0; i < 5; i++) {
        pthread_join(t[i], NULL);
    }

    printf("All threads done.\n");
    return 0;
}
