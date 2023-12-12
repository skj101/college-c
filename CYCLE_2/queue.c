#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int main() {
    int choice, value;

    do {
        printf("\nQueue Operations:\n1. Enqueue\n2. Dequeue\n3. Display Front & Rear\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (rear == MAX_SIZE - 1) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    if (front == -1)
                        front = 0;
                    queue[++rear] = value;
                }
                break;

            case 2:
                if (front == -1) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    printf("Dequeued element: %d\n", queue[front]);
                    (front == rear) ? (front = rear = -1) : (front++);
                }
                break;

            case 3:
                if (front == -1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Front element: %d\nRear element: %d\n", queue[front], queue[rear]);
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
