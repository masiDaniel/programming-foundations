#include <stdio.h>
#include <stdlib.h>
/**
 * this file opens and writes to a txt file
 * it also gives the option of quiting from the program effectively
*/

int main(){

    int value;
    FILE *file_pointer;
    int exit_status ;

    while (exit_status != 2)
    {
        file_pointer = fopen("opent_test.txt", "a");
        printf("\t\tplease enter a value : \n");
        scanf("%d", &value);

        fprintf(file_pointer, "%d\n", value);
        fclose(file_pointer);
        printf("do you want to\n 1. continue? \n 2. stop \n");
        scanf("%d", &exit_status);
    }
    

  
    return 0;
}