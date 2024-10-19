#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define IS_SQUARE 1 // 1 if square matrix, 0 if not
#define IS_PRINT 1 // 1 if print matrix, 0 if not

int percent = 50;
clock_t start, end;
double execTime;

typedef struct Sparse 
{
    unsigned int row; // row index
    unsigned int col; // column index
    int value; // value
} sparse;

void addMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C);
void addSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC);
void denseToSparse(const unsigned int row, const unsigned int col, const int *matrix, sparse **sparseMatrix);
void divMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C);
void divSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC);
void endTimer();
void fillMatrix(const unsigned int row, const unsigned int col, int *matrix, const int percent);
void freeMatrix(int **matrix);
void freeSparse(sparse **sparseM);
void getMatrixSize(unsigned int *row, unsigned int *col);
void makeMatrix(const unsigned int row, const unsigned int col, int **matrix);
void printExecutionTime();
void printMatrix(const unsigned int row, const unsigned int col, const int *matrix);
void printMenu();
void printSparse(const sparse *sparseM);
void startTimer();
void subMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C);
void subSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC);
void transposeMatrix(const unsigned int row, const unsigned int col, int *matrixA, int *matrixB);
void transposeSparse(const sparse *sparseA, sparse **sparseB);

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

                if (IS_PRINT)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparse(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparse(sparseC);
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

                if (IS_PRINT)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparse(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparse(sparseC);
                }

                printf("\n희소 행렬 뺄셈 시간\n");
                printExecutionTime();

                break;
            case 3: // multiplication
                printf("행렬 A:\n");
                getMatrixSize(&row, &col);
                makeMatrix(row, col, &A);
                printf("행렬 B:\n");
                getMatrixSize(&row, &col);
                makeMatrix(row, col, &B);
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

                if (IS_PRINT)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 B:\n");
                    printSparse(sparseB);

                    printf("\n희소 행렬 C:\n");
                    printSparse(sparseC);
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

                    printf("\n전치 행렬 B:\n");
                    printMatrix(col, row, B);
                }

                printf("\n일반 행렬 전치 행렬 변환 시간\n");
                printExecutionTime();

                denseToSparse(row, col, A, &sparseA);

                startTimer();
                transposeSparse(sparseA, &sparseB);
                endTimer();

                if (IS_PRINT)
                {
                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);

                    printf("\n희소 행렬 전치 행렬 B:\n");
                    printSparse(sparseB);
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

                    printf("\n희소 행렬 A:\n");
                    printSparse(sparseA);
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

void addMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C) 
{
    for (int i = 0; i < row * col; i++)
    {
        C[i] = A[i] + B[i];
    }
}

void addSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC) 
{
    *sparseC = (sparse *)malloc((sparseA[0].value + sparseB[0].value + 1) * sizeof(sparse));
    if (*sparseC == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseC)[0].row = sparseA[0].row;
    (*sparseC)[0].col = sparseA[0].col;

    int m = 1, n = 1, k = 1;

    while (m <= sparseA[0].value && n <= sparseB[0].value)
    {
        int indexA = sparseA[m].row * sparseA[0].col + sparseA[m].col;
        int indexB = sparseB[n].row * sparseB[0].col + sparseB[n].col;

        if (indexA < indexB)
        {
            (*sparseC)[k].row = sparseA[m].row;
            (*sparseC)[k].col = sparseA[m].col;
            (*sparseC)[k].value = sparseA[m].value;
            m++;
            k++;
        }
        else if (indexA > indexB)
        {
            (*sparseC)[k].row = sparseB[n].row;
            (*sparseC)[k].col = sparseB[n].col;
            (*sparseC)[k].value = sparseB[n].value;
            n++;
            k++;
        }
        else
        {
            (*sparseC)[k].row = sparseA[m].row;
            (*sparseC)[k].col = sparseA[m].col;
            (*sparseC)[k].value = sparseA[m].value + sparseB[n].value;
            m++;
            n++;
            k++;
        }
    }

    while (m <= sparseA[0].value)
    {
        (*sparseC)[k].row = sparseA[m].row;
        (*sparseC)[k].col = sparseA[m].col;
        (*sparseC)[k].value = sparseA[m].value;
        m++;
        k++;
    }
    while (n <= sparseB[0].value)
    {
        (*sparseC)[k].row = sparseB[n].row;
        (*sparseC)[k].col = sparseB[n].col;
        (*sparseC)[k].value = sparseB[n].value;
        n++;
        k++;
    }

    (*sparseC)[0].value = k - 1;
}

