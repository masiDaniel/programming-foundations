#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILENAME ""

struct Task {
    char *name;
    char *description;
    char *due_date;
    int status;
}task_1, task_2;

void createTask(){

    //allocating memory for the task fields
    task_2.name = (char *)malloc(100 * sizeof(char));
    task_2.description = (char *)malloc(100 * sizeof(char));
    task_2.due_date = (char *)malloc(100 * sizeof(char));

    // geting the details from the user
    printf("enter the task name: ");
    scanf("%s", task_2.name);

    printf("enter the task description: ");
    scanf("%s", task_2.description);

    printf("enter the task's due date: ");
    scanf("%s", task_2.due_date);

}

int main(){
    task_1.name = "mop";
    task_1.description = "finish cleaning the house";
    task_1.due_date = "11th december";
    task_1.status = 0 ;
    char answer[3];

    printf("the task is: %s \n and you should: %s \n before:%s \n ", task_1.name, task_1.description, task_1.due_date); 
    while (1){
        createTask();

        printf("the task is: %s \n and you should: %s \n before:%s \n ", task_2.name, task_2.description, task_2.due_date); 

        printf("do you want to stop adding tasks :");
        scanf("%s", answer);

        if (strcmp(answer, "y") == 0 || strcmp(answer, "yes") == 0) {
            break;
        }
    }
    free(task_2.name);
    free(task_2.description);
    free(task_2.due_date);

    return 0;
}
