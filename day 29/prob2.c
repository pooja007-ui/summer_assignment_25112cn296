#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice, i, pos, value, found;
    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Create (Input elements)\n");
        printf("2. Display elements\n");
        printf("3. Insert an element\n");
        printf("4. Delete an element\n");
        printf("5. Search for an element\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of elements you want to add (max %d): ", MAX_SIZE);
                scanf("%d", &n);
                if (n > MAX_SIZE || n < 0) {
                    printf("Invalid size! Please enter a value between 0 and %d.\n", MAX_SIZE);
                    n = 0;
                } else {
                    printf("Enter %d elements:\n", n);
                    for (i = 0; i < n; i++) {
                        printf("Element [%d]: ", i);
                        scanf("%d", &arr[i]);
                    }
                    printf("Array created successfully.\n");
                }
                break;
            case 2:
                if (n == 0) {
                    printf("The array is currently empty.\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                if (n == MAX_SIZE) {
                    printf("Array is full! Cannot insert new elements.\n");
                    break;
                }
                printf("Enter the index position for insertion (0 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Invalid position! Please enter an index between 0 and %d.\n", n);
                } else {
                    printf("Enter the value to insert: ");
                    scanf("%d", &value);
                    for (i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    n++;
                    printf("Element %d inserted at index %d.\n", value, pos);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("Array is empty! Nothing to delete.\n");
                    break;
                }
                printf("Enter the index position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    value = arr[pos];
                    for (i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Element %d deleted from index %d.\n", value, pos);
                }
                break;
            case 5:
                if (n == 0) {
                    printf("Array is empty! Cannot search.\n");
                    break;
                }
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                found = -1;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        found = i;
                        break;    
                    }
                }
                if (found != -1) {
                    printf("Element %d found at index %d.\n", value, found);
                } else {
                    printf("Element %d not found in the array.\n", value);
                }
                break;
            case 6:
                printf("Exiting the array operations system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);
    return 0;
}