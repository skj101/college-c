#include <stdio.h>

int main() {
    int arr[100], size, choice;

    printf("Enter the size of the array (max 100): ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSelect a sorting algorithm:\n 1. Bubble Sort\n 2. Selection Sort\n 3. Insertion Sort\n 4. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            printf("Array sorted using Bubble Sort.\n");
            break;

        case 2:
            for (int i = 0; i < size - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < size; j++) {
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j;
                    }
                }
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
            printf("Array sorted using Selection Sort.\n");
            break;

        case 3:
            for (int i = 1; i < size; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
            printf("Array sorted using Insertion Sort.\n");
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    // Display the sorted array
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
