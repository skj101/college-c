#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void getString(char str[MAX_LENGTH]) {
    printf("Enter a string (max %d characters): ", MAX_LENGTH);
    scanf(" %[^\n]s", str);
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH], subStr[MAX_LENGTH];
    int choice, start, length;

    getString(str1);
    getString(str2);

    while (1) {
        printf("\nSelect an operation:\n 1. Search for substring\n 2. Concatenate strings\n 3. Get substring\n  4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Search for substring
                printf("Enter the substring to search for: ");
                scanf(" %[^\n]s", subStr);
                if (strstr(str1, subStr)) {
                    printf("'%s' is a substring of '%s'.\n", subStr, str1);
                } else {
                    printf("'%s' is not a substring of '%s'.\n", subStr, str1);
                }
                break;

            case 2: // Concatenate strings
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 3: // Get substring
                printf("Enter the start position: ");
                scanf("%d", &start);
                printf("Enter the length: ");
                scanf("%d", &length);
                if (start >= 0 && start < strlen(str1) && length > 0 && (start + length) <= strlen(str1)) {
                    char subStr[MAX_LENGTH];
                    strncpy(subStr, str1 + start, length);
                    subStr[length] = '\0';
                    printf("Substring: %s\n", subStr);
                } else {
                    printf("Invalid start position or length for substring operation.\n");
                }
                break;

            case 4:
                return 0; // Exit the program

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
