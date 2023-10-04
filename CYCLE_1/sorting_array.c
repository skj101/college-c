#include <stdio.h>  // Include the standard input/output library which provides functions like printf and scanf.

int main() {  // Start of the main function.
    int arr[100], size, choice;  // Declare an array 'arr' with a maximum size of 100, and variables 'size' and 'choice'.

    printf("Enter the size of the array (max 100): ");  // Print a message asking the user to enter the size of the array.
    scanf("%d", &size);  // Read the user's input and store it in the variable 'size'.

    printf("Enter the elements of the array:\n");  // Print a message asking the user to enter the elements of the array.
    for (int i = 0; i < size; i++) {  // Start a loop to read elements into the array.
        scanf("%d", &arr[i]);  // Read an integer from the user and store it in the ith position of 'arr'.
    }

    printf("\nSelect a sorting algorithm:\n 1. Bubble Sort\n 2. Selection Sort\n 3. Insertion Sort\n 4. Exit\n");  // Print a menu for the user to select a sorting algorithm.
    scanf("%d", &choice);  // Read the user's choice and store it in the variable 'choice'.

    switch (choice) {  // Start a switch statement based on the user's choice.
        case 1:  // If the choice is 1:
            // Bubble Sort algorithm
            for (int i = 0; i < size - 1; i++) {  // Start nested loops for a bubble sort algorithm.
                for (int j = 0; j < size - i - 1; j++) {  // Inner loop for comparisons and swaps.
                    if (arr[j] > arr[j + 1]) {  // If elements are out of order:
                        int temp = arr[j];  // Swap them.
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            printf("Array sorted using Bubble Sort.\n");  // Print a message confirming the sorting algorithm used.
            break;  // Exit the switch statement.

        case 2:  // If the choice is 2:
            // Selection Sort algorithm
            for (int i = 0; i < size - 1; i++) {  // Start loops for a selection sort algorithm.
                int minIndex = i;  // Assume the current index has the minimum value.
                for (int j = i + 1; j < size; j++) {  // Inner loop to find the smallest element's index.
                    if (arr[j] < arr[minIndex]) {  // If a smaller element is found:
                        minIndex = j;  // Update the index of the smallest element.
                    }
                }
                int temp = arr[i];  // Swap the smallest element with the current element.
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
            printf("Array sorted using Selection Sort.\n");  // Print a message confirming the sorting algorithm used.
            break;  // Exit the switch statement.

        case 3:  // If the choice is 3:
            // Insertion Sort algorithm
            for (int i = 1; i < size; i++) {  // Start a loop to insert elements in their correct positions.
                int key = arr[i];  // Select the key element for insertion.
                int j = i - 1;
                while (j >= 0 && arr[j] > key) {  // Compare with elements on the left and shift them if necessary.
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;  // Insert the key element at the correct position.
            }
            printf("Array sorted using Insertion Sort.\n");  // Print a message confirming the sorting algorithm used.
            break;  // Exit the switch statement.

        case 4:  // If the choice is 4:
            return 0;  // Return 0 to indicate successful program termination.

        default:  // If the choice is not 1, 2, 3, or 4:
            printf("Invalid choice. Please try again.\n");  // Print an error message.
            break;  // Exit the switch statement.
    }

    // Display the sorted array
    printf("Array: ");  // Print a message indicating the display of the array.
    for (int i = 0; i < size; i++) {  // Start a loop to print the elements of the array.
        printf("%d ", arr[i]);  // Print the ith element of the array.
    }
    printf("\n");  // Print a newline character.

    return 0;  // Return 0 to indicate successful program termination.
}
