#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 100
#define STARTING_ACC_NUM 1001
typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    double balance;
} Account;
Account bank[MAX_ACCOUNTS];
int account_count = 0;
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int findAccountIndex(int acc_num) {
    for (int i = 0; i < account_count; i++) {
        if (bank[i].account_number == acc_num) {
            return i;
        }
    }
    return -1;
}
void createAccount() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("\nError: Bank capacity reached. Cannot open more accounts.\n");
        return;
    }
    Account newAccount;
    newAccount.account_number = STARTING_ACC_NUM + account_count;
    printf("\nEnter Account Holder Name: ");
    fgets(newAccount.name, MAX_NAME_LENGTH, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0;
    printf("Enter Initial Deposit Amount: $");
    scanf("%lf", &newAccount.balance);
    clearInputBuffer();
    if (newAccount.balance < 0) {
        printf("\nError: Initial deposit cannot be negative. Setting balance to $0.00.\n");
        newAccount.balance = 0.0;
    }
    bank[account_count] = newAccount;
    account_count++;
    printf("\nSuccess: Account created for '%s'. Account Number is %d.\n", newAccount.name, newAccount.account_number);
}
void deposit() {
    int acc_num, index;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_num);
    index = findAccountIndex(acc_num);
    if (index == -1) {
        printf("\nError: Account number %d not found.\n", acc_num);
        clearInputBuffer();
        return;
    }
    printf("Enter amount to deposit: $");
    scanf("%lf", &amount);
    clearInputBuffer();
    if (amount <= 0) {
        printf("\nError: Deposit amount must be greater than zero.\n");
    } else {
        bank[index].balance += amount;
        printf("\nSuccess: $%.2f deposited. New Balance: $%.2f\n", amount, bank[index].balance);
    }
}
void withdraw() {
    int acc_num, index;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_num);
    index = findAccountIndex(acc_num);
    if (index == -1) {
        printf("\nError: Account number %d not found.\n", acc_num);
        clearInputBuffer();
        return;
    }
    printf("Enter amount to withdraw: $");
    scanf("%lf", &amount);
    clearInputBuffer();
    if (amount <= 0) {
        printf("\nError: Withdrawal amount must be greater than zero.\n");
    } else if (amount > bank[index].balance) {
        printf("\nError: Insufficient funds. Current Balance is $%.2f.\n", bank[index].balance);
    } else {
        bank[index].balance -= amount;
        printf("\nSuccess: $%.2f withdrawn. New Balance: $%.2f\n", amount, bank[index].balance);
    }
}
void checkBalance() {
    int acc_num, index;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_num);
    clearInputBuffer();
    index = findAccountIndex(acc_num);
    if (index == -1) {
        printf("\nError: Account number %d not found.\n", acc_num);
    } else {
        printf("\nAccount Holder: %s\n", bank[index].name);
        printf("Current Balance: $%.2f\n", bank[index].balance);
    }
}
void displayAccounts() {
    if (account_count == 0) {
        printf("\nNo accounts have been created yet.\n");
        return;
    }
    printf("\n--- Bank Directory ---\n");
    printf("%-15s %-30s %-15s\n", "Account No.", "Account Holder", "Balance");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < account_count; i++) {
        printf("%-15d %-30s $%-14.2f\n", 
            bank[i].account_number, 
            bank[i].name, 
            bank[i].balance);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n===============================\n");
        printf("      Bank Account System      \n");
        printf("===============================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Funds\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAccounts();
                break;
            case 6:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}