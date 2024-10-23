#include <stdio.h>
#include <string.h>

void day_of_week();

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