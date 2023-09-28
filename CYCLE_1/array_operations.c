#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE], size1, size2;
    int choice, element, position, merged = 0;

    // Getting sizes and elements of the arrays from the user
    printf("Enter the size of the first array (max %d): ", MAX_SIZE);
    scanf("%d", &size1);

    printf("Enter elements of the first array: ");
    for (int i = 0; i < size1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter the size of the second array (max %d): ", MAX_SIZE - size1);
    scanf("%d", &size2);

    printf("Enter elements of the second array: ");
    for (int i = 0; i < size2; i++)
        scanf("%d", &arr2[i]);

    while (1) {
        // Displaying menu and taking user's choice
        printf("\nSelect an option:\n 1. Insert\n 2. Delete\n 3. Sort\n 4. Merge\n 5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Insertion logic
                printf("Enter element and position for insertion: ");
                scanf("%d %d", &element, &position);
                if (size1 < MAX_SIZE && position >= 1 && position <= size1 + 1) {
                    for (int i = size1; i >= position; i--)
                        arr1[i] = arr1[i - 1];
                    arr1[position - 1] = element;
                    size1++;
                    printf("Element inserted.\n");
                } else
                    printf("Invalid position for insertion.\n");
                break;
            }
            case 2: {
                // Deletion logic
                printf("Enter position for deletion: ");
                scanf("%d", &position);
                if (position >= 1 && position <= size1) {
                    for (int i = position - 1; i < size1 - 1; i++)
                        arr1[i] = arr1[i + 1];
                    size1--;
                    printf("Element deleted.\n");
                } else
                    printf("Invalid position for deletion.\n");
                break;
            }
            case 3: {
                // Sorting logic
                for (int i = 0; i < size1 - 1; i++) {
                    for (int j = 0; j < size1 - i - 1; j++) {
                        if (arr1[j] > arr1[j + 1]) {
                            int temp = arr1[j];
                            arr1[j] = arr1[j + 1];
                            arr1[j + 1] = temp;
                        }
                    }
                }
                printf("Array sorted.\n");
                break;
            }
            case 4: {
                // Merging logic
                if (merged == 0) {
                    int result[MAX_SIZE];
                    int i = 0, j = 0, k = 0;
                    while (i < size1 && j < size2) {
                        result[k++] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];
                    }
                    while (i < size1) result[k++] = arr1[i++];
                    while (j < size2) result[k++] = arr2[j++];
                    if (size1 + size2 <= MAX_SIZE) {
                        size1 += size2;
                        for (int i = 0; i < size1; i++) arr1[i] = result[i];
                        merged = 1;
                        printf("Arrays merged.\n");
                    } else
                        printf("Merging not possible. Resultant array would exceed maximum size.\n");
                } else {
                    printf("Already Merged!\n");
                }
                break;
            }
            case 5:
                // Exiting the program
                return 0;
            default:
                // Handling invalid choices
                printf("Invalid choice.\n");
                break;
        }

        // Displaying the current state of the array
        printf("Array: ");
        for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
        printf("\n");
    }

    return 0;
}
