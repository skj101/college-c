#include <stdio.h>

#define MAX_SIZE 100

int readSet(int set[]) {
    int size, i;
    printf("Enter the size of the set: ");
    scanf("%d", &size);

    printf("Enter elements of the set:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &set[i]);
    }

    return size;
}

void displaySet(int set[], int size) {
    int i;
    printf("Set: { ");
    for (i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

int main() {
    int set1[MAX_SIZE], set2[MAX_SIZE], result[MAX_SIZE];
    int size1, size2, resultSize;
    int choice;

    size1 = readSet(set1);
    size2 = readSet(set2);

    do {
        printf("\nSet Operations:\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference (set1 - set2)\n");
        printf("4. Display Sets\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                resultSize = 0;
                for (int i = 0; i < size1; i++) {
                    result[resultSize++] = set1[i];
                }
                for (int i = 0; i < size2; i++) {
                    int found = 0;
                    for (int j = 0; j < size1; j++) {
                        if (set2[i] == set1[j]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        result[resultSize++] = set2[i];
                    }
                }
                displaySet(result, resultSize);
                break;

            case 2:
                resultSize = 0;
                for (int i = 0; i < size1; i++) {
                    for (int j = 0; j < size2; j++) {
                        if (set1[i] == set2[j]) {
                            result[resultSize++] = set1[i];
                            break;
                        }
                    }
                }
                displaySet(result, resultSize);
                break;

            case 3:
                resultSize = 0;
                for (int i = 0; i < size1; i++) {
                    int found = 0;
                    for (int j = 0; j < size2; j++) {
                        if (set1[i] == set2[j]) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        result[resultSize++] = set1[i];
                    }
                }
                displaySet(result, resultSize);
                break;

            case 4:
                printf("\nSets:\n");
                printf("Set 1: ");
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
