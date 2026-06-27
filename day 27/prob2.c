#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int emp_id;
    char name[50];
    char designation[50];
    float salary;
} Employee;
void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();
void clearBuffer();
const char *FILE_NAME = "employees.dat";
int main() {
    int choice;
    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add a New Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search for an Employee\n");
        printf("4. Modify an Employee Record\n");
        printf("5. Delete an Employee Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
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
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    Employee e;
    printf("\n--- Add New Employee ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &e.emp_id);
    clearBuffer();
    printf("Enter Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = 0;
    printf("Enter Designation: ");
    fgets(e.designation, sizeof(e.designation), stdin);
    e.designation[strcspn(e.designation, "\n")] = 0;
    printf("Enter Salary: ");
    scanf("%f", &e.salary);
    fwrite(&e, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Employee record added successfully!\n");
}
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found. The database is empty.\n");
        return;
    }  
    Employee e;
    printf("\n%-10s %-20s %-20s %-12s\n", "Emp ID", "Name", "Designation", "Salary");
    printf("-----------------------------------------------------------------\n");
    while (fread(&e, sizeof(Employee), 1, fp)) {
        printf("%-10d %-20s %-20s %-11.2f\n", e.emp_id, e.name, e.designation, e.salary);
    }
    fclose(fp);
}
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    int id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    Employee e;
    while (fread(&e, sizeof(Employee), 1, fp)) {
        if (e.emp_id == id) {
            printf("\n--- Record Found ---\n");
            printf("Name        : %s\n", e.name);
            printf("Designation : %s\n", e.designation);
            printf("Salary      : %.2f\n", e.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found!\n", id);
    }
    fclose(fp);
}
void modifyEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }
    int id, found = 0;
    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &id);
    clearBuffer();
    Employee e;
    while (fread(&e, sizeof(Employee), 1, fp)) {
        if (e.emp_id == id) {
            printf("\nRecord Found. Enter new details:\n");
            printf("Enter New Name: ");
            fgets(e.name, sizeof(e.name), stdin);
            e.name[strcspn(e.name, "\n")] = 0;
            printf("Enter New Designation: ");
            fgets(e.designation, sizeof(e.designation), stdin);
            e.designation[strcspn(e.designation, "\n")] = 0;
            printf("Enter New Salary: ");
            scanf("%f", &e.salary);
            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&e, sizeof(Employee), 1, fp);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found) {
        printf("Record modified successfully.\n");
    } else {
        printf("Employee with ID %d not found!\n", id);
    }
}
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    FILE *temp = fopen("temp_emp.dat", "wb");
    if (temp == NULL) {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }
    int id, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    Employee e;
    while (fread(&e, sizeof(Employee), 1, fp)) {
        if (e.emp_id != id) {
            fwrite(&e, sizeof(Employee), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp_emp.dat", FILE_NAME);
    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Employee with ID %d not found!\n", id);
    }
}