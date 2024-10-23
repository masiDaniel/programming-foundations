#include <stdio.h>
#include <stdlib.h>

/**
 * i should have the ability to read and write to the file.
 * editing also should be available
 * the static and dynamic headers module comes into play here (do more research)
*/

int main(){
    FILE *file_pointer;
    int value;
    int value_array [] = {0,0,0,0,0,0,0,0,0,0};
    int length_of_array = sizeof(value_array) / sizeof(value_array[0]);

    file_pointer = fopen("opent_test.txt", "r");

    for (int x = 0; x < length_of_array && fscanf(file_pointer, "%d", &value) == 1; x++){
        value_array[x] = value;
    }

    for (int x = 0; x < length_of_array; x++){
        printf("%d\n", value_array[x]);
    }

    fclose(file_pointer);
    return 0;


}