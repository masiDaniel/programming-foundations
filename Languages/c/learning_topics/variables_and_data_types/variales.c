#include <stdio.h>

/**
 * variables - are continers for stoing data values 
 * examples - int, float, char
 * 
 * you can overwrite the excisting value of a variable.
 * 
 * to output something in c we must use format specifiers
 */

int main(){

    // declaring (creating) a variable while assigning 
    int myAge = 40;

     // declaring (creating) a variable without assigning 
     int myBrothersAge;
     myBrothersAge =50;

     //overwritting the value of my age to 80
     myAge = 80;

    // printing them out 
    printf("this is my age: %d\nThis is my brothers age: %d", myAge, myBrothersAge);
    return 0;
}