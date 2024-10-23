#include <stdio.h>
/**
 * what really is the significance and importance of pointers 
 * what are some of the challanges faced bby developers when handling memory?
 * how do we use pointers to manipulate data
*/

int main(){

    int age = 10;
    
    //this is the memory address associated with age and inside that address 10 is stored
    printf("%p\n", &age);

    //pointer ptr that has memory adress of age
    int* ptr = &age;

    //proof 
    printf("%p\n", ptr);

    //derefrencing the pointer 
    printf("%d\n", *ptr);

    //using the ponter to change the value using the pointer



    return 0;
}
