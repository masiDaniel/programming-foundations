#include <stdio.h>


struct myStructure {
    int myId;
    int myAge;
    char *name;
};

int main ()
{
    struct myStructure student1;
    struct myStructure student2 = {20211, 21, "kevin"};


    student1.myAge = 20;
    student1.name = "daniel";
    student1.myId = 20220;
    
    printf("student 1 name is %s, their age is %d, andd their id is %d\n", student1.name, student1.myAge, student1.myId);
    printf("student 2 name is %s, their age is %d, andd their id is %d\n", student2.name, student2.myAge, student2.myId);
    return 0;
}