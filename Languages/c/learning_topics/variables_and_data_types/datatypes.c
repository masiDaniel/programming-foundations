#include <stdio.h>

/**
 * Variables must be secified by a data type 
 * 
 * 
 */

int asciiFunction(char character);

int main (void)
{

   /**
    * char data type - used to store a single character 
    */

    char myGrade = 'A';
    printf("this is my grade: %c\n", myGrade);

    asciiFunction(myGrade);



    /**
     * numeric data types
     * int - used to  whole number without decimals
     * float - 4 bit - offeres 7 decimal digits
     * double - 8 bit - 0ffers 15-17 decimal digits
     * 
     */

     // cannot prefix with 0, interprated as octal
    int myPhoneNumber = 710000;
    printf("this is my phone number: %d\n", myPhoneNumber);

    float myfloatingnumber = 5.75;
    printf("this is my floating number: %.2f\n", myfloatingnumber);


    float myDoublenumber = 5.75;
    printf("this is my double number: %.3lf\n", myDoublenumber);



    int myInt;
    float myFloat;
    double myDouble;
    char myChar;

    printf("%lu\n", sizeof(myInt));
    printf("%lu\n", sizeof(myFloat));
    printf("%lu\n", sizeof(myDouble));
    printf("%lu\n", sizeof(myChar));










// //these are the values
// int a= 30;
// int b;
// // this is the pointer
// int *point;
// // this is assigning the memory address of a to the pointer
// point =&a ;
// // here we get the sizes of different data type 
// printf("size of char is : %lu \n",sizeof(char));
// printf("size of int is : %lu \n",sizeof(int));
// printf("size of float is : %lu \n",sizeof(float));
// printf("size of double is : %lu \n",sizeof(double));
// printf("the size of a pointer is %lu in bytes\n ", sizeof(point));
// //here we get to see the memory addresses of the variables declared above
// printf("the memory address of a is %p\n ",&a);
// printf("the memory address of b is %p\n ",&b);
// printf("the memory address of the pointer is %p\n ",&point);
// printf("the memory address of a is %p\n ",&a);
// //here we get to see the memory address stored in the pointer 
// printf("the value contained in point is  %p\n ",point );
// // we can see the value inside the memory address sstores in the pointer
// printf("the value inside the memory address stores in the pointer is :%d\n", *point);
// // below we get to see how pointers woek in real situations 
// printf("the value inside a is %d \n",a);
// *point = 300;
// printf("the value inside a  is %d \n",a);

return (0);
}


int asciiFunction(char character){

    /**
     * THis function is to return the ascii value of a character
     * args : asciiValue, character
     * body: it achieves this using two methods.
     * return (int): the actual ascii value
     */


    // (TODO): implement a check if it is a character, dont use a library

    if (sizeof(character) == 1){
        int asciiValue;
        //method 1: assigning to an integer variable.
        asciiValue = character;
        printf("ASCII value of %c is %d\n", character, asciiValue);
        // method 2:  direct printing with %d
        printf("ASCII value of %c is %d\n", character, character);

    return asciiValue;
    }
   
    return 1;

    

};