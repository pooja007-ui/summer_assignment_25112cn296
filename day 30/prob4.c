#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100
#define MAX_NAME 50
#define MAX_PHONE 20
int addContact(char names[][MAX_NAME], char phones[][MAX_PHONE], int count);
void displayContacts(char names[][MAX_NAME], char phones[][MAX_PHONE], int count);
void searchContact(char names[][MAX_NAME], char phones[][MAX_PHONE], int count);
int main() {
    char names[MAX_CONTACTS][MAX_NAME];
    char phones[MAX_CONTACTS][MAX_PHONE];
    int count = 0;
    int choice;
    do {
        printf("\n--- Phonebook Mini Project ---\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        while (getchar() != '\n'); 
        switch (choice) {
            case 1:
                count = addContact(names, phones, count);
                break;
            case 2:
                displayContacts(names, phones, count);
                break;
            case 3:
                searchContact(names, phones, count);
                break;
            case 4:
                printf("Exiting Phonebook. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}
int addContact(char names[][MAX_NAME], char phones[][MAX_PHONE], int count) {
    if (count >= MAX_CONTACTS) {
        printf("Phonebook is full! Cannot add more contacts.\n");
        return count; 
    }
    printf("Enter contact name: ");
    fgets(names[count], MAX_NAME, stdin);
    names[count][strcspn(names[count], "\n")] = '\0';
    printf("Enter phone number: ");
    fgets(phones[count], MAX_PHONE, stdin);
    phones[count][strcspn(phones[count], "\n")] = '\0';
    printf("Contact added successfully!\n");
    return count + 1;
}
void displayContacts(char names[][MAX_NAME], char phones[][MAX_PHONE], int count) {
    if (count == 0) {
        printf("No contacts saved.\n");
        return;
    }
    printf("\nName\t\t\tPhone Number\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s\t%s\n", names[i], phones[i]); 
    }
}
void searchContact(char names[][MAX_NAME], char phones[][MAX_PHONE], int count) {
    if (count == 0) {
        printf("Phonebook is empty.\n");
        return;
    }
    char search_name[MAX_NAME];
    printf("Enter exact name to search: ");
    fgets(search_name, MAX_NAME, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], search_name) == 0) {
            printf("\n--- Contact Found ---\n");
            printf("Name: %s\n", names[i]);
            printf("Phone: %s\n", phones[i]);
            return;
        }
    }
    printf("Contact '%s' not found.\n", search_name);
}