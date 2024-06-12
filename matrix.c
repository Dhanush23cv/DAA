#include <stdio.h>
#include <time.h>

void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int result[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond) 
{
    for (int i = 0; i < rowFirst; ++i) 
    {
        for (int j = 0; j < columnSecond; ++j) 
        {
            result[i][j] = 0;
            for (int k = 0; k < columnFirst; ++k) 
            {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][10], int row, int column) 
{
    for (int i = 0; i < row; ++i) 
    {
        for (int j = 0; j < column; ++j) 
        {
            printf("%d  ", matrix[i][j]);
            if (j == column - 1)
                printf("\n");
        }
    }
}

int main() {
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];
    int rowFirst, columnFirst, rowSecond, columnSecond;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &columnFirst);

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &columnSecond);

    // Check if multiplication is possible
    if (columnFirst != rowSecond) 
    {
        printf("Error! column of first matrix is not equal to row of second.\n");
        return -1;
    }

    // Storing elements of first matrix
    printf("\nEnter elements of matrix 1:\n");
    for (int i = 0; i < rowFirst; ++i) 
    {
        for (int j = 0; j < columnFirst; ++j) 
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Storing elements of second matrix
    printf("\nEnter elements of matrix 2:\n");
    for (int i = 0; i < rowSecond; ++i) 
    {
        for (int j = 0; j < columnSecond; ++j) 
        {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Measuring the time taken for matrix multiplication
    clock_t start = clock();
    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);
    clock_t end = clock();

    // Calculating the total time taken by the program.
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Displaying the result
    printf("\nResultant matrix:\n");
    printMatrix(result, rowFirst, columnSecond);

    printf("\nMatrix multiplication took %f seconds to execute \n", time_taken);

    return 0;
}
