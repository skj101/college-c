#include <stdio.h>

#define MAX_SIZE 10

void getMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
  printf("Enter elements of the matrix:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      scanf("%d", &mat[i][j]);
    }
  }
}

void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
  printf("Matrix:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%d ", mat[i][j]);
    }

    printf("\n");
  }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2)
{
  if (cols1 != rows2)
  {
    printf("Matrix multiplication not possible. Columns of the first matrix must be equal to rows of the second matrix.\n");
    return;
  }

  for (int i = 0; i < rows1; i++)
  {
    for (int j = 0; j < cols2; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < cols1; k++)
      {
        result[i][j] += mat1[i][k] *mat2[k][j];
      }
    }
  }
}

void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[j][i] = mat[i][j];
    }
  }
}

int main()
{
  int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
  int rows1, cols1, rows2, cols2, choice;

 	// Input for matrix 1
  printf("Enter the number of rows for matrix 1 (max %d): ", MAX_SIZE);
  scanf("%d", &rows1);

  printf("Enter the number of columns for matrix 1 (max %d): ", MAX_SIZE);
  scanf("%d", &cols1);

  getMatrix(mat1, rows1, cols1);

 	// Input for matrix 2
  printf("Enter the number of rows for matrix 2 (max %d): ", MAX_SIZE);
  scanf("%d", &rows2);

  printf("Enter the number of columns for matrix 2 (max %d): ", MAX_SIZE);
  scanf("%d", &cols2);

  getMatrix(mat2, rows2, cols2);
  
  while (1)
  {
    printf("\nSelect an operation:\n");
    printf("1. Matrix Addition\n 2. Matrix Multiplication\n 3. Transpose of Matrix 1\n 4. Transpose of Matrix 2\n 5. Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
       	// Matrix Addition
        if (rows1 == rows2 && cols1 == cols2)
        {
          addMatrices(mat1, mat2, result, rows1, cols1);
          displayMatrix(result, rows1, cols1);
        }
        else
        {
          printf("Matrix addition not possible. Matrices must have the same dimensions.\n");
        }

        break;

      case 2:
       	// Matrix Multiplication
        if (cols1 == rows2)
        {
          multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);
          displayMatrix(result, rows1, cols2);
        }
        else
        {
          printf("Matrix multiplication not possible. Columns of the first matrix must be equal to rows of the second matrix.\n");
        }

        break;

      case 3:
       	// Transpose of Matrix 1
        transposeMatrix(mat1, result, rows1, cols1);
        displayMatrix(result, cols1, rows1);
        break;

      case 4:
       	// Transpose of Matrix 2
        transposeMatrix(mat2, result, rows2, cols2);
        displayMatrix(result, cols2, rows2);
        break;

      case 5:
        return 0;	// Exit the program

      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}
