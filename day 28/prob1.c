#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BOOKS 100
#define MAX_LENGTH 100
typedef struct {
    int id;
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    int is_borrowed;
} Book;
Book library[MAX_BOOKS];
int book_count = 0;
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\nError: Library is full. Cannot add more books.\n");
        return;
    }
    Book newBook;
    newBook.id = book_count + 1;
    printf("\nEnter Book Title: ");
    fgets(newBook.title, MAX_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    printf("Enter Book Author: ");
    fgets(newBook.author, MAX_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;
    newBook.is_borrowed = 0;
    library[book_count] = newBook;
    book_count++;
    printf("\nSuccess: '%s' added with Book ID %d.\n", newBook.title, newBook.id);
}
void displayBooks() {
    if (book_count == 0) {
        printf("\nThe library is currently empty.\n");
        return;
    }
    printf("\n--- Library Catalog ---\n");
    printf("%-5s %-30s %-25s %-15s\n", "ID", "Title", "Author", "Status");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-5d %-30s %-25s %-15s\n", 
            library[i].id, 
            library[i].title, 
            library[i].author, 
            library[i].is_borrowed ? "Borrowed" : "Available");
    }
}
void searchBook() {
    if (book_count == 0) {
        printf("\nThe library is empty.\n");
        return;
    }
    char searchTitle[MAX_LENGTH];
    printf("\nEnter title to search: ");
    fgets(searchTitle, MAX_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strstr(library[i].title, searchTitle) != NULL) {
            if (!found) {
                printf("\n%-5s %-30s %-25s %-15s\n", "ID", "Title", "Author", "Status");
                printf("-------------------------------------------------------------------------------\n");
            }
            printf("%-5d %-30s %-25s %-15s\n", 
                library[i].id, 
                library[i].title, 
                library[i].author, 
                library[i].is_borrowed ? "Borrowed" : "Available");
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo books found matching '%s'.\n", searchTitle);
    }
}
void borrowBook() {
    int id;
    printf("\nEnter the Book ID to borrow: ");
    scanf("%d", &id);
    clearInputBuffer();
    if (id <= 0 || id > book_count) {
        printf("\nError: Invalid Book ID.\n");
        return;
    }
    if (library[id - 1].is_borrowed == 1) {
        printf("\nSorry, '%s' is already borrowed.\n", library[id - 1].title);
    } else {
        library[id - 1].is_borrowed = 1;
        printf("\nSuccess: You have borrowed '%s'.\n", library[id - 1].title);
    }
}
void returnBook() {
    int id;
    printf("\nEnter the Book ID to return: ");
    scanf("%d", &id);
    clearInputBuffer();
    if (id <= 0 || id > book_count) {
        printf("\nError: Invalid Book ID.\n");
        return;
    }
    if (library[id - 1].is_borrowed == 0) {
        printf("\nError: '%s' was not borrowed.\n", library[id - 1].title);
    } else {
        library[id - 1].is_borrowed = 0;
        printf("\nSuccess: You have returned '%s'.\n", library[id - 1].title);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n===============================\n");
        printf("   Library Management System   \n");
        printf("===============================\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Borrow a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                borrowBook();
                break;
            case 5:
                returnBook();
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