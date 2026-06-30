#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 50
int main() {
    char titles[MAX_BOOKS][MAX_TITLE];
    char authors[MAX_BOOKS][MAX_AUTHOR];
    int is_issued[MAX_BOOKS];
    int count = 0;
    int choice;
    char search_title[MAX_TITLE];
    int found;
    do {
        printf("\n--- Mini Library System ---\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue a Book\n");
        printf("4. Return a Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        while (getchar() != '\n'); 
        switch (choice) {
            case 1:
                if (count < MAX_BOOKS) {
                    printf("Enter book title: ");
                    fgets(titles[count], MAX_TITLE, stdin);
                    titles[count][strcspn(titles[count], "\n")] = '\0'; 
                    printf("Enter author name: ");
                    fgets(authors[count], MAX_AUTHOR, stdin);
                    authors[count][strcspn(authors[count], "\n")] = '\0'; 
                    is_issued[count] = 0; 
                    count++;
                    printf("Book added successfully!\n");
                } else {
                    printf("Library is full!\n");
                }
                break;
            case 2:
                if (count == 0) {
                    printf("The library is currently empty.\n");
                } else {
                    printf("\nStatus\t\tTitle (Author)\n");
                    printf("--------------------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        if (is_issued[i] == 0) {
                            printf("Available\t");
                        } else {
                            printf("Issued\t\t");
                        }
                        printf("%s (%s)\n", titles[i], authors[i]);
                    }
                }
                break;
            case 3:
            case 4:
                if (count == 0) {
                    printf("The library is currently empty.\n");
                    break;
                }
                printf("Enter exact book title: ");
                fgets(search_title, MAX_TITLE, stdin);
                search_title[strcspn(search_title, "\n")] = '\0'; 
                found = 0; 
                for (int i = 0; i < count; i++) {
                    if (strcmp(titles[i], search_title) == 0) { 
                        found = 1;
                        if (choice == 3) {
                            if (is_issued[i] == 0) {
                                is_issued[i] = 1;
                                printf("Book '%s' has been issued to you.\n", titles[i]);
                            } else {
                                printf("Sorry, '%s' is already issued.\n", titles[i]);
                            }
                        } else if (choice == 4) {
                            if (is_issued[i] == 1) {
                                is_issued[i] = 0;
                                printf("Book '%s' has been successfully returned.\n", titles[i]);
                            } else {
                                printf("Book '%s' was not issued.\n", titles[i]);
                            }
                        }
                        break; 
                    }
                }
                if (!found) {
                    printf("Book titled '%s' not found in the system.\n", search_title);
                }
                break;
            case 5:
                printf("Shutting down the library system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}