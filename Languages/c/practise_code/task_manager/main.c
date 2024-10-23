#include <stdio.h>
#include <stdlib.h>

int createAccount();
void view_score();


int main(){
    int option, userBankNo;
    char *userName;

    printf("hello and welcome to your task manager\n");
    while(1){
        printf("key in what you want to do with us today\n");
        scanf("%d", &option);
        printf("the option you have keyed in is %d \n", option);
        // this is memory allocation for the username string
        userName = (char*)malloc(100 * sizeof(char));

        //god convention tells us to check if it was allocated well hence 
        if (userName == NULL){
            printf("memory allocation failed\n");
            return 1;
        }

        //accepting input from the user
        printf("key in your name and the bank number\n");
        scanf("%s %d", userName, &userBankNo);

        printf("the users name is %s and the bank number is \n%d", userName, userBankNo);
        if (userBankNo == 1){
            createAccount();
        }else{
            printf("we dont have you in our system\n");
        }
        free(userName);
    }


    return 0;
}

int createAccount(){
    //this is a file pointer
    FILE *filePointer;
    char *inputBuffer;
    int sizeOf_buffer = 100;
    int choice;

    //opens a file for writting
    filePointer = fopen("exmaple.txt", "w");

    // exits if the file was not opened succesfully
    if (filePointer == NULL){
        printf("unable to create the file\n");
        return 1;
    }
    
    inputBuffer = (char*)malloc(100 * sizeof(char));
    //this part reads input from the keyboard and keeps it in the file
    do {
        
        //read input from the keyboard
        fgets(inputBuffer, sizeOf_buffer, stdin);

       
        //thi line writes whatever we have keyed into the file
        fprintf(filePointer, "%s", inputBuffer);

        printf("enter more text or press 0 to exit\n");
        scanf("%d", &choice);

        

    } while (choice != 0);

    free(inputBuffer);
    fclose(filePointer);
    
    return(0);

}
