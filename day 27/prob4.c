#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int roll_no;
    char name[50];
    float math;
    float science;
    float english;
    float computer;
    float history;
    float total;
    float percentage;
    char grade;
} Marksheet;
void addRecord();
void displayAllRecords();
void searchAndPrintMarksheet();
void modifyRecord();
void deleteRecord();
void clearBuffer();
void calculateGrades(Marksheet *m);
void printMarksheetBox(Marksheet m);
const char *FILE_NAME = "marksheet.dat";
int main() {
    int choice;
    while (1) {
        printf("\n=== Marksheet Generation System ===\n");
        printf("1. Add Student Marks\n");
        printf("2. Display All Records\n");
        printf("3. Search & Generate Marksheet\n");
        printf("4. Modify Student Marks\n");
        printf("5. Delete Student Record\n");
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
            case 2: displayAllRecords(); break;
            case 3: searchAndPrintMarksheet(); break;
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
void calculateGrades(Marksheet *m) {
    m->total = m->math + m->science + m->english + m->computer + m->history;
    m->percentage = m->total / 5.0;   
    if (m->percentage >= 90.0) {
        m->grade = 'A';
    } else if (m->percentage >= 80.0) {
        m->grade = 'B';
    } else if (m->percentage >= 70.0) {
        m->grade = 'C';
    } else if (m->percentage >= 60.0) {
        m->grade = 'D';
    } else {
        m->grade = 'F';
    }
}
void printMarksheetBox(Marksheet m) {
    printf("\n================================================\n");
    printf("               ACADEMIC MARKSHEET               \n");
    printf("================================================\n");
    printf("Roll No: %-10d Name: %s\n", m.roll_no, m.name);
    printf("------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "SUBJECT", "MARKS", "MAX MARKS");
    printf("------------------------------------------------\n");
    printf("%-20s %-10.2f %-10s\n", "Mathematics", m.math, "100");
    printf("%-20s %-10.2f %-10s\n", "Science", m.science, "100");
    printf("%-20s %-10.2f %-10s\n", "English", m.english, "100");
    printf("%-20s %-10.2f %-10s\n", "Computer Science", m.computer, "100");
    printf("%-20s %-10.2f %-10s\n", "History", m.history, "100");
    printf("------------------------------------------------\n");
    printf("Total Marks : %.2f / 500\n", m.total);
    printf("Percentage  : %.2f%%\n", m.percentage);
    printf("Grade       : %c\n", m.grade);
    printf("================================================\n");
}
void addRecord() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }   
    Marksheet m;
    printf("\n--- Add Student Marks ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &m.roll_no);
    clearBuffer();
    printf("Enter Name: ");
    fgets(m.name, sizeof(m.name), stdin);
    m.name[strcspn(m.name, "\n")] = 0;
    printf("Enter Marks for Mathematics (out of 100): ");
    scanf("%f", &m.math);
    printf("Enter Marks for Science (out of 100): ");
    scanf("%f", &m.science);
    printf("Enter Marks for English (out of 100): ");
    scanf("%f", &m.english);
    printf("Enter Marks for Computer Science (out of 100): ");
    scanf("%f", &m.computer);
    printf("Enter Marks for History (out of 100): ");
    scanf("%f", &m.history);
    calculateGrades(&m);
    fwrite(&m, sizeof(Marksheet), 1, fp);
    fclose(fp);
    printf("Record added successfully! Percentage: %.2f%%, Grade: %c\n", m.percentage, m.grade);
}
void displayAllRecords() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found. The database is empty.\n");
        return;
    }   
    Marksheet m;
    printf("\n%-8s %-15s %-7s %-7s %-7s %-7s %-7s %-8s %-6s %-5s\n", 
           "Roll No", "Name", "Math", "Sci", "Eng", "Comp", "Hist", "Total", "Perc", "Grade");
    printf("--------------------------------------------------------------------------------------\n");
    while (fread(&m, sizeof(Marksheet), 1, fp)) {
        printf("%-8d %-15s %-7.1f %-7.1f %-7.1f %-7.1f %-7.1f %-8.1f %-6.1f %-5c\n", 
               m.roll_no, m.name, m.math, m.science, m.english, m.computer, m.history, 
               m.total, m.percentage, m.grade);
    } 
    fclose(fp);
}
void searchAndPrintMarksheet() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    int roll, found = 0;
    printf("\nEnter Roll Number to generate marksheet: ");
    scanf("%d", &roll);
    Marksheet m;
    while (fread(&m, sizeof(Marksheet), 1, fp)) {
        if (m.roll_no == roll) {
            printMarksheetBox(m);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nRecord for Roll Number %d not found!\n", roll);
    }
    fclose(fp);
}
void modifyRecord() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    int roll, found = 0;
    printf("\nEnter Roll Number to modify marks: ");
    scanf("%d", &roll);
    clearBuffer();
    Marksheet m;
    while (fread(&m, sizeof(Marksheet), 1, fp)) {
        if (m.roll_no == roll) {
            printf("\nRecord Found. Enter new marks:\n");
            printf("Enter New Math Marks: ");
            scanf("%f", &m.math);
            printf("Enter New Science Marks: ");
            scanf("%f", &m.science);
            printf("Enter New English Marks: ");
            scanf("%f", &m.english);
            printf("Enter New Computer Science Marks: ");
            scanf("%f", &m.computer);
            printf("Enter New History Marks: ");
            scanf("%f", &m.history);
            calculateGrades(&m);
            fseek(fp, -sizeof(Marksheet), SEEK_CUR);
            fwrite(&m, sizeof(Marksheet), 1, fp);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found) {
        printf("Marks updated successfully. New Grade: %c\n", m.grade);
    } else {
        printf("Record for Roll Number %d not found!\n", roll);
    }
}
void deleteRecord() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }   
    FILE *temp = fopen("temp_marks.dat", "wb");
    if (temp == NULL) {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }
    int roll, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    Marksheet m;
    while (fread(&m, sizeof(Marksheet), 1, fp)) {
        if (m.roll_no != roll) {
            fwrite(&m, sizeof(Marksheet), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp_marks.dat", FILE_NAME);
    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record for Roll Number %d not found!\n", roll);
    }
}