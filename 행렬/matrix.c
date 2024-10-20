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
        // A의 현재 요소가 0이거나 B의 현재 요소가 0인 경우, 나눗셈을 건너뛰고 C[i]를 0으로 설정
        if (B[i] == 0 || A[i] == 0) {
            C[i] = 0; // 0으로 설정 (상황에 따라 다른 값을 설정할 수 있음)
        } else {
            C[i] = A[i] / B[i]; // 일반적인 나눗셈 수행
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
    *matrix = (int *)calloc(row * col, sizeof(int)); // 메모리 할당 및 0으로 초기화

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
            int sum = 0; // 이 요소의 합을 초기화
            for (int k = 0; k < col; k++)
            {
                // A나 B의 현재 요소가 0인 경우, 곱셈을 건너뛰고 다음 인덱스로 넘어감
                if (*(A + m * col + k) == 0 || *(B + k * col + n) == 0) {
                    sum = 0; // 현재 요소는 0으로 초기화
                    break; // 다음 n으로 넘어감
                }
                sum += *(A + m * col + k) * *(B + k * col + n); // 포인터 산술 사용
            }
            *(C + m * col + n) = sum; // 결과 저장
        }
    }
}

void printMenu() 
{
    printf("1. 덧셈 수행 시간 비교\n"); // 두 개의 행렬이 필요하며, 크기가 같음
    printf("2. 뺄셈 수행 시간 비교\n"); // 두 개의 행렬이 필요하며, 크기가 같음
    printf("3. 곱셈 수행 시간 비교\n"); // 두 개의 행렬이 필요하며, A의 열 크기가 B의 행 크기와 같아야 함
    printf("4. 나눗셈 수행 시간 비교\n"); // 두 개의 행렬이 필요하며, 크기가 같음
    printf("5. 전치 행렬 변환 시간 비교\n"); // 하나의 행렬이 필요
    printf("6. 희소 행렬 변환 시간 비교\n"); // 하나의 행렬이 필요
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