void denseToSparse(const unsigned int row, const unsigned int col, const int *matrix, sparse **sparseMatrix) 
{
    int count = 0;

    for (int i = 0; i < row * col; i++)
    {
        if (matrix[i] != 0)
        {
            count++;
        }
    }

    *sparseMatrix = (sparse *)calloc(count + 1, sizeof(sparse));

    if (*sparseMatrix == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseMatrix)[0].row = row;
    (*sparseMatrix)[0].col = col;
    (*sparseMatrix)[0].value = count;

    count = 1;

    for (int i = 0; i < row * col; i++)
    {
        if (matrix[i] != 0)
        {
            (*sparseMatrix)[count].row = i / col;
            (*sparseMatrix)[count].col = i % col;
            (*sparseMatrix)[count].value = matrix[i];
            count++;
        }
    }
}

void divMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C) 
{
    for (int i = 0; i < row * col; i++)
    {
        if (B[i] == 0)
        {
            C[i] = -1; // Divide by zero
        }
        else
        {
            C[i] = A[i] / B[i];
        }
    }
}

void divSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC) 
{
    *sparseC = (sparse *)malloc((sparseA[0].value + sparseB[0].value + 1) * sizeof(sparse));
    if (*sparseC == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseC)[0].row = sparseA[0].row;
    (*sparseC)[0].col = sparseA[0].col;

    int m = 1, n = 1, k = 1;

    while (m <= sparseA[0].value && n <= sparseB[0].value)
    {
        int indexA = sparseA[m].row * sparseA[0].col + sparseA[m].col;
        int indexB = sparseB[n].row * sparseB[0].col + sparseB[n].col;

        if (indexA < indexB)
        {
            (*sparseC)[k].row = sparseA[m].row;
            (*sparseC)[k].col = sparseA[m].col;
            (*sparseC)[k].value = sparseA[m].value; 
            m++;
            k++;
        }
        else if (indexA > indexB)
        {
            (*sparseC)[k].row = sparseB[n].row;
            (*sparseC)[k].col = sparseB[n].col;
            (*sparseC)[k].value = 0;
            n++;
            k++;
        }
        else
        {
            if (sparseB[n].value != 0) 
            {
                (*sparseC)[k].row = sparseA[m].row;
                (*sparseC)[k].col = sparseA[m].col;
                (*sparseC)[k].value = sparseA[m].value / sparseB[n].value;
            }
            else
            {
                (*sparseC)[k].value = -1; // Divide by zero
            }
            m++;
            n++;
            k++;
        }
    }

    while (m <= sparseA[0].value)
    {
        (*sparseC)[k].row = sparseA[m].row;
        (*sparseC)[k].col = sparseA[m].col;
        (*sparseC)[k].value = sparseA[m].value;
        m++;
        k++;
    }
    while (n <= sparseB[0].value)
    {
        (*sparseC)[k].row = sparseB[n].row;
        (*sparseC)[k].col = sparseB[n].col;
        (*sparseC)[k].value = 0;
        n++;
        k++;
    }

    (*sparseC)[0].value = k - 1;
}

