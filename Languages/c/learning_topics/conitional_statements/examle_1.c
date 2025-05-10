#include <stdio.h>
#include <string.h>

void day_of_week();
void while_loops();
void for_loops();

int main(){

    int x = 10;
    int age = 18; 
    char* area = "kenya";
    char* local = "kenya";
    int answer;


    if (x < 10){
        printf("[%d] is less than 10\n", x);
    }else if (x > 10){
        printf("[%d] is greater than 10\n", x);
    }else {
        printf("[%d] is equal to 10\n", x);
    }


    if (age >= 18){
        /**
         * comparisons between strings is a bit technical, find out 
         * i have found out about strcmp that returns 0 if they match and 1 if they dont
         * but i want to actually do it myself and not just a function (find out)
        */
       answer == strcmp(area, local);
        if (answer == 0){
            printf("you can vote\n");
        }else{
            printf("you are not kenyan\n");
        }
    }else {
        printf("you are not of age yet to vote\n");
    }

    day_of_week(5);

    while_loops();

    for_loops();
    return 0;
}

void day_of_week(int day){
    switch (day){
        case 1:
        printf("today is monday\n");
        break;
        case 2:
        printf("today is tuesday\n");
        break;
        case 3:
        printf("today is wednesday\n");
        break;
        case 4:
        printf("today is thursday\n");
        break;
        case 5:
        printf("today is friday\n");
        break;
        case 6:
        printf("today is saturday\n");
        break;
        case 7:
        printf("today is sunday\n");
        break;
        default:
        printf("this is not a day of the week\n");
    
    }
}

void job_category(char* job){

    /**
     * i wanted to filter using a switch satement the various jobs but im gettign an error that it olnly works with integers 
     * do research on that
    */
}


void while_loops(){
    /**
     * loops execute a block of code as long as a condition is reached
     * while loops -  loops through a block of code as long as the specified codition is true
     * do/while - this executes the code once, then checks if the condition is true, then repeat as long as it is true
     */

     int number = 0;
     int age = 5;
     while (number < 5){
        printf("this is the number: %d\n", number);
        number++;
     }

     do {
        age++;
        printf("the child is insured at age :%d\n", age);

     }while(age < 25);
}

void for_loops(){
/**
 * when ou know exactly how many times you want to run the block of code you use a for loop
 * 
 */

 int number ;
 

 for (number = 0; number <10; number++){
    printf("this is the number %d\n", number);
 }

 // nested loops 
 int i, j;

 for (i = 0; i <2 ; i++){

    printf("this is i{%d} on the outside\n", i);

    for (j =0; j <3; j++)
    {
        printf("\tthis is j{%d} on the inside\n", j);   
    }
 }

}