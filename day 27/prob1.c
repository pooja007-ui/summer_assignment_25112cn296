#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int roll_no;
    char name[50];
    char course[50];
    float marks;
} Student;
void addStudent();
void displayStudents();
void searchStudent();
void modifyStudent();
void deleteStudent();
void clearBuffer();
const char *FILE_NAME = "students.dat";
int main() {
    int choice;
    while (1) {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add a New Student\n");
        printf("2. Display All Students\n");
        printf("3. Search for a Student\n");
        printf("4. Modify a Student Record\n");
        printf("5. Delete a Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6:
                printf("Saving data and exiting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a number between 1 and 6.\n");
        }
    }
    return 0;
}
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void addStudent() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    Student s;
    printf("\n--- Add New Student ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll_no);
    clearBuffer();
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0;
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student record added successfully!\n");
}
void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found. The database is empty.\n");
        return;
    }
    Student s;
    printf("\n%-10s %-20s %-15s %-10s\n", "Roll No", "Name", "Course", "Marks");
    printf("------------------------------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%-10d %-20s %-15s %-10.2f\n", s.roll_no, s.name, s.course, s.marks);
    }
    fclose(fp);
}
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    int roll, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll_no == roll) {
            printf("\n--- Record Found ---\n");
            printf("Name   : %s\n", s.name);
            printf("Course : %s\n", s.course);
            printf("Marks  : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent with Roll Number %d not found!\n", roll);
    }
    fclose(fp);
}
void modifyStudent() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    int roll, found = 0;
    printf("\nEnter Roll Number to modify: ");
    scanf("%d", &roll);
    clearBuffer();
    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll_no == roll) {
            printf("\nRecord Found. Enter new details:\n");
            printf("Enter New Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;
            printf("Enter New Course: ");
            fgets(s.course, sizeof(s.course), stdin);
            s.course[strcspn(s.course, "\n")] = 0;
            printf("Enter New Marks: ");
            scanf("%f", &s.marks);
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found) {
        printf("Record modified successfully.\n");
    } else {
        printf("Student with Roll Number %d not found!\n", roll);
    }
}
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    } 
    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }
    int roll, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll_no != roll) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);
    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Student with Roll Number %d not found!\n", roll);
    }
}