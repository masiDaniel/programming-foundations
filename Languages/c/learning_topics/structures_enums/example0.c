#include <stdio.h>


typedef struct relative
{
    int age;
    char gender;
   
} myRelative;

int main(){
    int age = 5;
    printf("my age is %d\n", age);

    myRelative freedy;
    freedy.age=20;
    freedy.gender = 'M';
    printf("this is freddy, he is %d years old and is of the %c gender\n", freedy.age, freedy.gender);
    myRelative moraa;
    moraa.age=35;
    moraa.gender='F';
    printf("These are my cousins freddy and moraa and they are %d, %d and  %c, %c respectively\n", freedy.age, moraa.age, freedy.gender, moraa.gender);

    return 0;
}