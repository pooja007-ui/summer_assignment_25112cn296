#include<stdio.h>
int main() {
    int score = 0;
    int answer;
    int status;
    printf("   Welcome to the C Programming Quiz!   \n");
    printf("Question 1: Who created the C programming language?\n");
    printf("1. Guido van Rossum\n");
    printf("2. James Gosling\n");
    printf("3. Dennis Ritchie\n");
    printf("4. Bjarne Stroustrup\n");
    while (1) {
        printf("Enter your answer (1-4): ");
        status = scanf("%d", &answer);
        if (status != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
        } else if (answer < 1 || answer > 4) {
            printf("Please select a valid option (1, 2, 3, or 4).\n");
        } else {
            if (answer == 3) {
                printf("Correct!\n\n");
                score++;
            } else {
                printf("Incorrect. The correct answer was 3. Dennis Ritchie.\n\n");
            }
            break;
        }
    }
    printf("Question 2: What symbol must you use in scanf to point to a variable's memory address?\n");
    printf("1. *\n");
    printf("2. &\n");
    printf("3. %%\n");
    printf("4. #\n");
    while (1) {
        printf("Enter your answer (1-4): ");
        status = scanf("%d", &answer);
        if (status != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        } else if (answer < 1 || answer > 4) {
            printf("Please select a valid option (1, 2, 3, or 4).\n");
        } else {
            if (answer == 2) {
                printf("Correct! Never forget the ampersand!\n\n");
                score++;
            } else {
                printf("Incorrect. The correct answer was 2. & (Ampersand).\n\n");
            }
            break;
        }
    }
    printf("Question 3: Which of these is NOT a built-in data type in standard C?\n");
    printf("1. int\n");
    printf("2. float\n");
    printf("3. char\n");
    printf("4. string\n");
    while (1) {
        printf("Enter your answer (1-4): ");
        status = scanf("%d", &answer);
        if (status != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        } else if (answer < 1 || answer > 4) {
            printf("Please select a valid option (1, 2, 3, or 4).\n");
        } else {
            if (answer == 4) {
                printf("Correct! C uses arrays of chars instead of a dedicated string type.\n\n");
                score++;
            } else {
                printf("Incorrect. The correct answer was 4. string.\n\n");
            }
            break; 
        }
    }
    printf("========================================\n");
    printf("Quiz Complete! Your final score is: %d/3\n", score);   
    if (score == 3) {
        printf("Excellent job! You're a C master.\n");
    } else if (score == 2) {
        printf("Great work! Just one mistake.\n");
    } else {
        printf("Keep studying! You'll get it next time.\n");
    }
    printf("========================================\n");
    return 0;
}