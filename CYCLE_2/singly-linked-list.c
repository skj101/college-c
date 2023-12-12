#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0; // Current size of the array

void insertAtHead(int value) {
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;
    size++;
}

void insertAtTail(int value) {
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    array[size] = value;
    size++;
}

void insertAtPosition(int value, int position) {
    if (size == MAX_SIZE || position < 1 || position > size + 1) {
        printf("Invalid position or array is full.\n");
        return;
    }
    for (int i = size; i >= position; i--) {
        array[i] = array[i - 1];
    }
    array[position - 1] = value;
    size++;
}

void deleteAtHead() {
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

void deleteAtTail() {
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    size--;
}

void deleteAtPosition(int position) {
    if (size == 0 || position < 1 || position > size) {
        printf("Invalid position or array is empty.\n");
        return;
    }
    for (int i = position - 1; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

void search(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            printf("%d found at position %d.\n", value, i + 1);
            return;
        }
    }
    printf("%d not found in the array.\n", value);
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int choice, value, position;

    do {
        printf("\nArray Operations:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Head\n");
        printf("5. Delete at Tail\n");
        printf("6. Delete at Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtHead(value);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtTail(value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;

            case 4:
                deleteAtHead();
                break;

            case 5:
                deleteAtTail();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 9);
    return 0;
}
