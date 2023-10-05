#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
int listSize = 0;
int MAX_SIZE;

#define isFull() (listSize >= MAX_SIZE)
#define isEmpty() (listSize == 0)

int main() {
    printf("Enter the maximum size of the linked list: ");
    scanf("%d", &MAX_SIZE);

    int choice, value, position;

    while (1) {
        printf("\nLinked List Operations:\n 1. Insert at Head\n 2. Insert at Tail\n 3. Insert at Position\n 4. Delete at Head\n 5. Delete at Tail\n 6. Delete at Position\n 7. Display\n 8. Exit\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: case 2: case 3: {
                if (isFull()) {
                    printf("List is full. Cannot insert.\n");
                } else {
                    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                    if (!newNode) exit(EXIT_FAILURE);
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    newNode->data = value;
                    newNode->next = (choice == 3) ? NULL : head;
                    head = (choice == 1) ? newNode : head;
                    if (choice == 3) {
                        printf("Enter position: ");
                        scanf("%d", &position);
                        if (position < 1 || position > listSize + 1) {
                            printf("Invalid position. Position should be between 1 and %d.\n", listSize + 1);
                            free(newNode); 
                        } else {
                            struct Node* temp = head;
                            for (int i = 1; i < position - 1; i++) temp = temp->next;
                            newNode->next = temp->next;
                            temp->next = newNode;
                            listSize++;
                        }
                    } else listSize++;
                }
                break;
            }
            case 4: case 5: case 6: {
                if (isEmpty()) {
                    printf("List is empty. Nothing to delete.\n");
                } else {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                    if (choice == 4) listSize--;
                    else if (choice == 5) listSize = (head == NULL) ? 0 : listSize;
                    else if (choice == 6) {
                        printf("Enter position to delete: ");
                        scanf("%d", &position);
                        if (position < 1 || position > listSize) {
                            printf("Invalid position. Position should be between 1 and %d.\n", listSize);
                        } else {
                            struct Node* temp = head;
                            struct Node* prev = NULL;
                            for (int i = 1; i < position; i++) {
                                prev = temp;
                                temp = temp->next;
                            }
                            prev->next = temp->next;
                            free(temp);
                            listSize--;
                        }
                    }
                }
                break;
            }
            case 7: {
                if (isEmpty()) {
                    printf("List is empty.\n");
                } else {
                    struct Node* temp = head;
                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;
            }
            case 8:
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


// Data Structure (Node):

// The code uses a linked list data structure to store a sequence of elements. Each element is represented by a struct Node which contains an integer data and a pointer next pointing to the next node in the sequence.
// Global Variables:

// struct Node* head: This is a pointer to the first node in the linked list. It starts as NULL to indicate an empty list.
// int listSize: Keeps track of the current size of the linked list.
// int MAX_SIZE: The maximum size of the linked list, which is set by the user.
// isFull() and isEmpty():

// These are macro functions defined using #define. They return 1 if the linked list is full or empty, respectively, based on the defined MAX_SIZE and listSize.
// Menu and User Input:

// The program displays a menu of operations for the user to choose from.
// It prompts the user to enter a choice (integer) based on the menu.
// Switch Statement:

// The program uses a switch statement to execute different actions based on the user's choice.
// Insertion Operations:

// The program handles three cases of insertion: at head, at tail, and at a specified position.
// Depending on the choice, it checks if the list is full, allocates memory for a new node, prompts the user for the value to insert, and performs the insertion.
// Deletion Operations:

// Similar to insertion, the program handles three cases of deletion: at head, at tail, and at a specified position.
// It checks if the list is empty, frees the memory of the deleted node, and updates listSize accordingly.
// Display Operation:

// This operation traverses the linked list and prints the data of each node.
// Exit Operation:

// Choosing '8' in the menu exits the program. Before exiting, it frees all allocated memory by traversing the list and deleting each node.
// Memory Allocation and Deallocation:

// malloc() is used to allocate memory for a new node.
// free() is used to deallocate memory when a node is deleted.
// Error Handling:

// The program checks for cases where the user tries to insert into a full list, delete from an empty list, or access an invalid position.
// Looping:

// The program runs in an infinite loop (while (1)) until the user chooses to exit.
// Preprocessor Directives:

// #include: Includes necessary header files.
// #define: Defines macros for simplifying code and improving readability.