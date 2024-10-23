#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//the structure to handle tasks
struct Task{
    char *name;
    char *description;
    char *due_date;
};

void createTask(struct Task *task){
    printf("enter the task name: ");
    scanf("%s", task->name);

    printf("enter the task description: ");
    scanf("%s", task->description);

    printf("enter the task's due date: ");
    scanf("%s", task->due_date);
}

void saveTaskToFile(const struct Task *task, const char *filename){
    FILE *file = fopen(filename, "a");

    if (file != NULL){
        fprintf(file, "%S,%s,%s\n", task->name, task->description,task->due_date);
        fclose(file);
    }else{
        printf("error opening the file for writting\n");
    }
}

void printTasksFromFile(const char *filename){
    FILE *file = fopen(filename, "r");

    if (file != NULL){
        struct Task task;

        printf("\nTasks:\n");

        while (fscanf(file, "%[^,],%[^,],%[^\n]\n", task.name, task.description, task.due_date) == 3){
            printf("Name: %s\nDescription: %s\nDue Date: %s\n\n", task.name, task.description, task.due_date);
        }
        fclose(file);
    }else {
        printf("error opening the file for reading\n");
    }
}

int main() {
    struct Task task;

    // Create a task
    createTask(&task);

    // Generate a filename based on user information (e.g., name)
    char *filename ; // +5 for ".txt"
    sprintf(filename, "%s.txt", task.name);

    // Save the task to the file
    saveTaskToFile(&task, filename);

    // Print tasks from the file
    printTasksFromFile(filename);

    return 0;
}