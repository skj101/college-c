

// Circular Queue:
// Enqueue Operation:

// In a circular queue, when an element is enqueued, it is added to the rear of the queue.
// If the queue is full (rear is just behind front), further enqueuing is not possible.
// Dequeue Operation:

// In a circular queue, when an element is dequeued, it is removed from the front of the queue.
// If the queue is empty (both front and rear are -1), further dequeuing is not possible.
// Display Operation:

// The display operation shows all the elements in the queue from front to rear in a circular manner, wrapping around if needed.
// Full and Empty Checks:

// Fullness is determined when (front == 0 && rear == MAX_SIZE - 1) or (front == rear + 1) which indicates that the queue has wrapped around or reached its maximum capacity.
// Emptiness is determined when both front and rear are -1.
// Array Traversal:

// The array is traversed in a circular manner from front to rear, which may wrap around to the beginning of the array.


#include <stdio.h>

int MAX_SIZE;

int queue[100];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

int main() {
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &MAX_SIZE);

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if full\n");
        printf("5. Check if empty\n");
        printf("6. Display Front\n");
        printf("7. Display Rear\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    if (front == -1) {
                        front = 0;
                    }
                    rear = (rear + 1) % MAX_SIZE;
                    queue[rear] = value;
                    printf("%d enqueued successfully.\n", value);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    int removed = queue[front];
                    if (front == rear) {
                        front = rear = -1;
                    } else {
                        front = (front + 1) % MAX_SIZE;
                    }
                    printf("%d dequeued successfully.\n", removed);
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue elements: ");
                    int i = front;
                    do {
                        printf("%d ", queue[i]);
                        i = (i + 1) % MAX_SIZE;
                    } while (i != (rear + 1) % MAX_SIZE);
                    printf("\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                if (front != -1) {
                    printf("Front value: %d\n", queue[front]);
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 7:
                if (rear != -1) {
                    printf("Rear value: %d\n", queue[rear]);
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


// Key Differences:
// Handling Fullness:

// In a standard queue, once the rear reaches the end of the array, further enqueuing is not possible until elements are dequeued.
// In a circular queue, as long as there is space behind the front element, enqueuing is possible even if the rear reaches the end of the array.
// Array Traversal:

// In a standard queue, the array is traversed linearly from front to rear.
// In a circular queue, the array is traversed in a circular manner, potentially wrapping around to the beginning of the array.
// Implementation of Enqueue and Dequeue:

// In both implementations, elements are added to the rear and removed from the front. However, the handling of indices and wrap-around differs.
// Handling Empty Queue:

// Both types of queues have similar checks for emptiness. If both front and rear are -1, the queue is considered empty.
// Space Utilization:

// Circular queues may potentially make better use of the available space, as they allow wrapping around in the array.