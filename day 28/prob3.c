#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_EVENTS 50
#define MAX_NAME_LENGTH 100
#define STARTING_EVENT_ID 101
typedef struct {
    int event_id;
    char name[MAX_NAME_LENGTH];
    int total_seats;
    int available_seats;
    double ticket_price;
} Event;
Event schedule[MAX_EVENTS];
int event_count = 0;
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int findEventIndex(int event_id) {
    for (int i = 0; i < event_count; i++) {
        if (schedule[i].event_id == event_id) {
            return i;
        }
    }
    return -1;
}
void addEvent() {
    if (event_count >= MAX_EVENTS) {
        printf("\nError: System capacity reached. Cannot add more events.\n");
        return;
    }
    Event newEvent;
    newEvent.event_id = STARTING_EVENT_ID + event_count;
    printf("\nEnter Event Name (e.g., Movie Title, Concert): ");
    fgets(newEvent.name, MAX_NAME_LENGTH, stdin);
    newEvent.name[strcspn(newEvent.name, "\n")] = 0;
    printf("Enter Total Number of Seats: ");
    scanf("%d", &newEvent.total_seats);
    printf("Enter Ticket Price: $");
    scanf("%lf", &newEvent.ticket_price);
    clearInputBuffer();
    if (newEvent.total_seats <= 0) newEvent.total_seats = 50;
    if (newEvent.ticket_price < 0) newEvent.ticket_price = 0.0;
    newEvent.available_seats = newEvent.total_seats;
    schedule[event_count] = newEvent;
    event_count++;
    printf("\nSuccess: Event '%s' added. Event ID is %d.\n", newEvent.name, newEvent.event_id);
}
void displayEvents() {
    if (event_count == 0) {
        printf("\nNo events are currently scheduled.\n");
        return;
    }
    printf("\n--- Available Events ---\n");
    printf("%-10s %-30s %-10s %-15s %-10s\n", "Event ID", "Event Name", "Price", "Available Seats", "Total");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < event_count; i++) {
        printf("%-10d %-30s $%-9.2f %-15d %-10d\n", 
            schedule[i].event_id, 
            schedule[i].name, 
            schedule[i].ticket_price,
            schedule[i].available_seats,
            schedule[i].total_seats);
    }
}
void bookTicket() {
    if (event_count == 0) {
        printf("\nNo events available for booking.\n");
        return;
    }
    int id, index, tickets_to_book;
    printf("\nEnter Event ID to book: ");
    scanf("%d", &id);
    index = findEventIndex(id);
    if (index == -1) {
        printf("\nError: Event ID %d not found.\n", id);
        clearInputBuffer();
        return;
    }
    if (schedule[index].available_seats == 0) {
        printf("\nSorry, '%s' is completely sold out!\n", schedule[index].name);
        clearInputBuffer();
        return;
    }
    printf("How many tickets would you like to book? (Available: %d): ", schedule[index].available_seats);
    scanf("%d", &tickets_to_book);
    clearInputBuffer();
    if (tickets_to_book <= 0) {
        printf("\nError: You must book at least one ticket.\n");
    } else if (tickets_to_book > schedule[index].available_seats) {
        printf("\nError: Only %d seats are available. You cannot book %d.\n", schedule[index].available_seats, tickets_to_book);
    } else {
        schedule[index].available_seats -= tickets_to_book;
        double total_cost = tickets_to_book * schedule[index].ticket_price;
        printf("\n--- Booking Confirmed ---\n");
        printf("Event: %s\n", schedule[index].name);
        printf("Tickets: %d\n", tickets_to_book);
        printf("Total Cost: $%.2f\n", total_cost);
        printf("-------------------------\n");
    }
}
void cancelTicket() {
    int id, index, tickets_to_cancel;
    printf("\nEnter Event ID for cancellation: ");
    scanf("%d", &id);
    index = findEventIndex(id);
    if (index == -1) {
        printf("\nError: Event ID %d not found.\n", id);
        clearInputBuffer();
        return;
    }
    printf("How many tickets are you canceling?: ");
    scanf("%d", &tickets_to_cancel);
    clearInputBuffer();
    if (tickets_to_cancel <= 0) {
        printf("\nError: You must cancel at least one ticket.\n");
    } else if (schedule[index].available_seats + tickets_to_cancel > schedule[index].total_seats) {
        printf("\nError: Invalid cancellation. This exceeds the total venue capacity.\n");
    } else {
        schedule[index].available_seats += tickets_to_cancel;
        double refund = tickets_to_cancel * schedule[index].ticket_price;
        printf("\n--- Cancellation Successful ---\n");
        printf("Event: %s\n", schedule[index].name);
        printf("Refund Amount: $%.2f\n", refund);
        printf("-------------------------------\n");
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n===============================\n");
        printf("     Ticket Booking System     \n");
        printf("===============================\n");
        printf("1. Add New Event (Admin)\n");
        printf("2. View All Events\n");
        printf("3. Book Tickets\n");
        printf("4. Cancel Tickets\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:
                addEvent();
                break;
            case 2:
                displayEvents();
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                printf("\nExiting the system. Have a great day!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}