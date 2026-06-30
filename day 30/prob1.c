#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 50
#define MAX_NAME 50
int main() {
    char names[MAX_STUDENTS][MAX_NAME];
    int roll_numbers[MAX_STUDENTS];     
    float marks[MAX_STUDENTS];
    int count = 0;
    int choice;
    char search_name[MAX_NAME];
    int found;
    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add a Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }
        while (getchar() != '\n'); 
        switch (choice) {
            case 1:
                if (count < MAX_STUDENTS) {
                    printf("Enter student's full name: ");
                    fgets(names[count], MAX_NAME, stdin);
                    names[count][strcspn(names[count], "\n")] = '\0'; 
                    printf("Enter roll number: ");
                    scanf("%d", &roll_numbers[count]);
                    printf("Enter marks: ");
                    scanf("%f", &marks[count]);
                    count++;
                    printf("Student added successfully!\n");
                } else {
                    printf("System is full! Cannot add more students.\n");
                }
                break;
            case 2:
                if (count == 0) {
                    printf("No student records found.\n");
                } else {
                    printf("\nRoll No.\tMarks\t\tName\n");
                    printf("--------------------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t\t%.2f\t\t%s\n", roll_numbers[i], marks[i], names[i]);
                    }
                }
                break;
            case 3:
                if (count == 0) {
                    printf("No records to search.\n");
                    break;
                }
                printf("Enter exact name to search: ");
                fgets(search_name, MAX_NAME, stdin);
                search_name[strcspn(search_name, "\n")] = '\0';
                found = 0; 
                for (int i = 0; i < count; i++) {
                    if (strcmp(names[i], search_name) == 0) { 
                        printf("\n--- Student Found ---\n");
                        printf("Name: %s\n", names[i]);
                        printf("Roll Number: %d\n", roll_numbers[i]);
                        printf("Marks: %.2f\n", marks[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Student named '%s' not found.\n", search_name);
                }
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    return 0;
}