#include <stdio.h>

#define MAX_SIZE 100

int readSet(int set[]) {
    int size, i;
    printf("Enter the size of the set: ");
    scanf("%d", &size);

    printf("Enter elements of the set:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &set[i]);

    return size;
}

void displaySet(int set[], int size) {
    printf("Set: { ");
    for (int i = 0; i < size; i++)
        printf("%d ", set[i]);
    printf("}\n");
}

int main() {
    int set1[MAX_SIZE], set2[MAX_SIZE], result[MAX_SIZE];
    int size1, size2, resultSize;
    int choice;

    size1 = readSet(set1);
    size2 = readSet(set2);

    do {
        printf("\nSet Operations:\n1. Union\n2. Intersection\n3. Difference (set1 - set2)\n4. Display Sets\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                resultSize = 0;
                for (int i = 0; i < size1; i++)
                    result[resultSize++] = set1[i];
                for (int i = 0; i < size2; i++)
                    if (!memchr(set1, set2[i], size1))
                        result[resultSize++] = set2[i];
                displaySet(result, resultSize);
                break;

            case 2:
                resultSize = 0;
                for (int i = 0; i < size1; i++)
                    if (memchr(set2, set1[i], size2))
                        result[resultSize++] = set1[i];
                displaySet(result, resultSize);
                break;

            case 3:
                resultSize = 0;
                for (int i = 0; i < size1; i++)
                    if (!memchr(set2, set1[i], size2))
                        result[resultSize++] = set1[i];
                displaySet(result, resultSize);
                break;

            case 4:
                printf("\nSets:\nSet 1: ");
                displaySet(set1, size1);
                printf("Set 2: ");
                displaySet(set2, size2);
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
