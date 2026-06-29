#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;
int main() {
    Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice, i, searchId, found, c;
    do {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add New Item\n");
        printf("2. Display Inventory\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        while ((c = getchar()) != '\n' && c != EOF);
        switch (choice) {
            case 1:
                if (itemCount >= MAX_ITEMS) {
                    printf("Error: Inventory capacity reached!\n");
                    break;
                }
                printf("Enter Item ID: ");
                scanf("%d", &inventory[itemCount].id);
                while ((c = getchar()) != '\n' && c != EOF);
                printf("Enter Item Name: ");
                fgets(inventory[itemCount].name, sizeof(inventory[itemCount].name), stdin);
                inventory[itemCount].name[strcspn(inventory[itemCount].name, "\n")] = 0;
                printf("Enter Item Quantity: ");
                scanf("%d", &inventory[itemCount].quantity);
                printf("Enter Item Price: ");
                scanf("%f", &inventory[itemCount].price);
                itemCount++;
                printf("Item successfully added to inventory.\n");
                break;
            case 2:
                if (itemCount == 0) {
                    printf("The inventory is currently empty.\n");
                    break;
                }
                printf("\n%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
                printf("------------------------------------------------------------\n");
                for (i = 0; i < itemCount; i++) {
                    printf("%-10d %-25s %-10d %.2f\n", 
                           inventory[i].id, 
                           inventory[i].name, 
                           inventory[i].quantity, 
                           inventory[i].price);
                }
                break;
            case 3:
                if (itemCount == 0) {
                    printf("The inventory is currently empty.\n");
                    break;
                }
                printf("Enter Item ID to search: ");
                scanf("%d", &searchId);
                found = 0;
                for (i = 0; i < itemCount; i++) {
                    if (inventory[i].id == searchId) {
                        printf("\n--- Item Found ---\n");
                        printf("ID: %d\n", inventory[i].id);
                        printf("Name: %s\n", inventory[i].name);
                        printf("Quantity: %d\n", inventory[i].quantity);
                        printf("Price: %.2f\n", inventory[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Error: Item with ID %d not found in inventory.\n", searchId);
                }
                break;
            case 4:
                if (itemCount == 0) {
                    printf("The inventory is currently empty.\n");
                    break;
                }
                printf("Enter Item ID to update: ");
                scanf("%d", &searchId);
                found = 0;
                for (i = 0; i < itemCount; i++) {
                    if (inventory[i].id == searchId) {
                        printf("Current Quantity: %d\n", inventory[i].quantity);
                        printf("Enter New Quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("Item quantity successfully updated.\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Error: Item with ID %d not found in inventory.\n", searchId);
                }
                break;
            case 5:
                printf("Exiting Inventory Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}