#include <stdio.h>  
#define MAX_SIZE 100  

int main() {  
    int stack[MAX_SIZE], choice, value, size, top = -1;  
    printf("Enter size of stack: ");  
    scanf("%d", &size);  
    while (1) {  
        printf("\nEnter your choice:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");  
        scanf("%d", &choice);  

        switch (choice) {  
            case 1:  
                if (top == size - 1)  
                    printf("Stack Overflow\n");  
                else {  
                    printf("Enter value to push: ");  
                    scanf("%d", &value);  
                    stack[++top] = value;  
                }
                break;  
            case 2:  
                if (top == -1)  
                    printf("Stack Underflow\n");  
                else  
                    top--;  
                break;  
            case 3:  
                if (top == -1)  
                    printf("Stack is empty\n");  
                else  
                    for (int i = top; i >= 0; i--)  
                        printf("%d\n", stack[i]);  
                break;  
            case 4:  
                return 0;  
            default:  
                printf("Invalid choice\n");  
                break;  
        }
    }

    return 0;  
}
