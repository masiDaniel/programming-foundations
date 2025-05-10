#include <stdio.h>


void access_element(int index, int array[], int* arr);
int main (){
    /**
     * arrays - are used to store multiple values of a single variable
     * 
     */

    int myNumbersArray[] = {10, 20,30,40,50};
    access_element(2, myNumbersArray, myNumbersArray);

    /**
     * 
     * Multidimentional arrays - is an array of arrays.
     */

     int matrix[2][3] = {{1,2,3},{4,5,6}};


     /**
      * string -  are used to store text/characters
      * in c you must create an array of characters to create a string
      * it has to be "" quotes
      */

    char greetings[] = "Hello world";
    







//     int x;
//     int y = 1;

//     // simple strings
//     char greetings[] = "hello world, straight from kenya";
//     char* name = "daniel";

//     // this is how we access the strings defined in our programs
//     printf("\t%s\n\t%s\n\n", name, greetings);


//     // this is how we define an empty string
//    // char* brothers; // seg fault
//     char names[] = "";
//     printf("enter the names of the individuals: \n"); // does not print more than 1 name if many are keyed 
//     scanf("%s", names);
//     printf("enter the name of your brother\n");
//    // scanf("%s", brothers); // seg fault

//     printf("the names are: [%s]\n", names);
//    // printf("the name of your brother is [%s]\n", brothers); // seg fault


//     /**
//      * how do we do arrays of more than 1000 characters
//      * how does the memory get allocated
//      * are strings mutable?
//     */


//     //simple array 
//     int my_integers [] = {10,9,8,7,6,5,4,3,2};
//     printf("%d\n", my_integers[2]);

//     for (x = 0; x < 9; x++){
//         printf("the value [%d] is number {%d} \n", my_integers[x], y);
//         y++;
//     }

//     // multidimentional arrays 


  

    return 0;
}

void access_element(int index,int array[], int* arr){

    printf("the item in index: %d is: %d\n", index, array[index]);

    printf("the item in index: [%d] is: [%d]\n", index, arr[index]);
}