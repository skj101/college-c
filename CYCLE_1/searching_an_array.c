#include <stdio.h>  // Include the standard input/output library which provides functions like printf and scanf.

int main() {  // Start of the main function.
    int size, choice;  // Declare variables size and choice.

    // Prompt user for the size of the array.
    printf("Enter the size of the array: ");
    scanf("%d", &size);  // Read the user's input and store it in the variable 'size'.

    if (size <= 0) {  // Check if the user entered a non-positive size.
        printf("Invalid array size.\n");  // Print an error message.
        return 1;  // Return 1 to indicate an error.
    }

    int arr[size];  // Declare an array 'arr' of size 'size'.
    printf("Enter %d elements:\n", size);  // Prompt user to enter 'size' elements.

    for (int i = 0; i < size; i++) {  // Loop to read 'size' number of elements from the user.
        scanf("%d", &arr[i]);  // Read an integer from the user and store it in the ith position of 'arr'.
    }

    int key;  // Declare a variable 'key' to store the element to be searched.

    while (1) {  // Start an infinite loop (loop will be exited manually).

        // Display menu for user to choose an operation.
        printf("1. Linear Search\n2. Binary Search\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);  // Read the user's choice and store it in the variable 'choice'.

        switch (choice) {  // Start a switch statement based on the user's choice.
            case 1: {  // If the choice is 1:

                printf("Enter the element to search for: ");  // Prompt user to enter the element to be searched.
                scanf("%d", &key);  // Read the user's input and store it in the variable 'key'.
                int i;

                // Linear Search Algorithm
                for (i = 0; i < size; i++) {  // Loop to search for 'key' in 'arr'.
                    if (arr[i] == key) {  // If 'key' is found:
                        printf("Element found at index %d.\n", i);  // Print the index where 'key' was found.
                        break;  // Exit the loop.
                    }
                }

                if (i == size) {  // If the loop completes without finding 'key':
                    printf("Element not found.\n");  // Print a message indicating 'key' was not found.
                }
                break;  // Exit the switch statement.
            }

            case 2: {  // If the choice is 2:

                printf("Enter the element to search for: ");  // Prompt user to enter the element to be searched.
                scanf("%d", &key);  // Read the user's input and store it in the variable 'key'.
                int left = 0, right = size - 1;
                int found = 0;  // Flag to track if the element is found

                // Binary Search Algorithm
                while (left <= right) {  // Continue the search as long as the range of search is valid.
                    int mid = left + (right - left) / 2;  // Calculate the midpoint of the range.

                    if (arr[mid] == key) {  // If 'key' is found at the midpoint:
                        printf("Element found at index %d.\n", mid);  // Print the index where 'key' was found.
                        found = 1;  // Set the flag indicating 'key' was found.
                        break;  // Exit the loop.
                    }

                    if (arr[mid] < key) {  // If 'key' is in the right half of the range:
                        left = mid + 1;  // Adjust the left boundary of the range.
                    } else {  // If 'key' is in the left half of the range:
                        right = mid - 1;  // Adjust the right boundary of the range.
                    }
                }

                if (!found) {  // If 'key' was not found after the loop completes:
                    printf("Element not found.\n");  // Print a message indicating 'key' was not found.
                }
                break;  // Exit the switch statement.
            }

            case 3:  // If the choice is 3:
                printf("Exiting...\n");  // Print a message indicating program exit.
                return 0;  // Return 0 to indicate successful program termination.

            default:  // If the choice is not 1, 2, or 3:
                printf("Invalid choice. Please try again.\n");  // Print an error message.
                break;  // Exit the switch statement.
        }
    }

    return 0;  // Return 0 to indicate successful program termination.
}
