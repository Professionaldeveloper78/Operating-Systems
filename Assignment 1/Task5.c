#include <stdio.h>
#include <pthread.h>

typedef struct {
    int student_id;
    char name[50];
    float gpa;
} Student;

int deanCount = 0;          // shared counter
pthread_mutex_t lock;       // for thread-safe increment

void* checkDeanList(void* arg) {
    Student* s = (Student*)arg;

    printf("ID: %d | Name: %s | GPA: %.2f\n", s->student_id, s->name, s->gpa);

    if (s->gpa >= 3.5) {
        printf("-> %s is on the Dean's List!\n", s->name);
        pthread_mutex_lock(&lock);
        deanCount++;
        pthread_mutex_unlock(&lock);
    } else {
        printf("-> %s is not on the Dean's List.\n", s->name);
    }

    return NULL;
}

int main() {
    pthread_t t[3];
    Student students[3] = {
        {121, "Ahmad", 3.8},
        {122, "Abdul", 3.2},
        {123, "Hina", 3.5}
    };

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, checkDeanList, &students[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    printf("\nTotal students on Dean's List: %d\n", deanCount);

    pthread_mutex_destroy(&lock);
    return 0;
}
