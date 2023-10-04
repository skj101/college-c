#include <stdio.h>
#include <stdlib.h>

int stack[100], size, top = -1;

void push(int value)
{
	if(top == size-1)
	{
	printf("Stack Overflow\n");
	return;
	}
	top++;
	stack[top] = value;
}

void pop()
	{
	if(top == -1)
	{
	printf("Stack Underflow\n");
	return;
	}
	top--;
}

void display()
	{
	if(top == -1)
	{
	printf("Stack is empty\n");
	return;
	}
	for(int i=top; i>=0; i--)
	printf("%d\n", stack[i]);
}

int main()
{
	int choice, value;
	printf("Enter size of stack: ");
	scanf("%d", &size);

	while(1)
	{
    	printf("\nEnter your choice:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    	scanf("%d", &choice);

    	switch(choice)
    	{
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
   	 }
}
return 0;
}
