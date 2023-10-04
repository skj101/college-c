#include <stdio.h>  // Include the standard input/output library which provides functions like printf and scanf.

#define MAX_SIZE 100  // Define a constant MAX_SIZE with the value 100. This will be used to specify the maximum size of arrays.

int main() {  // Start of the main function.
    int arr1[MAX_SIZE], arr2[MAX_SIZE], size1, size2;  // Declare two arrays arr1 and arr2 with a maximum size of MAX_SIZE, and two variables size1 and size2 to store their respective sizes.
    int choice, element, position, merged = 0;  // Declare variables choice, element, position, and merged. Initialize merged to 0.

    // Getting sizes and elements of the arrays from the user
    printf("Enter the size of the first array (max %d): ", MAX_SIZE);  // Print a message asking the user to enter the size of the first array.
    scanf("%d", &size1);  // Read the user's input and store it in the variable size1.

    printf("Enter elements of the first array: ");  // Print a message asking the user to enter elements of the first array.
    for (int i = 0; i < size1; i++)  // Start a loop to read elements into arr1.
        scanf("%d", &arr1[i]);  // Read an integer from the user and store it in the ith position of arr1.

    printf("Enter the size of the second array (max %d): ", MAX_SIZE - size1);  // Print a message asking the user to enter the size of the second array, considering the remaining space after the first array.
    scanf("%d", &size2);  // Read the user's input and store it in the variable size2.

    printf("Enter elements of the second array: ");  // Print a message asking the user to enter elements of the second array.
    for (int i = 0; i < size2; i++)  // Start a loop to read elements into arr2.
        scanf("%d", &arr2[i]);  // Read an integer from the user and store it in the ith position of arr2.

    while (1) {  // Start an infinite loop (loop will be exited manually).
        // Displaying menu and taking user's choice
        printf("\nSelect an option:\n 1. Insert\n 2. Delete\n 3. Sort\n 4. Merge\n 5. Exit\n");  // Print a menu for the user to choose an operation.
        scanf("%d", &choice);  // Read the user's choice and store it in the variable choice.

        switch (choice) {  // Start a switch statement based on the user's choice.
            case 1: {  // If the choice is 1:
                // Insertion logic
                printf("Enter element and position for insertion: ");  // Print a message asking the user for an element and position for insertion.
                scanf("%d %d", &element, &position);  // Read the element and position from the user.
                if (size1 < MAX_SIZE && position >= 1 && position <= size1 + 1) {  // If conditions for insertion are met:
                    for (int i = size1; i >= position; i--)  // Start a loop to shift elements to make space for the new element.
                        arr1[i] = arr1[i - 1];  // Move the element one position to the right.
                    arr1[position - 1] = element;  // Insert the new element at the specified position.
                    size1++;  // Increase the size of arr1.
                    printf("Element inserted.\n");  // Print a message confirming the insertion.
                } else  // If conditions for insertion are not met:
                    printf("Invalid position for insertion.\n");  // Print an error message.
                break;  // Exit the switch statement.
            }
            // (cases 2, 3, and 4 are similar with different operations)
            case 2: {  // If the choice is 2:
                // Deletion logic
                printf("Enter position for deletion: ");  // Print a message asking the user for a position for deletion.
                scanf("%d", &position);  // Read the position from the user.
                if (position >= 1 && position <= size1) {  // If conditions for deletion are met:
                    for (int i = position - 1; i < size1 - 1; i++)  // Start a loop to shift elements to fill the deleted position.
                        arr1[i] = arr1[i + 1];  // Move the element one position to the left.
                    size1--;  // Decrease the size of arr1.
                    printf("Element deleted.\n");  // Print a message confirming the deletion.
                } else  // If conditions for deletion are not met:
                    printf("Invalid position for deletion.\n");  // Print an error message.
                break;  // Exit the switch statement.
            }
            case 3: {  // If the choice is 3:
                // Sorting logic
                for (int i = 0; i < size1 - 1; i++) {  // Start nested loops for a bubble sort algorithm.
                    for (int j = 0; j < size1 - i - 1; j++) {  // Inner loop for comparisons and swaps.
                        if (arr1[j] > arr1[j + 1]) {  // If elements are out of order:
                            int temp = arr1[j];  // Swap them.
                            arr1[j] = arr1[j + 1];
                            arr1[j + 1] = temp;
                        }
                    }
                }
                printf("Array sorted.\n");  // Print a message confirming the sorting.
                break;  // Exit the switch statement.
            }
            case 4: {  // If the choice is 4:
                // Merging logic
                if (merged == 0) {  // If arrays haven't been merged yet:
                    int result[MAX_SIZE];  // Declare an array result to store the merged result.
                    int i = 0, j = 0, k = 0;  // Initialize variables for array indices.
                    while (i < size1 && j < size2) {  // Start a loop to merge elements from arr1 and arr2.
                        result[k++] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];  // Compare elements and store the smaller one in result.
                    }
                    while (i < size1) result[k++] = arr1[i++];  // Copy remaining elements from arr1.
                    while (j < size2) result[k++] = arr2[j++];  // Copy remaining elements from arr2.
                    if (size1 + size2 <= MAX_SIZE) {  // If merged array size doesn't exceed the maximum allowed size:
                        size1 += size2;  // Update size of arr1.
                        for (int i = 0; i < size1; i++) arr1[i] = result[i];  // Copy merged array back to arr1.
                        merged = 1;  // Set merged flag to indicate that arrays have been merged.
                        printf("Arrays merged.\n");  // Print a message confirming the merge.
                    } else  // If merged array size exceeds the maximum allowed size:
                        printf("Merging not possible. Resultant array would exceed maximum size.\n");  // Print an error message.
                } else {  // If arrays have already been merged:
                    printf("Already Merged!\n");  // Print a message indicating that arrays have already been merged.
                }
                break;  // Exit the switch statement.
            }
            case 5:  // If the choice is 5:
                // Exiting the program
                return 0;  // Return 0 to indicate successful program termination.
            default:  // If the choice is not 1, 2, 3, 4, or 5:
                // Handling invalid choices
                printf("Invalid choice.\n");  // Print an error message.
                break;  // Exit the switch statement.
        }

        // Displaying the current state of the array
        printf("Array: ");  // Print a message indicating the display of the array.
        for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);  // Print the elements of arr1.
        printf("\n");  // Print a newline character.
    }

    return 0;  // Return 0 to indicate successful program termination.
}
