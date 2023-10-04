#include <stdio.h>  // Include the standard input/output library which provides functions like printf and scanf.
#include <string.h>  // Include the string manipulation library which provides functions like strcat, strncpy, etc.

#define MAX_LENGTH 100  // Define a constant MAX_LENGTH with the value 100. This will be used to specify the maximum length of strings.

void getString(char str[MAX_LENGTH]) {  // Define a function getString that takes a character array as an argument.
    printf("Enter a string (max %d characters): ", MAX_LENGTH);  // Print a message asking the user to enter a string.
    scanf(" %[^\n]s", str);  // Read the user's input and store it in the variable str. %[^\n]s allows the input to include spaces.
}

int main() {  // Start of the main function.
    char str1[MAX_LENGTH], str2[MAX_LENGTH], subStr[MAX_LENGTH];  // Declare three character arrays str1, str2, and subStr with a maximum length of MAX_LENGTH.
    int choice, start, length;  // Declare variables choice, start, and length.

    getString(str1);  // Call the function getString to get a string and store it in str1.
    getString(str2);  // Call the function getString again to get another string and store it in str2.

    while (1) {  // Start an infinite loop (loop will be exited manually).
        printf("\nSelect an operation:\n 1. Search for substring\n 2. Concatenate strings\n 3. Get substring\n 4. Exit\n");  // Print a menu for the user to choose an operation.
        scanf("%d", &choice);  // Read the user's choice and store it in the variable choice.

        switch (choice) {  // Start a switch statement based on the user's choice.
            case 1:  // If the choice is 1:
                // Search for substring
                printf("Enter the substring to search for: ");  // Print a message asking the user for a substring.
                scanf(" %[^\n]s", subStr);  // Read the substring from the user and store it in subStr.
                if (strstr(str1, subStr)) {  // If subStr is found in str1:
                    printf("'%s' is a substring of '%s'.\n", subStr, str1);  // Print a message confirming the substring was found.
                } else {  // If subStr is not found in str1:
                    printf("'%s' is not a substring of '%s'.\n", subStr, str1);  // Print a message indicating the substring was not found.
                }
                break;  // Exit the switch statement.

            case 2:  // If the choice is 2:
                // Concatenate strings
                strcat(str1, str2);  // Concatenate str1 and str2 and store the result in str1.
                printf("Concatenated string: %s\n", str1);  // Print the concatenated string.
                break;  // Exit the switch statement.

            case 3:  // If the choice is 3:
                // Get substring
                printf("Enter the start position: ");  // Print a message asking the user for the starting position of the substring.
                scanf("%d", &start);  // Read the starting position from the user and store it in the variable start.
                printf("Enter the length: ");  // Print a message asking the user for the length of the substring.
                scanf("%d", &length);  // Read the length from the user and store it in the variable length.
                if (start >= 0 && start < strlen(str1) && length > 0 && (start + length) <= strlen(str1)) {  // If conditions for substring extraction are met:
                    char subStr[MAX_LENGTH];  // Declare a character array subStr to store the substring.
                    strncpy(subStr, str1 + start, length);  // Copy the substring from str1 to subStr.
                    subStr[length] = '\0';  // Add a null terminator to the end of subStr to terminate the string.
                    printf("Substring: %s\n", subStr);  // Print the extracted substring.
                } else {  // If conditions for substring extraction are not met:
                    printf("Invalid start position or length for substring operation.\n");  // Print an error message.
                }
                break;  // Exit the switch statement.

            case 4:  // If the choice is 4:
                return 0;  // Return 0 to indicate successful program termination.

            default:  // If the choice is not 1, 2, 3, or 4:
                printf("Invalid choice. Please try again.\n");  // Print an error message.
                break;  // Exit the switch statement.
        }
    }

    return 0;  // Return 0 to indicate successful program termination.
}
