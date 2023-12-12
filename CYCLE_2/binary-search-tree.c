#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int size = 0;

int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations:\n1. Insert\n2. Delete\n3. Search\n4. In-order Traversal\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (size == MAX_SIZE || bsearch(&value, tree, size, sizeof(int), compareInt)) {
                    printf("Duplicate value or tree is full. Not inserted.\n");
                } else {
                    tree[size++] = value;
                    printf("%d inserted into the tree.\n", value);
                }
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                {
                    int* found = bsearch(&value, tree, size, sizeof(int), compareInt);
                    if (found) {
                        *found = tree[size-- - 1];
                        printf("%d deleted from the tree.\n", value);
                    } else {
                        printf("%d not found in the tree.\n", value);
                    }
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                {
                    int* found = bsearch(&value, tree, size, sizeof(int), compareInt);
                    if (found) {
                        printf("%d found in the tree.\n", value);
                    } else {
                        printf("%d not found in the tree.\n", value);
                    }
                }
                break;

            case 4:
                printf("In-order Traversal: ");
                qsort(tree, size, sizeof(int), compareInt);
                for (int i = 0; i < size; i++) {
                    printf("%d ", tree[i]);
                }
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
