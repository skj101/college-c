#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int element, int position) {
    if (*size < MAX_SIZE && position >= 1 && position <= *size + 1) {
        for (int i = *size; i >= position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = element;
        (*size)++;
        printf("Element inserted.\n");
    } else printf("Invalid position for insertion.\n");
}

void deleteElement(int arr[], int *size, int position) {
    if (position >= 1 && position <= *size) {
        for (int i = position - 1; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted.\n");
    } else printf("Invalid position for deletion.\n");
}

void sortArray(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted.\n");
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) result[k++] = arr1[i++];
        else result[k++] = arr2[j++];
    }
    while (i < size1) result[k++] = arr1[i++];
    while (j < size2) result[k++] = arr2[j++];
}

void mergeSort(int arr1[], int *size1, int arr2[], int size2) {
    int result[MAX_SIZE];
    if (*size1 + size2 <= MAX_SIZE) {
        mergeArrays(arr1, *size1, arr2, size2, result);
        *size1 += size2;
        for (int i = 0; i < *size1; i++) {
            arr1[i] = result[i];
        }
        printf("Arrays merged.\n");
    } else printf("Merging not possible. Resultant array would exceed maximum size.\n");
}

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int size1 = 0, size2 = 0,merged = 0;
    int choice, element, position;

    printf("Enter the size of the first array (max %d): ", MAX_SIZE);
    scanf("%d", &size1);

    printf("Enter elements of the first array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array (max %d): ", MAX_SIZE - size1);
    scanf("%d", &size2);

    printf("Enter elements of the second array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    while (1) {
        printf("\nSelect an option:\n 1. Insert\n 2. Delete\n 3. Sort\n 4. Merge\n 5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Insertion
                printf("Enter element and position for insertion: ");
                scanf("%d %d", &element, &position);
                insertElement(arr1, &size1, element, position);
                displayArray(arr1, size1);
                break;
            case 2:
                // Deletion
                printf("Enter position for deletion: ");
                scanf("%d", &position);
                deleteElement(arr1, &size1, position);
                displayArray(arr1, size1);
                break;
            case 3:
                // Sorting
                sortArray(arr1, size1);
                displayArray(arr1, size1);
                break;
            case 4:
                // Merge
                if (merged == 0) {
                mergeSort(arr1, &size1, arr2, size2);
                merged = 1;
                } else {
                printf("Already Merged!\n");
                }
                displayArray(arr1, size1);
                break;
            case 5:
                return 0; // Exit the program
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
