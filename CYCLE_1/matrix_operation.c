#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2, choice;

    printf("Enter the number of rows for matrix 1 (max %d): ", MAX_SIZE);
    scanf("%d", &rows1);

    printf("Enter the number of columns for matrix 1 (max %d): ", MAX_SIZE);
    scanf("%d", &cols1);

    printf("Enter elements of the matrix 1:\n");
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++)
            scanf("%d", &mat1[i][j]);

    printf("Enter the number of rows for matrix 2 (max %d): ", MAX_SIZE);
    scanf("%d", &rows2);

    printf("Enter the number of columns for matrix 2 (max %d): ", MAX_SIZE);
    scanf("%d", &cols2);

    printf("Enter elements of the matrix 2:\n");
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++)
            scanf("%d", &mat2[i][j]);

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Matrix Addition\n2. Matrix Multiplication\n3. Transpose of Matrix 1\n4. Transpose of Matrix 2\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rows1 == rows2 && cols1 == cols2) {
                    printf("Matrix Addition Result:\n");
                    for (int i = 0; i < rows1; i++) {
                        for (int j = 0; j < cols1; j++) {
                            result[i][j] = mat1[i][j] + mat2[i][j];
                            printf("%d ", result[i][j]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("Matrix addition not possible. Matrices must have the same dimensions.\n");
                }
                break;

            case 2:
                if (cols1 == rows2) {
                    printf("Matrix Multiplication Result:\n");
                    for (int i = 0; i < rows1; i++) {
                        for (int j = 0; j < cols2; j++) {
                            result[i][j] = 0;
                            for (int k = 0; k < cols1; k++) {
                                result[i][j] += mat1[i][k] * mat2[k][j];
                            }
                            printf("%d ", result[i][j]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("Matrix multiplication not possible. Columns of the first matrix must be equal to rows of the second matrix.\n");
                }
                break;

            case 3:
                printf("Transpose of Matrix 1:\n");
                for (int i = 0; i < cols1; i++) {
                    for (int j = 0; j < rows1; j++)
                        printf("%d ", mat1[j][i]);
                    printf("\n");
                }
                break;

            case 4:
                printf("Transpose of Matrix 2:\n");
                for (int i = 0; i < cols2; i++) {
                    for (int j = 0; j < rows2; j++)
                        printf("%d ", mat2[j][i]);
                    printf("\n");
                }
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
