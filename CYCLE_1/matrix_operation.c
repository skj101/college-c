#include <stdio.h>  // Include the standard input/output library which provides functions like printf and scanf.

#define MAX_SIZE 10  // Define a constant MAX_SIZE with the value 10. This will be used to specify the maximum size of matrices.

int main() {  // Start of the main function.
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];  // Declare three 2D arrays to store matrices mat1, mat2, and the result of operations.
    int rows1, cols1, rows2, cols2, choice;  // Declare variables to store the dimensions of matrices and user's choice.

    // Getting dimensions and elements of matrix 1 from the user
    printf("Enter the number of rows for matrix 1 (max %d): ", MAX_SIZE);  // Print a message asking the user to enter the number of rows for matrix 1.
    scanf("%d", &rows1);  // Read the user's input and store it in the variable rows1.

    printf("Enter the number of columns for matrix 1 (max %d): ", MAX_SIZE);  // Print a message asking the user to enter the number of columns for matrix 1.
    scanf("%d", &cols1);  // Read the user's input and store it in the variable cols1.

    printf("Enter elements of the matrix 1:\n");  // Print a message asking the user to enter elements of matrix 1.
    for (int i = 0; i < rows1; i++)  // Start nested loops to read elements into mat1.
        for (int j = 0; j < cols1; j++)
            scanf("%d", &mat1[i][j]);  // Read an integer from the user and store it in the (i, j) position of mat1.

    // Getting dimensions and elements of matrix 2 from the user
    printf("Enter the number of rows for matrix 2 (max %d): ", MAX_SIZE);  // Print a message asking the user to enter the number of rows for matrix 2.
    scanf("%d", &rows2);  // Read the user's input and store it in the variable rows2.

    printf("Enter the number of columns for matrix 2 (max %d): ", MAX_SIZE);  // Print a message asking the user to enter the number of columns for matrix 2.
    scanf("%d", &cols2);  // Read the user's input and store it in the variable cols2.

    printf("Enter elements of the matrix 2:\n");  // Print a message asking the user to enter elements of matrix 2.
    for (int i = 0; i < rows2; i++)  // Start nested loops to read elements into mat2.
        for (int j = 0; j < cols2; j++)
            scanf("%d", &mat2[i][j]);  // Read an integer from the user and store it in the (i, j) position of mat2.

    while (1) {  // Start an infinite loop (loop will be exited manually).
        printf("\nSelect an operation:\n");  // Print a message asking the user to select an operation.
        printf("1. Matrix Addition\n 2. Matrix Multiplication\n 3. Transpose of Matrix 1\n 4. Transpose of Matrix 2\n 5. Exit\n");  // Print options for the user.
        scanf("%d", &choice);  // Read the user's choice and store it in the variable choice.

        switch (choice) {  // Start a switch statement based on the user's choice.
            case 1:  // If the choice is 1:
                if (rows1 == rows2 && cols1 == cols2) {  // If dimensions of both matrices are the same:
                    printf("Matrix Addition Result:\n");  // Print a message indicating the result of matrix addition.
                    for (int i = 0; i < rows1; i++) {  // Start nested loops to perform matrix addition.
                        for (int j = 0; j < cols1; j++) {
                            result[i][j] = mat1[i][j] + mat2[i][j];  // Perform addition and store the result in result matrix.
                            printf("%d ", result[i][j]);  // Print the result.
                        }
                        printf("\n");  // Print a newline to separate rows.
                    }
                } else {  // If dimensions are not compatible for addition:
                    printf("Matrix addition not possible. Matrices must have the same dimensions.\n");  // Print an error message.
                }
                break;  // Exit the switch statement.

            case 2:  // If the choice is 2:
                if (cols1 == rows2) {  // If dimensions are compatible for multiplication:
                    printf("Matrix Multiplication Result:\n");  // Print a message indicating the result of matrix multiplication.
                    for (int i = 0; i < rows1; i++) {  // Start nested loops to perform matrix multiplication.
                        for (int j = 0; j < cols2; j++) {
                            result[i][j] = 0;  // Initialize result element to 0.
                            for (int k = 0; k < cols1; k++) {
                                result[i][j] += mat1[i][k] *mat2[k][j];  // Perform multiplication and accumulate the result.
                            }
                            printf("%d ", result[i][j]);  // Print the result.
                        }
                        printf("\n");  // Print a newline to separate rows.
                    }
                } else {  // If dimensions are not compatible for multiplication:
                    printf("Matrix multiplication not possible. Columns of the first matrix must be equal to rows of the second matrix.\n");  // Print an error message.
                }
                break;  // Exit the switch statement.

            case 3:  // If the choice is 3:
                printf("Transpose of Matrix 1:\n");  // Print a message indicating the transposition.
                for (int i = 0; i < cols1; i++) {  // Start nested loops to perform transposition.
                    for (int j = 0; j < rows1; j++)
                        printf("%d ", mat1[j][i]);  // Print the transposed element.
                    printf("\n");  // Print a newline to separate rows.
                }
                break;  // Exit the switch statement.

            case 4:  // If the choice is 4:
                printf("Transpose of Matrix 2:\n");  // Print a message indicating the transposition.
                for (int i = 0; i < cols2; i++) {  // Start nested loops to perform transposition.
                    for (int j = 0; j < rows2; j++)
                        printf("%d ", mat2[j][i]);  // Print the transposed element.
                    printf("\n");  // Print a newline to separate rows.
                }
                break;  // Exit the switch statement.

            case 5:  // If the choice is 5:
                return 0;  // Return 0 to indicate successful program termination.

            default:  // If the choice is not 1, 2, 3, 4, or 5:
                printf("Invalid choice. Please try again.\n");  // Print an error message.
                break;  // Exit the switch statement.
        }
    }

    return 0;  // Return 0 to indicate successful program termination.
}
