#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char date[11]; // format: YYYY-MM-DD
    double amount;
    char typeOfTransaction[10]; // "income" or "expense"
    char description[100];
} Transaction;

typedef struct main
{
    double currentBalance;
    char accountName[50];
} Account;

void addTransaction(Transaction transactions[], int *transactionCount);
void viewTransactions(const Transaction transactions[], int transactionCount);
void generateReport(const Transaction transactions[], int transactionCount);
void saveTransactionsToFile(const Transaction transactions[], int transactionCount, const char *filename);
void loadTransactionsFromFile(Transaction transactions[], int *transactionCount, const char *filename);

int main(){
    Transaction transactions[1000];
    int transactionCount = 0;
    int choice;

    loadTransactionsFromFile(transactions, &transactionCount, "transactions.txt");
    while (1)
    {
        printf("\nFinance Manager\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Generate Report\n");
        printf("4. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTransaction(transactions, &transactionCount);
            break;
        case 2:
            viewTransactions(transactions, transactionCount);
            break;
        case 3:
            generateReport(transactions, transactionCount);
            break;
        case 4:
            saveTransactionsToFile(transactions, transactionCount, "transactions.txt");
            exit(0);
        default:
         printf("Invalid choice!\n");
            break;
        }
    }
    

    return 0;
}

void addTransaction(Transaction transactions[], int *transactionCount){
    Transaction t;
    printf("Enter date (YYYY-MM-DD):  ");
    scanf("%s", t.date);
    printf("Enter amount: ");
    scanf("%lf", &t.amount);
    printf("Enter type (income/expense): ");
    scanf("%s", t.typeOfTransaction);
    printf("Enter description: ");
    scanf(" %[^\n]", t.description);

    transactions[*transactionCount] = t;
    (*transactionCount)++;
}

void viewTransactions(const Transaction transactions[], int transactionCount){
    for (int i = 0; i < transactionCount; i++){
        printf("%s | %.2f | %s | %s\n", 
        transactions[i].date, 
        transactions[i].amount, 
        transactions[i].typeOfTransaction, 
        transactions[i].description);
    }
}

void generateReport(const Transaction transactions[], int transactionCount){
    double totalIncome = 0.0, totalExpense = 0.0;
    for (int i = 0; i < transactionCount;  i++){
        if (strcmp(transactions[i].typeOfTransaction, "income") == 0){
            totalIncome += transactions[i].amount;
        } else if (strcmp(transactions[i].typeOfTransaction, "expense") == 0){
            totalExpense += transactions[i].amount;
        }
    }
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", totalIncome - totalExpense);
}

void saveTransactionsToFile(const Transaction transactions[], int transactionCount, const char *filename){
    FILE *file = fopen(filename, "wb");
    if (file == NULL){
        printf("Error opening file for writting! \n");
        return;
    }
    fwrite(transactions, sizeof(Transaction), transactionCount, file);
    fclose(file);
}

void loadTransactionsFromFile(Transaction transactions[], int *transactionCount, const char *filename){
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reding!\n");
        return;
    }
    *transactionCount = fread(transactions, sizeof(Transaction), 1000, file);
    fclose(file);
    
}