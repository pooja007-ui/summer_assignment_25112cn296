#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int emp_id;
    char name[50];
    float basic_salary;
    float allowances;
    float deductions;
    float net_salary;
} SalaryRecord;
void addRecord();
void displayRecords();
void searchRecord();
void modifyRecord();
void deleteRecord();
void clearBuffer();
void generatePayslip(SalaryRecord r);
const char *FILE_NAME = "salary.dat";
int main() {
    int choice;
    while (1) {
        printf("\n=== Salary Management System ===\n");
        printf("1. Add Salary Record\n");
        printf("2. Display All Records\n");
        printf("3. Search & Print Payslip\n");
        printf("4. Modify Salary Record\n");
        printf("5. Delete Salary Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();
        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: modifyRecord(); break;
            case 5: deleteRecord(); break;
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
void generatePayslip(SalaryRecord r) {
    printf("\n========================================\n");
    printf("              SALARY SLIP               \n");
    printf("========================================\n");
    printf("Employee ID   : %d\n", r.emp_id);
    printf("Name          : %s\n", r.name);
    printf("----------------------------------------\n");
    printf("Basic Salary  : $%.2f\n", r.basic_salary);
    printf("Allowances(+) : $%.2f\n", r.allowances);
    printf("Deductions(-) : $%.2f\n", r.deductions);
    printf("----------------------------------------\n");
    printf("NET SALARY    : $%.2f\n", r.net_salary);
    printf("========================================\n");
}
void addRecord() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }   
    SalaryRecord r;
    printf("\n--- Add Salary Record ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &r.emp_id);
    clearBuffer();
    printf("Enter Name: ");
    fgets(r.name, sizeof(r.name), stdin);
    r.name[strcspn(r.name, "\n")] = 0;
    printf("Enter Basic Salary: ");
    scanf("%f", &r.basic_salary);
    printf("Enter Total Allowances (Bonus, Medical, etc.): ");
    scanf("%f", &r.allowances);
    printf("Enter Total Deductions (Tax, PF, etc.): ");
    scanf("%f", &r.deductions);
    r.net_salary = r.basic_salary + r.allowances - r.deductions;
    fwrite(&r, sizeof(SalaryRecord), 1, fp);
    fclose(fp);
    printf("Salary record added successfully! Net Salary calculated as $%.2f\n", r.net_salary);
}
void displayRecords() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found. The database is empty.\n");
        return;
    }   
    SalaryRecord r;
    printf("\n%-8s %-18s %-12s %-12s %-12s %-12s\n", "Emp ID", "Name", "Basic", "Allowances", "Deductions", "Net Salary");
    printf("--------------------------------------------------------------------------------\n");
    while (fread(&r, sizeof(SalaryRecord), 1, fp)) {
        printf("%-8d %-18s $%-11.2f $%-11.2f $%-11.2f $%-11.2f\n", 
               r.emp_id, r.name, r.basic_salary, r.allowances, r.deductions, r.net_salary);
    }
    fclose(fp);
}
void searchRecord() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    int id, found = 0;
    printf("\nEnter Employee ID to generate payslip: ");
    scanf("%d", &id);
    SalaryRecord r;
    while (fread(&r, sizeof(SalaryRecord), 1, fp)) {
        if (r.emp_id == id) {
            generatePayslip(r);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nRecord for Employee ID %d not found!\n", id);
    }
    fclose(fp);
}
void modifyRecord() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    int id, found = 0;
    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &id);
    clearBuffer();
    SalaryRecord r;
    while (fread(&r, sizeof(SalaryRecord), 1, fp)) {
        if (r.emp_id == id) {
            printf("\nRecord Found. Enter new financial details:\n");
            printf("Enter New Basic Salary: ");
            scanf("%f", &r.basic_salary);
            printf("Enter New Total Allowances: ");
            scanf("%f", &r.allowances);
            printf("Enter New Total Deductions: ");
            scanf("%f", &r.deductions);
            r.net_salary = r.basic_salary + r.allowances - r.deductions;
            fseek(fp, -sizeof(SalaryRecord), SEEK_CUR);
            fwrite(&r, sizeof(SalaryRecord), 1, fp);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found) {
        printf("Record modified successfully. New Net Salary is $%.2f\n", r.net_salary);
    } else {
        printf("Record for Employee ID %d not found!\n", id);
    }
}
void deleteRecord() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    FILE *temp = fopen("temp_salary.dat", "wb");
    if (temp == NULL) {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }
    int id, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    SalaryRecord r;
    while (fread(&r, sizeof(SalaryRecord), 1, fp)) {
        if (r.emp_id != id) {
            fwrite(&r, sizeof(SalaryRecord), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp_salary.dat", FILE_NAME);
    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record for Employee ID %d not found!\n", id);
    }
}