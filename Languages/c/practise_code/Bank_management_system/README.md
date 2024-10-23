this project deals with the banking systems and will touch on various programming principles 

#include <stdio.h>
#include <stdlib.h>

// Define data structures
typedef struct {
    int accountNumber;
    char accountHolder[50];
    float balance;
} Account;

// Function prototypes
void createAccount(Account accounts[], int *numAccounts);
void deposit(Account accounts[], int numAccounts, int accountNumber, float amount);
void withdraw(Account accounts[], int numAccounts, int accountNumber, float amount);
void displayAccountInfo(Account accounts[], int numAccounts, int accountNumber);

int main() {
    // Declare variables and arrays
    Account accounts[100];
    int numAccounts = 0;
    int choice, accountNumber;
    float amount;

    // Main menu
    do {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Info\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(accounts, numAccounts, accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(accounts, numAccounts, accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                displayAccountInfo(accounts, numAccounts, accountNumber);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to create an account
void createAccount(Account accounts[], int *numAccounts) {
    // Check if there is space for a new account
    if (*numAccounts < 100) {
        printf("Enter account holder name: ");
        scanf("%s", accounts[*numAccounts].accountHolder);
        
        accounts[*numAccounts].accountNumber = *numAccounts + 1;
        accounts[*numAccounts].balance = 0.0;

        printf("Account created successfully!\n");
        printf("Account Number: %d\n", accounts[*numAccounts].accountNumber);

        (*numAccounts)++;
    } else {
        printf("Cannot create more accounts. Maximum limit reached.\n");
    }
}

// Function to deposit to an account
void deposit(Account accounts[], int numAccounts, int accountNumber, float amount) {
    // Check if the account number is valid
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        // Deposit amount into the account
        accounts[accountNumber - 1].balance += amount;
        printf("Deposit successful. New balance: %.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number. Please try again.\n");
    }
}

// Function to withdraw from an account
void withdraw(Account accounts[], int numAccounts, int accountNumber, float amount) {
    // Check if the account number is valid
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        // Check if there are sufficient funds for withdrawal
        if (amount <= accounts[accountNumber - 1].balance) {
            // Withdraw amount from the account
            accounts[accountNumber - 1].balance -= amount;
            printf("Withdrawal successful. New balance: %.2f\n", accounts[accountNumber - 1].balance);
        } else {
            printf("Insufficient funds for withdrawal. Please try again.\n");
        }
    } else {
        printf("Invalid account number. Please try again.\n");
    }
}

// Function to display account information
void displayAccountInfo(Account accounts[], int numAccounts, int accountNumber) {
    // Check if the account number is valid
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        // Display account information
        printf("Account Number: %d\n", accounts[accountNumber - 1].accountNumber);
        printf("Account Holder: %s\n", accounts[accountNumber - 1].accountHolder);
        printf("Balance: %.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number. Please try again.\n");
    }
}
