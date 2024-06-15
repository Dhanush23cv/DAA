#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void addMatrix(int A[2][2], int B[2][2], int C[2][2]) 
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int A[2][2], int B[2][2], int C[2][2]) 
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's Matrix Multiplication
void strassenMatrixMultiplication(int A[2][2], int B[2][2], int C[2][2]) 
{
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int temp1[2][2], temp2[2][2];

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A, A, temp1);
    addMatrix(B, B, temp2);
    M1[0][0] = temp1[0][0] * temp2[0][0];
    M1[0][1] = temp1[0][1] * temp2[0][1];
    M1[1][0] = temp1[1][0] * temp2[1][0];
    M1[1][1] = temp1[1][1] * temp2[1][1];

    // M2 = (A21 + A22) * B11
    addMatrix(A, A, temp1);
    M2[0][0] = temp1[1][0] * B[0][0];
    M2[0][1] = temp1[1][1] * B[0][1];
    M2[1][0] = temp1[1][0] * B[0][0];
    M2[1][1] = temp1[1][1] * B[0][1];

    // M3 = A11 * (B12 - B22)
    subtractMatrix(B, B, temp1);
    M3[0][0] = A[0][0] * temp1[0][1];
    M3[0][1] = A[0][0] * temp1[0][1];
    M3[1][0] = A[1][0] * temp1[1][1];
    M3[1][1] = A[1][1] * temp1[1][1];

    // M4 = A22 * (B21 - B11)
    subtractMatrix(B, B, temp1);
    M4[0][0] = A[1][1] * temp1[1][0];
    M4[0][1] = A[1][1] * temp1[1][0];
    M4[1][0] = A[1][1] * temp1[1][0];
    M4[1][1] = A[1][1] * temp1[1][0];

    // M5 = (A11 + A12) * B22
    addMatrix(A, A, temp1);
    M5[0][0] = temp1[0][0] * B[1][1];
    M5[0][1] = temp1[0][1] * B[1][1];
    M5[1][0] = temp1[0][0] * B[1][1];
    M5[1][1] = temp1[0][1] * B[1][1];

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A, A, temp1);
    addMatrix(B, B, temp2);
    M6[0][0] = temp1[1][0] * temp2[0][0];
    M6[0][1] = temp1[1][0] * temp2[0][1];
    M6[1][0] = temp1[1][0] * temp2[1][0];
    M6[1][1] = temp1[1][0] * temp2[1][1];

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A, A, temp1);
    addMatrix(B, B, temp2);
    M7[0][0] = temp1[0][1] * temp2[1][0];
    M7[0][1] = temp1[0][1] * temp2[1][1];
    M7[1][0] = temp1[0][1] * temp2[1][0];
    M7[1][1] = temp1[0][1] * temp2[1][1];

    // C11 = M1 + M4 - M5 + M7
    C[0][0] = M1[0][0] + M4[0][0] - M5[0][0] + M7[0][0];
    C[0][1] = M1[0][1] + M4[0][1] - M5[0][1] + M7[0][1];
    C[1][0] = M1[1][0] + M4[1][0] - M5[1][0] + M7[1][0];
    C[1][1] = M1[1][1] + M4[1][1] - M5[1][1] + M7[1][1];

    // C12 = M3 + M5
    C[0][1] = M3[0][1] + M5[0][1];
    C[1][1] = M3[1][1] + M5[1][1];

    // C21 = M2 + M4
    C[1][0] = M2[1][0] + M4[1][0];

    // C22 = M1 - M2 + M3 + M6
    C[1][1] = M1[1][1] - M2[1][1] + M3[1][1] + M6[1][1];
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    // Input the elements of the first matrix
    printf("Enter the elements of the first 2x2 matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input the elements of the second matrix
    printf("Enter the elements of the second 2x2 matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Call the Strassen's matrix multiplication function
    strassenMatrixMultiplication(A, B, C);

    // Print the result
    printf("Resulting 2x2 matrix after Strassen's multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