void endTimer()
{
    end = clock();
    execTime = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
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

void freeSparse(sparse **sparseM) 
{
    if (*sparseM == NULL)
    {
        return;
    }
    free(*sparseM);
    *sparseM = NULL;
}

void getMatrixSize(unsigned int *row, unsigned int *col) 
{
    printf("\n");
    if (IS_SQUARE)
    {
        do
        {
            printf("정방행렬의 크기를 입력하세요: ");
            scanf("%d", row);
        } while (*row < 1);
        *col = *row;
    }
    else
    {
        do
        {
            printf("행렬의 행 크기를 입력하세요: ");
            scanf("%d", row);
        } while (*row < 1);
        do
        {
            printf("행렬의 열 크기를 입력하세요: ");
            scanf("%d", col);
        } while (*col < 1);
    }
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

void printExecutionTime()
{
    double microseconds = execTime;
    double milliseconds = microseconds / 1000.0;
    double seconds = milliseconds / 1000.0;
    double minutes = seconds / 60.0;
    double hours = minutes / 60.0;

    printf("- %.0lf microseconds\n", microseconds);
    printf("- %.3lf milliseconds\n", milliseconds);
    printf("- %.3lf seconds\n", seconds);
    printf("- %d minutes %.3lf seconds\n", (int)minutes, fmod(seconds, 60.0));
    printf("- %d hours %d minutes %.3lf seconds\n", (int)hours, (int)fmod(minutes, 60.0), fmod(seconds, 60.0));
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

void printSparse(const sparse *sparseM) 
{
    for (int i = 0; i <= sparseM[0].value; i++)
    {
        printf("%d %d %d\n", sparseM[i].row, sparseM[i].col, sparseM[i].value);
    }
}

void startTimer()
{
    start = clock();
}

void subMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C) 
{
    for (int i = 0; i < row * col; i++)
    {
        C[i] = A[i] - B[i];
    }
}

void subSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC) 
{
    *sparseC = (sparse *)malloc((sparseA[0].value + sparseB[0].value + 1) * sizeof(sparse));
    if (*sparseC == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseC)[0].row = sparseA[0].row;
    (*sparseC)[0].col = sparseA[0].col;

    int m = 1, n = 1, k = 1;

    while (m <= sparseA[0].value && n <= sparseB[0].value)
    {
        int indexA = sparseA[m].row * sparseA[0].col + sparseA[m].col;
        int indexB = sparseB[n].row * sparseB[0].col + sparseB[n].col;

        if (indexA < indexB)
        {
            (*sparseC)[k].row = sparseA[m].row;
            (*sparseC)[k].col = sparseA[m].col;
            (*sparseC)[k].value = sparseA[m].value;
            m++;
            k++;
        }
        else if (indexA > indexB)
        {
            (*sparseC)[k].row = sparseB[n].row;
            (*sparseC)[k].col = sparseB[n].col;
            (*sparseC)[k].value = -sparseB[n].value;
            n++;
            k++;
        }
        else
        {
            (*sparseC)[k].row = sparseA[m].row;
            (*sparseC)[k].col = sparseA[m].col;
            (*sparseC)[k].value = sparseA[m].value - sparseB[n].value;
            m++;
            n++;
            k++;
        }
    }

    while (m <= sparseA[0].value)
    {
        (*sparseC)[k].row = sparseA[m].row;
        (*sparseC)[k].col = sparseA[m].col;
        (*sparseC)[k].value = sparseA[m].value;
        m++;
        k++;
    }
    while (n <= sparseB[0].value)
    {
        (*sparseC)[k].row = sparseB[n].row;
        (*sparseC)[k].col = sparseB[n].col;
        (*sparseC)[k].value = -sparseB[n].value;
        n++;
        k++;
    }
    
    (*sparseC)[0].value = k - 1;
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

void transposeSparse(const sparse *sparseA, sparse **sparseB) 
{
    *sparseB = (sparse *)malloc((sparseA[0].value + 1) * sizeof(sparse));
    if (*sparseB == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseB)[0].row = sparseA[0].col;
    (*sparseB)[0].col = sparseA[0].row;
    (*sparseB)[0].value = sparseA[0].value;

    for (int i = 0; i <= sparseA[0].value; i++)
    {
        (*sparseB)[i].row = sparseA[i].col;
        (*sparseB)[i].col = sparseA[i].row;
        (*sparseB)[i].value = sparseA[i].value;
    }
}
