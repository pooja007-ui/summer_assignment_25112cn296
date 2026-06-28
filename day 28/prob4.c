#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CONTACTS 100
#define MAX_LENGTH 100
typedef struct {
    int id;
    char name[MAX_LENGTH];
    char phone[20];
    char email[MAX_LENGTH];
} Contact;
Contact addressBook[MAX_CONTACTS];
int contact_count = 0;
int next_id = 1;
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int findContactIndex(int id) {
    for (int i = 0; i < contact_count; i++) {
        if (addressBook[i].id == id) {
            return i;
        }
    }
    return -1;
}
void addContact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("\nError: Address book is full. Cannot add more contacts.\n");
        return;
    }
    Contact newContact;
    newContact.id = next_id++;
    printf("\nEnter Contact Name: ");
    fgets(newContact.name, MAX_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;
    printf("Enter Phone Number: ");
    fgets(newContact.phone, 20, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;
    printf("Enter Email Address: ");
    fgets(newContact.email, MAX_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0;
    addressBook[contact_count] = newContact;
    contact_count++;
    printf("\nSuccess: Contact '%s' added with ID %d.\n", newContact.name, newContact.id);
}
void displayContacts() {
    if (contact_count == 0) {
        printf("\nYour address book is empty.\n");
        return;
    }
    printf("\n--- Address Book ---\n");
    printf("%-5s %-25s %-15s %-30s\n", "ID", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%-5d %-25s %-15s %-30s\n", 
            addressBook[i].id, 
            addressBook[i].name, 
            addressBook[i].phone,
            addressBook[i].email);
    }
}
void searchContact() {
    if (contact_count == 0) {
        printf("\nYour address book is empty.\n");
        return;
    }
    char searchName[MAX_LENGTH];
    printf("\nEnter name to search: ");
    fgets(searchName, MAX_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strstr(addressBook[i].name, searchName) != NULL) {
            if (!found) {
                printf("\n--- Search Results ---\n");
                printf("%-5s %-25s %-15s %-30s\n", "ID", "Name", "Phone", "Email");
                printf("-------------------------------------------------------------------------------\n");
            }
            printf("%-5d %-25s %-15s %-30s\n", 
                addressBook[i].id, 
                addressBook[i].name, 
                addressBook[i].phone,
                addressBook[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo contacts found matching '%s'.\n", searchName);
    }
}
void deleteContact() {
    if (contact_count == 0) {
        printf("\nYour address book is empty.\n");
        return;
    }
    int id, index;
    printf("\nEnter the Contact ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();
    index = findContactIndex(id);
    if (index == -1) {
        printf("\nError: Contact ID %d not found.\n", id);
        return;
    }
    char deletedName[MAX_LENGTH];
    strcpy(deletedName, addressBook[index].name);
    for (int i = index; i < contact_count - 1; i++) {
        addressBook[i] = addressBook[i + 1];
    }
    contact_count--;
    printf("\nSuccess: Contact '%s' (ID %d) has been deleted.\n", deletedName, id);
}
int main() {
    int choice;
    while (1) {
        printf("\n===============================\n");
        printf("   Contact Management System   \n");
        printf("===============================\n");
        printf("1. Add a Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete a Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        clearInputBuffer(); 
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}