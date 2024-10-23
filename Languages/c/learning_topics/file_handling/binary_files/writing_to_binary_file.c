#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    int roll;
    char name[20];
}record;

int main(){

    int a = 5;
    int array[] = {1,2,3};
    record one;
    strcpy(one.name, "dan");
    one.roll = 1;
    FILE *binary_file_pointer;
    /**
     * what file operations for writting are supported
    */


    binary_file_pointer = fopen("file_database.bin", "wb");

    fwrite(&a, sizeof(a), 1, binary_file_pointer);

    fwrite(&array, sizeof(array),1, binary_file_pointer);

    fwrite(&one, sizeof(one), 1,binary_file_pointer);

    fclose(binary_file_pointer);
    



    return 0;
}