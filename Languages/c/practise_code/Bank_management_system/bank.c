#include <stdio.h>
#include <stdlib.h>

void user_selection(int choice);
void createAccount();

typedef struct
{
    int accountNumber;
    char accountHolder[60];
    float balance;
}Account;

int main (){

    Account accounts[100];
    int no_of_accounts = 0;
    int selected_choice, accountNumber;
    float amount;

    do
    {
        printf("\n\n\t\t ====Bank Of Daystar=====\n\n");
        printf("0. exit \n");
        printf("1. Create account\n");
        printf("2. deposit in to your account\n");
        printf("3. withraw from your account\n");
        printf("4. display all your accounts information\n");
        printf("\t enter your choice: ");
        scanf("%d", &selected_choice);

        user_selection(selected_choice);



    } while (selected_choice != 0);
    


    return 0;
}

void user_selection(int choice){
        switch (choice)
        {
            case 1:
                createAccount();
                break;
            case 2:
                printf("deposit\n");
                break;
            case 3:
                printf("withdraw\n");
                break;
            case 4:
                printf("display account info\n");
                break;
            case 5:
                printf("exit\n");
                break;
            default:
                printf("choice not functioning yet\n please input again \n");
                break;
        }    
}

void createAccount(){

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
}