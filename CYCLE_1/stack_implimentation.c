#include <stdio.h>  // Include the standard input/output library which provides functions like printf and scanf.
#define MAX_SIZE 100  // Define a constant MAX_SIZE with the value 100. This will be used to specify the maximum size of the stack.

int main() {  // Start of the main function.
    int stack[MAX_SIZE], choice, value, size, top = -1;  // Declare an array 'stack' to represent the stack, and variables choice, value, size, and top. Initialize top to -1.

    printf("Enter size of stack: ");  // Print a message asking the user to enter the size of the stack.
    scanf("%d", &size);  // Read the user's input and store it in the variable size.

    while (1) {  // Start an infinite loop (loop will be exited manually).
        printf("\nEnter your choice:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");  // Print a menu for the user to choose an operation.
        scanf("%d", &choice);  // Read the user's choice and store it in the variable choice.

        switch (choice) {  // Start a switch statement based on the user's choice.
            case 1:  // If the choice is 1:
                if (top == size - 1)  // If the stack is already full:
                    printf("Stack Overflow\n");  // Print an error message.
                else {  // If there is space in the stack:
                    printf("Enter value to push: ");  // Print a message asking the user for a value to push.
                    scanf("%d", &value);  // Read the value from the user.
                    stack[++top] = value;  // Push the value onto the stack and update the top of the stack.
                }
                break;  // Exit the switch statement.
            case 2:  // If the choice is 2:
                if (top == -1)  // If the stack is already empty:
                    printf("Stack Underflow\n");  // Print an error message.
                else  // If there are elements in the stack:
                    top--;  // Pop an element from the stack by decrementing the top.
                break;  // Exit the switch statement.
            case 3:  // If the choice is 3:
                if (top == -1)  // If the stack is empty:
                    printf("Stack is empty\n");  // Print a message indicating that the stack is empty.
                else  // If there are elements in the stack:
                    for (int i = top; i >= 0; i--)  // Start a loop to display the elements of the stack from top to bottom.
                        printf("%d\n", stack[i]);  // Print each element on a new line.
                break;  // Exit the switch statement.
            case 4:  // If the choice is 4:
                return 0;  // Return 0 to indicate successful program termination.
            default:  // If the choice is not 1, 2, 3, or 4:
                printf("Invalid choice\n");  // Print an error message.
                break;  // Exit the switch statement.
        }
    }

    return 0;  // Return 0 to indicate successful program termination.
}
