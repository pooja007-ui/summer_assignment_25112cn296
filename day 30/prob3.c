#include <stdio.h>
#include <string.h>
#define MAX_EMP 100
#define MAX_NAME 50
#define MAX_DEPT 30
int main() {
    char names[MAX_EMP][MAX_NAME];
    char departments[MAX_EMP][MAX_DEPT];
    int emp_ids[MAX_EMP];
    float salaries[MAX_EMP];
    int count = 0;
    int choice;
    int search_id;
    int found;
    do {
        printf("\n--- Employee Management System ---\n");
        printf("1. Add an Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee Salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }
        while (getchar() != '\n');
        switch (choice) {
            case 1:
                if (count < MAX_EMP) {
                    printf("Enter Employee ID: ");
                    scanf("%d", &emp_ids[count]);
                    while (getchar() != '\n');
                    printf("Enter Employee Name: ");
                    fgets(names[count], MAX_NAME, stdin);
                    names[count][strcspn(names[count], "\n")] = '\0';
                    printf("Enter Department: ");
                    fgets(departments[count], MAX_DEPT, stdin);
                    departments[count][strcspn(departments[count], "\n")] = '\0';
                    printf("Enter Salary: ");
                    scanf("%f", &salaries[count]);
                    count++;
                    printf("Employee added successfully!\n");
                } else {
                    printf("System capacity reached! Cannot add more employees.\n");
                }
                break;
            case 2:
                if (count == 0) {
                    printf("No employee records available.\n");
                } else {
                    printf("\nID\tSalary\t\tDept\t\tName\n");
                    printf("------------------------------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%.2f\t\t%s\t\t%s\n", emp_ids[i], salaries[i], departments[i], names[i]);
                    }
                }
                break;
            case 3:
            case 4:
                if (count == 0) {
                    printf("No employee records available.\n");
                    break;
                }
                printf("Enter Employee ID: ");
                scanf("%d", &search_id);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (emp_ids[i] == search_id) {
                        found = 1;
                        if (choice == 3) {
                            printf("\n--- Employee Record ---\n");
                            printf("Name: %s\n", names[i]);
                            printf("ID: %d\n", emp_ids[i]);
                            printf("Department: %s\n", departments[i]);
                            printf("Salary: %.2f\n", salaries[i]);
                        } else if (choice == 4) {
                            printf("Current Salary: %.2f\n", salaries[i]);
                            printf("Enter New Salary: ");
                            scanf("%f", &salaries[i]);
                            printf("Salary updated successfully!\n");
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Employee with ID %d not found in the system.\n", search_id);
                }
                break;
            case 5:
                printf("Exiting the Employee Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}