#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void addMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C) 
{
    for (int i = 0; i < row * col; i++)
    {
        C[i] = A[i] + B[i];
    }
}

void divMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C) 
{
    for (int i = 0; i < row * col; i++)
    {
        if (B[i] == 0)
        {
            if (A[i] == 0)
            {
                C[i] = 0; // 0 / 0
            }
            else
            {
                C[i] = -1; // Divide by zero
            }
        }
        else
        {
            C[i] = A[i] / B[i];
        }
    }
}

void fillMatrix(const unsigned int row, const unsigned int col, int *matrix, const int percent) 
{
     for (int i = 0; i < row * col; i++)
    {
        if (rand() % 100 < percent)
        {
            matrix[i] = 0; // 0
        }
        else
        {
            matrix[i] = rand() % 9 + 1; // 1 ~ 9
        }
    }
}

void freeMatrix(int **matrix) 
{
    if (*matrix == NULL)
    {
        return;
    }
    free(*matrix);
    *matrix = NULL;
}

void getMatrixSize(unsigned int *row, unsigned int *col) 
{
    printf("\n");
    do
    {
        printf("정방행렬의 크기를 입력하세요: ");
        scanf("%d", row);
    } while (*row < 1);
    *col = *row;
}

void makeMatrix(const unsigned int row, const unsigned int col, int **matrix)
{
    *matrix = (int *)calloc(row * col, sizeof(int)); // Allocate memory, Initialize to 0

    if (*matrix == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void mulMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C) 
{
    for (int m = 0; m < row; m++)
    {
        for (int n = 0; n < col; n++)
        {
            C[m * col + n] = 0;
            for (int k = 0; k < col; k++)
            {
                C[m * col + n] += A[m * col + k] * B[k * col + n];
            }
        }
    }
}

void printMenu() 
{
    printf("1. 덧셈 수행 시간 비교\n"); // Two matrices are required, same size
    printf("2. 뺄셈 수행 시간 비교\n"); // Two matrices are required, same size
    printf("3. 곱셈 수행 시간 비교\n"); // Two matrices are required, A's column size == B's row size
    printf("4. 나눗셈 수행 시간 비교\n"); // Two matrices are required, same size
    printf("5. 전치 행렬 변환 시간 비교\n"); // One matrix is required
    printf("6. 희소 행렬 변환 시간 비교\n"); // One matrix is required
    printf("7. 종료\n");
    printf("메뉴 선택: ");
}

void printMatrix(const unsigned int row, const unsigned int col, const int *matrix) 
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i * col + j]);
        }
        printf("\n");
    }
}

void subMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C) 
{
    for (int i = 0; i < row * col; i++)
    {
        C[i] = A[i] - B[i];
    }
}

void transposeMatrix(const unsigned int row, const unsigned int col, int *matrixA, int *matrixB) 
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrixB[j * row + i] = matrixA[i * col + j];
        }
    }
}
