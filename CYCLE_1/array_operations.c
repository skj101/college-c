#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE], size1, size2;

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
        int choice;
        printf("\nSelect an option:\n1. Insert\n2. Delete\n3. Sort\n4. Merge\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int element, position;
                printf("Enter element and position for insertion: ");
                scanf("%d %d", &element, &position);
                if (size1 < MAX_SIZE && position >= 1 && position <= size1 + 1) {
                    for (int i = size1; i >= --position; i--)
                        arr1[i] = arr1[i - 1];
                    arr1[position] = element;
                    size1++;
                    printf("Element inserted.\n");
                } else
                    printf("Invalid position for insertion.\n");
                break;
            }
            case 2: {
                int position;
                printf("Enter position for deletion: ");
                scanf("%d", &position);
                if (position >= 1 && position <= size1) {
                    for (int i = --position; i < size1 - 1; i++)
                        arr1[i] = arr1[i + 1];
                    size1--;
                    printf("Element deleted.\n");
                } else
                    printf("Invalid position for deletion.\n");
                break;
            }
            case 3: {
                qsort(arr1, size1, sizeof(int), compare);
                printf("Array sorted.\n");
                break;
            }
            case 4: {
                if (size1 + size2 <= MAX_SIZE) {
                    for (int i = 0; i < size2; i++)
                        arr1[size1++] = arr2[i];
                    printf("Arrays merged.\n");
                } else
                    printf("Merging not possible. Resultant array would exceed maximum size.\n");
                break;
            }
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Array: ");
        for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
        printf("\n");
    }

    return 0;
}
