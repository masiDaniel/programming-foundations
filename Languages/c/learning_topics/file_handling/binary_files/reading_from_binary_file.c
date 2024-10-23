#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * this is a user defined data type.
 * i can now use record as i would use in or even a function
 * typedef and the detailed naming conventions should be looked into more
*/
typedef struct record {
    int roll;
    char name[20];
}record;

int main (){

    int a;
    int array[3];
    FILE *binary_file_pointer;
    record one;

    /**
     * what is a binary file?
     * what operations does it support
     * how is it similar and different from a text file
    */
    binary_file_pointer = fopen("file_database.bin", "rb");

    fread(&a, sizeof(a), 1, binary_file_pointer);

    fread(&array, sizeof(array), 1, binary_file_pointer);

    fread(&one, sizeof(one), 1, binary_file_pointer);

    printf("a = %d\n", a);
    for (int i = 0; i < 3; i++)
    {
        printf("%d = %d\n", i, array[i]);
    }

    printf("the name is %s \nand the roll number is %d", one.name, one.roll);

    fclose(binary_file_pointer);
    


    return 0;
}