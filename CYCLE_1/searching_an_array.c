#include <stdio.h>

int main() {
    int size, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    printf("Enter %d elements:\n", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;

    while (1) {
        printf("1. Linear Search\n2. Binary Search\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                for (int i = 0; i < size; i++) {
                    if (arr[i] == key) {
                        printf("Element found at index %d.\n", i);
                        break;
                    } else {
                        printf("Not found")
                    }
                }
                break;
            }
            case 2: {
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                int left = 0, right = size - 1;
                int found = 0;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (arr[mid] == key) {
                        printf("Element found at index %d.\n", mid);
                        found = 1;
                        break;
                    }

                    if (arr[mid] < key) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                if (!found) {
                    printf("Element not found.\n");
                }
                break;
            }

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
