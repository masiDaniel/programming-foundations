#include <stdio.h>

int main (){

    int myAge = 23;

    printf("%d\n", myAge);
    printf("%p\n", &myAge);

    int* ptrToMyAge = &myAge;

    printf("%p", ptrToMyAge);

    return 0;
}