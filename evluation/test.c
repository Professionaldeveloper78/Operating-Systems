/*Write a C program that:

Defines a structure containing:

Student ID (integer)

Student Name (string — max 50 chars)

Marks (float)

Grade (char — to be calculated by thread)

Creates an array of 3 student records with sample data.

Creates 3 threads — each thread receives one student structure and:

Determines the grade based on marks:

≥ 85 → Grade A

≥ 70 → Grade B

≥ 60 → Grade C

≥ 50 → Grade D

else → Grade F

Each thread prints the student's details (ID, Name, Marks, Grade).

The main thread waits for all threads to complete.*/


#include<stdio.h>   // declare the libraries for run basic command of c
#include<pthread.h> // declare the libraries for use the thread function
struct student {    //creat a class which can hold the attributes of student and class can creat in c with struct keyword
    int id;         
    char name[50];
    float mark;
    char grade;
};
void* calculate(void* arg) { // declare the void pointer function that calculate grade according to marks
    struct student* s = (struct student*)arg; // make the object of class which name have c

    if (s->mark >= 85) s->grade = 'A';      // check the condition according to marks and update the grade
    else if (s->mark >= 70) s->grade = 'B';
    else if (s->mark >= 60) s->grade = 'C';
    else if (s->mark >= 50) s->grade = 'D';
    else s->grade = 'F';

    printf("ID: %d \nName: %s\n Marks: %.3f\n Grade: %c\n", //It can display the the student details like id name marks and grade
           s->id, s->name, s->mark, s->grade);

    return NULL; //in this we return null value because return type of function is void pointer
}
int main(){
    pthread_t t[3]; // declare thread variable
     struct student stu[3] = { // declare and initalize the array of 3 student structure
        {1, "Abdul", 90.0},
        {2, "Ahmad", 72.5},
        {3, "Hadi", 48.0}
    };
    for (int i = 0; i < 3; i++) // there is for loop that can creat thread one by one and due to for loop it can 3 thread after 3 loop will end
        pthread_create(&t[i], NULL, calculate, &stu[i]);
    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL); // wait thread number to finish before contunuing the main thread
    printf("All threads finished.\n"); // it can tell all thread will be comleted
    return 0; // 

}