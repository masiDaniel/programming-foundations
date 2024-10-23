#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_DESCRIPTION_LENGTH 100
#define FILENAME "data.txt"


typedef struct{
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    int priority;
    int completed;
} Task;

typedef struct{
    Task tasks[MAX_TASKS];
    int task_count;
} TaskManager;

void initializeTaskManager(TaskManager *taskManager);
void displayMenu();
void addTask(TaskManager *taskManager);
void displayTasks(TaskManager *taskManager);
void saveTasksToFile(TaskManager *taskManager);
void loadTasksFromFile(TaskManager *taskManager);

int main(){
    TaskManager taskManager;
    initializeTaskManager(&taskManager);
    loadTasksFromFile(&taskManager);


    int choice;

    do {
        displayMenu();
        printf("\t\tenter your choice\n");
        scanf("%d", &choice);

        switch (choice){
            case 0:
                printf("exiting task manager! bye!");
                break;
            case 1:
                addTask(&taskManager);
                saveTasksToFile(&taskManager);
            break;
            case 2:
                displayTasks(&taskManager);
            break;
            default:
                printf("invalis choice please try again \n");
        }
    } while (choice != 0);



    return 0;
}

void initializeTaskManager(TaskManager *taskManager){
    taskManager->task_count = 0;
}

void displayMenu(){
    printf("\t\t======  TASK MANAGER MENU  ======\n\n");
    printf("1. Add task\n");
    printf("2. disaplay task\n");
    printf("0. exit\n");

}

void addTask(TaskManager *taskManager){
    if (taskManager->task_count == MAX_TASKS){
        printf("task manager is full. cannot add more tasks\n");
        return;
    }

    Task newTask;
    newTask.id = taskManager->task_count + 1;

    printf("enter the task description\n");
    scanf("%s\n", newTask.description);

    printf("enter the task priority [1 - 5]\n");
    scanf(" %d", newTask.priority);

    newTask.completed = 0;
    taskManager->tasks[taskManager->task_count++] = newTask;

    printf("task added succesfully\n");
}

void displayTasks(TaskManager *taskManager){
    printf("\n === task list ===\n");
    for (int i = 0; i < taskManager->task_count; ++i){
        printf("ID: %d, Description: %s, Priority: %d, Completed: %s\n",
            taskManager->tasks[i].id,
            taskManager->tasks[i].description,
            taskManager->tasks[i].priority,
            taskManager->tasks[i].completed ? "yes" : "no");
    }
}

void saveTasksToFile(TaskManager *taskManager) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < taskManager->task_count; ++i) {
        fprintf(file, "%d,%s,%d,%d\n",
                taskManager->tasks[i].id,
                taskManager->tasks[i].description,
                taskManager->tasks[i].priority,
                taskManager->tasks[i].completed);
    }

    fclose(file);
}

void loadTasksFromFile(TaskManager *taskManager) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("File not found or error opening file for reading. Starting with an empty task manager.\n");
        return;
    }

    while (fscanf(file, "%d,%99[^,],%d,%d\n",
                  &taskManager->tasks[taskManager->task_count].id,
                  taskManager->tasks[taskManager->task_count].description,
                  &taskManager->tasks[taskManager->task_count].priority,
                  &taskManager->tasks[taskManager->task_count].completed) == 4) {
        taskManager->task_count++;
        if (taskManager->task_count >= MAX_TASKS) {
            printf("Too many tasks in the file. Some tasks may be ignored.\n");
            break;
        }
    }

    fclose(file);
}