#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void add_element();
void search_element();
void display();
void insertion();//adds an eleemnt at a given index
void delete_element();
// int* myNumbersArray[5];   -  this is an array of 5 pointers to integers. 

int main(){
    int size = 5;
    int *myNumbersArray = malloc(size * sizeof(int));

    if (myNumbersArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    


    add_element(myNumbersArray, size);
    display(myNumbersArray, size);
    search_element(myNumbersArray, size);
    delete_element(myNumbersArray, &size);
    display(myNumbersArray, size);
    free(myNumbersArray);
    

return (0);
}

void add_element(int *array, int size)
{
    printf("key in the values you want to add from 1 - 5\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d = ", i+1);
        while (scanf("%d", &array[i]) != 1)
        {
            printf("invalid input: Please enter an integer");
           
            while (getchar() != '\n');
        }
        
    }


}

void display(int *array, int size)
{
    printf("the elements you have added are: [\n");
	for (int x = 0; x < size; x++)
    {
        printf("[%d]",array[x]);
        if (x < size - 1){
            printf(", ");
        }
    }
    printf("]\n");
}

void search_element(int *array, int size)
{
    int search_element;
    int x;
    int found = 0;
    
    printf("enter the element you want to search\n");
    while (scanf("%d", &search_element) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n'); // Clear invalid input
    }
    
    for (x = 0; x < 5; x++)
    {
        if (search_element == array[x])
        {
            printf("the element %d was at index %d\n", search_element, x);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("element not found\n");
}

/*how do i delete elements from an array?*/
void delete_element(int *array ,int *size)
{
    int index;
    printf("enter the element you want to delete (0 to %d): \n", *size - 1);
    while (scanf("%d", &index) != 1 || index < 0 || index >= *size) {
        printf("Invalid index. Please enter a valid index: ");
        while (getchar() != '\n'); // Clear invalid input
    }

    for (int i = index; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }

    (*size)--;
    printf("Element at index %d deleted successfully.\n", index);
}