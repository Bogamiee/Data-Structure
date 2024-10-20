#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "matrix.h"
#include "timer.h"
#include "sparse.h"

#define IS_PRINT 1 // 1 if print matrix, 0 if not
#define IS_PRINTSPARSE 0 // 1 if print sparse matrix, 0 if not
#define IS_PRINTSPARSEMATRIX 1 // 1 if print sparse matrix as matrix, 0 if not

int percent = 50;

int main() 
{
    int menu;
    unsigned int row, col;
    int *A = NULL, *B = NULL, *C = NULL;
    sparse *sparseA = NULL, *sparseB = NULL, *sparseC = NULL;
    srand(time(NULL));

    do 
    {
        printf("행렬의 0일 확률을 입력하세요(0 ~ 100): ");
        scanf("%d", &percent);
    } while (percent < 0 || percent > 100);
    printf("\n");

    do 
    {
        printMenu();
        scanf("%d", &menu);

        switch (menu)
        {
            case 1: // addition
                getMatrixSize(&row, &col);

                makeMatrix(row, col, &A);
                makeMatrix(row, col, &B);
                makeMatrix(row, col, &C);

                fillMatrix(row, col, A, percent);
                fillMatrix(row, col, B, percent);

                startTimer();
                addMatrix(row, col, A, B, C); // add dense matrix
                endTimer();
                
                if (IS_PRINT)
                {
                    printf("\n행렬 A:\n");
                    printMatrix(row, col, A);

                    printf("\n행렬 B:\n");
                    printMatrix(row, col, B);

                    printf("\n행렬 C:\n");
                    printMatrix(row, col, C);
                }

                printf("\n일반 행렬 덧셈 시간\n");
                printExecutionTime();

                denseToSparse(row, col, A, &sparseA);
                denseToSparse(row, col, B, &sparseB);

                startTimer();
                addSparse(sparseA, sparseB, &sparseC); // add sparse matrix
                endTimer();

                if (IS_PRINTSPARSE)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparse(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparse(sparseC);
                }

                if (IS_PRINTSPARSEMATRIX)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparseAsMatrix(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparseAsMatrix(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparseAsMatrix(sparseC);
                }
    
                printf("\n희소 행렬 덧셈 시간\n");
                printExecutionTime();

                break;
            case 2: // subtract
                getMatrixSize(&row, &col);

                makeMatrix(row, col, &A);
                makeMatrix(row, col, &B);
                makeMatrix(row, col, &C);

                fillMatrix(row, col, A, percent);
                fillMatrix(row, col, B, percent);
                
                startTimer();
                subMatrix(row, col, A, B, C); // subtract dense matrix
                endTimer();

                if (IS_PRINT)
                {
                    printf("\n행렬 A:\n");
                    printMatrix(row, col, A);

                    printf("\n행렬 B:\n");
                    printMatrix(row, col, B);

                    printf("\n행렬 C:\n");
                    printMatrix(row, col, C);
                }

                printf("\n일반 행렬 뺄셈 시간\n");
                printExecutionTime();

                denseToSparse(row, col, A, &sparseA);
                denseToSparse(row, col, B, &sparseB);

                startTimer();
                subSparse(sparseA, sparseB, &sparseC); // subtract sparse matrix
                endTimer();

                if (IS_PRINTSPARSE)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparse(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparse(sparseC);
                }

                if (IS_PRINTSPARSEMATRIX)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparseAsMatrix(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparseAsMatrix(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparseAsMatrix(sparseC);
                }
 
                printf("\n희소 행렬 뺄셈 시간\n");
                printExecutionTime();

                break;
            case 3: // multiplication
                getMatrixSize(&row, &col);

                makeMatrix(row, col, &A);
                makeMatrix(row, col, &B);
                makeMatrix(row, col, &C);

                fillMatrix(row, col, A, percent);
                fillMatrix(row, col, B, percent);

                startTimer();
                mulMatrix(row, col, A, B, C);
                endTimer();

                if (IS_PRINT)
                {
                    printf("\n행렬 A:\n");
                    printMatrix(row, col, A);

                    printf("\n행렬 B:\n");
                    printMatrix(row, col, B);

                    printf("\n행렬 C:\n");
                    printMatrix(row, col, C);
                }
                
                printf("\n일반 행렬 곱셈 시간\n");
                printExecutionTime();

                denseToSparse(row, col, A, &sparseA);
                denseToSparse(row, col, B, &sparseB);

                transposeSparse(sparseB, &sparseB);

                startTimer();
                mulSparse(sparseA, sparseB, &sparseC);
                endTimer();

                if (IS_PRINTSPARSE)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparse(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparse(sparseC);
                }
                
                if (IS_PRINTSPARSEMATRIX)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparseAsMatrix(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparseAsMatrix(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparseAsMatrix(sparseC);
                }

                printf("\n희소 행렬 곱셈 시간\n");
                printExecutionTime();

                break;
            case 4: // division
                getMatrixSize(&row, &col);

                makeMatrix(row, col, &A); 
                makeMatrix(row, col, &B);
                makeMatrix(row, col, &C);

                fillMatrix(row, col, A, percent);
                fillMatrix(row, col, B, percent);
                
                startTimer();
                divMatrix(row, col, A, B, C);
                endTimer();

                if (IS_PRINT)
                {
                    printf("\n행렬 A:\n");
                    printMatrix(row, col, A);

                    printf("\n행렬 B:\n");
                    printMatrix(row, col, B);

                    printf("\n행렬 C:\n");
                    printMatrix(row, col, C);
                }

                printf("\n일반 행렬 나눗셈 시간\n");
                printExecutionTime();

                denseToSparse(row, col, A, &sparseA);
                denseToSparse(row, col, B, &sparseB);

                startTimer();
                divSparse(sparseA, sparseB, &sparseC);
                endTimer();

                if (IS_PRINTSPARSE)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparse(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparse(sparseC);
                }

                if (IS_PRINTSPARSEMATRIX)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparseAsMatrix(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparseAsMatrix(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparseAsMatrix(sparseC);
                }

                printf("\n희소 행렬 나눗셈 시간\n");
                printExecutionTime();

                break;
            case 5: // transpose
                getMatrixSize(&row, &col);

                makeMatrix(row, col, &A);
                makeMatrix(col, row, &B);

                fillMatrix(row, col, A, percent);

                startTimer();
                transposeMatrix(row, col, A, B);
                endTimer();

                if (IS_PRINT)
                {
                    printf("\n행렬 A:\n");
                    printMatrix(row, col, A);

                    printf("\n전치 행렬 A:\n");
                    printMatrix(col, row, B);
                }

                printf("\n일반 행렬 전치 행렬 변환 시간\n");
                printExecutionTime();

                denseToSparse(row, col, A, &sparseA);

                startTimer();
                transposeSparse(sparseA, &sparseB);
                endTimer();

                if (IS_PRINTSPARSE)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 전치 A:\n");
                    printSparse(sparseB);
                }

                if (IS_PRINTSPARSEMATRIX)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparseAsMatrix(sparseA);

                    printf("\n희소 행렬 전치 A:\n");
                    printSparseAsMatrix(sparseB);
                }

                printf("\n희소 행렬 전치 행렬 변환 시간\n");
                printExecutionTime();

                break;
            case 6: // sparse matrix
                getMatrixSize(&row, &col);

                makeMatrix(row, col, &A);

                fillMatrix(row, col, A, percent);

                startTimer();
                denseToSparse(row, col, A, &sparseA);
                endTimer();

                if (IS_PRINT)
                {
                    printf("\n행렬 A:\n");
                    printMatrix(row, col, A);
                }

                if (IS_PRINTSPARSE)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);
                }

                if (IS_PRINTSPARSEMATRIX)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparseAsMatrix(sparseA);
                }

                printf("\n희소 행렬 변환 시간\n");
                printExecutionTime();

                break;
            case 7:
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 입력입니다.\n");
                break;
        }
        printf("\n");
    } while (menu != 7);

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    
    freeSparse(&sparseA);
    freeSparse(&sparseB);
    freeSparse(&sparseC);

    return 0;
}
