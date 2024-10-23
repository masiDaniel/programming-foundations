#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_TITLE_LENGTH 100
#define MAX_DESC_LENGTH 256
#define MAX_TASKS 100

typedef struct 
{
    int id;
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    int status;

} TASK;


void addTask(TASK tasks[], int *taskCount, int currentId, const char *CurrentTitle, const char *CurrentDescription){
    if (*taskCount >= MAX_TASKS){
        printf("Task list is full!\n");
        return;
    }

    tasks[*taskCount].id = currentId;
    strncpy(tasks[*taskCount].title, CurrentTitle, MAX_TITLE_LENGTH);
    strncpy(tasks[*taskCount].description, CurrentDescription, MAX_DESC_LENGTH);
    tasks[*taskCount].status = 0;
    (*taskCount)++;
}


void viewTasks(TASK tasks[], int taskCount) {
    for (int i = 0; i < taskCount; i++) {
        printf("\n\nID: %d\nTitle: %s\nDescription: %s\nStatus: %s\n\n",
               tasks[i].id,
               tasks[i].title,
               tasks[i].description,
               tasks[i].status ? "Completed" : "Pending");
    }
}


void updateTaskStatus(TASK tasks[], int taskCount, int id, int status) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            tasks[i].status = status;
            printf("Task ID %d status updated to %s\n", id, status ? "Completed" : "Pending");
            return;
        }
    }
    printf("Task ID %d not found!\n", id);
}



void deleteTask(TASK tasks[], int *taskCount, int id) {
    for (int i = 0; i < *taskCount; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < *taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            (*taskCount)--;
            printf("Task ID %d deleted\n", id);
            return;
        }
    }
    printf("Task ID %d not found!\n", id);
}



char* serializeTask(const TASK* task){
    static char buffer[512];
    sprintf(buffer, "%d|%s|%s|%d\n", task->id, task->title, task->description, task->status);
    return strdup(buffer);
}


TASK deserializeTask(const char* line){
    TASK task;
    sscanf(line, "%d|%[^|]|%[^|]|%d", &task.id, task.title, task.description, &task.status);
    return task;
}


void saveTasksToFile(TASK tasks[], int taskCount) {
    FILE *file = fopen("tasks.txt", "w");
    if (file!= NULL) {
        for (int i = 0; i < taskCount; i++) {
            char* serializedTask = serializeTask(&tasks[i]);
            fwrite(serializedTask, strlen(serializedTask), 1, file);
            free(serializedTask);
        }
        fclose(file);
    }
}

int main(){
    TASK tasks[MAX_TASKS];
    int taskCount = 0;
    int choice, id, status;
    char title[MAX_TITLE_LENGTH], description[MAX_DESC_LENGTH];

    FILE *file = fopen("tasks.txt", "r");
    if (file!= NULL) {
        char line[512];
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = 0;
            TASK task = deserializeTask(line);
            addTask(tasks, &taskCount, task.id, task.title, task.description);
        }
        fclose(file);
    }

    while (1)
    {
        printf("\n\t\tTask Manager System\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Update Task Status\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
                printf("Enter task ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter task title: ");
                scanf(" %[^\n]s", title);
                getchar();
                printf("Enter task description: ");
                scanf(" %[^\n]s", description);
                getchar();
                addTask(tasks, &taskCount, id, title, description);
                saveTasksToFile(tasks, taskCount);
            break;
        case 2:
                viewTasks(tasks, taskCount);
                break;
        case 3:
                printf("Enter task ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new status (0 for pending, 1 for completed): ");
                scanf("%d", &status);
                getchar();
                updateTaskStatus(tasks, taskCount, id, status);
                saveTasksToFile(tasks, taskCount);
                break;
        case 4:
                printf("Enter task ID to delete: ");
                scanf("%d", &id);
                deleteTask(tasks, &taskCount, id);
                break;
        case 5:
                exit(0);

        
        
        default:
             printf("Invalid choice! Please try again.\n");
            break;
        }
    }
    
    return 0;
}
