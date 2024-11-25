#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "sparse.h"

void addSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC) {
    *sparseC = (sparse *)malloc((sparseA[0].value + sparseB[0].value + 1) * sizeof(sparse));
    if (*sparseC == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseC)[0].row = sparseA[0].row;
    (*sparseC)[0].col = sparseA[0].col;

    int m = 1, n = 1, k = 1;

    while (m <= sparseA[0].value || n <= sparseB[0].value) {
        if (m > sparseA[0].value) {
            (*sparseC)[k++] = sparseB[n++];
        } else if (n > sparseB[0].value) {
            (*sparseC)[k++] = sparseA[m++];
        } else {
            int indexA = sparseA[m].row * sparseA[0].col + sparseA[m].col;
            int indexB = sparseB[n].row * sparseB[0].col + sparseB[n].col;

            if (indexA < indexB) {
                (*sparseC)[k++] = sparseA[m++];
            } else if (indexA > indexB) {
                (*sparseC)[k++] = sparseB[n++];
            } else {
                (*sparseC)[k].row = sparseA[m].row;
                (*sparseC)[k].col = sparseA[m].col;
                (*sparseC)[k].value = sparseA[m].value + sparseB[n].value;
                m++;
                n++;
                k++;
            }
        }
    }
    (*sparseC)[0].value = k - 1;
}

int compareSparse(const void *a, const void *b)
{
    sparse *A = (sparse *)a;
    sparse *B = (sparse *)b;

    if (A->row < B->row)
    {
        return -1;
    }
    if (A->row > B->row)
    {
        return 1;
    }
    if (A->col < B->col)
    {
        return -1;
    }
    if (A->col > B->col)
    {
        return 1;
    }
    return 0;
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

void divSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC) 
{
    int maxSize = sparseA[0].value > sparseB[0].value ? sparseA[0].value : sparseB[0].value;
    *sparseC = (sparse *)malloc((maxSize + 1) * sizeof(sparse));
    if (*sparseC == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseC)[0].row = sparseA[0].row;
    (*sparseC)[0].col = sparseA[0].col;
    (*sparseC)[0].value = 0;

    int m = 1, n = 1, k = 1;

    while (m <= sparseA[0].value || n <= sparseB[0].value)
    {
        int indexA = m <= sparseA[0].value ? sparseA[m].row * sparseA[0].col + sparseA[m].col : INT_MAX;
        int indexB = n <= sparseB[0].value ? sparseB[n].row * sparseB[0].col + sparseB[n].col : INT_MAX;

        if (indexA == indexB)
        {
            if (sparseB[n].value != 0)
            {
                int result = sparseA[m].value / sparseB[n].value;
                if (result != 0)
                {
                    (*sparseC)[k].row = sparseA[m].row;
                    (*sparseC)[k].col = sparseA[m].col;
                    (*sparseC)[k].value = result;
                    k++;
                }
            }
            else
            {
                (*sparseC)[k].row = sparseA[m].row;
                (*sparseC)[k].col = sparseA[m].col;
                (*sparseC)[k].value = -1;
                k++;
            }
            m++;
            n++;
        }
        else if (indexA < indexB)
        {
            (*sparseC)[k].row = sparseA[m].row;
            (*sparseC)[k].col = sparseA[m].col;
            (*sparseC)[k].value = -1;
            k++;
            m++;
        }
        else
        {
            n++;
        }
    }

    (*sparseC)[0].value = k - 1;
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

int getValue(const unsigned int row, const unsigned int col, const sparse *sparseM)
{
    for (int i = 1; i <= sparseM[0].value; i++)
    {
        if (sparseM[i].row == row && sparseM[i].col == col)
        {
            return sparseM[i].value;
        }
    }
    return 0;
}

int getValueDiv(const unsigned int row, const unsigned int col, const sparse *sparseM)
{
    int left = 1;
    int right = sparseM[0].value;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (sparseM[mid].row == row && sparseM[mid].col == col)
        {
            return sparseM[mid].value;
        }
        else if (sparseM[mid].row < row || (sparseM[mid].row == row && sparseM[mid].col < col))
        {
            left = mid + 1;  // Search right half
        }
        else
        {
            right = mid - 1;  // Search left half
        }
    }

    return 0;  // When the value is not found
}

void mulSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC) 
{
    if (sparseA[0].col != sparseB[0].row) 
    {
        printf("Matrix multiplication is not possible\n");
        return;
    }

    *sparseC = (sparse *)malloc((sparseA[0].row * sparseB[0].row + 1) * sizeof(sparse));
    if (*sparseC == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseC)[0].row = sparseA[0].row;
    (*sparseC)[0].col = sparseB[0].row;
    (*sparseC)[0].value = 0;

    for (int m = 0; m < sparseA[0].row; m++)
    {
        for (int n = 0; n < sparseB[0].row; n++)
        {
            int sum = 0;
            for (int i = 1; i <= sparseA[0].value && sparseA[i].row <= m; i++)
            {
                if (sparseA[i].row == m)
                {
                    int valueB = getValue(n, sparseA[i].col, sparseB);
                    if (valueB != 0)
                    {
                        sum += sparseA[i].value * valueB;
                    }
                }
            }
            if (sum != 0)
            {
                (*sparseC)[++((*sparseC)[0].value)] = (sparse){m, n, sum};
            }
        }
    }
}

void mulSparseDiv(const sparse *sparseA, const sparse *sparseB, sparse **sparseC) 
{
    if (sparseA[0].col != sparseB[0].row) 
    {
        printf("Matrix multiplication is not possible\n");
        return;
    }

    *sparseC = (sparse *)malloc((sparseA[0].row * sparseB[0].row + 1) * sizeof(sparse));
    if (*sparseC == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseC)[0].row = sparseA[0].row;
    (*sparseC)[0].col = sparseB[0].row;
    (*sparseC)[0].value = 0;

    for (int m = 0; m < sparseA[0].row; m++)
    {
        for (int n = 0; n < sparseB[0].row; n++)
        {
            int sum = 0;
            for (int i = 1; i <= sparseA[0].value && sparseA[i].row <= m; i++)
            {
                if (sparseA[i].row == m)
                {
                    int valueB = getValueDiv(n, sparseA[i].col, sparseB);
                    if (valueB != 0)
                    {
                        sum += sparseA[i].value * valueB;
                    }
                }
            }
            if (sum != 0)
            {
                (*sparseC)[++((*sparseC)[0].value)] = (sparse){m, n, sum};
            }
        }
    }
}

void printSparse(const sparse *sparseM) 
{
    for (int i = 0; i <= sparseM[0].value; i++)
    {
        printf("%d %d %d\n", sparseM[i].row, sparseM[i].col, sparseM[i].value);
    }
}

void printSparseAsMatrix(const sparse *sparseM)
{
    unsigned int row = sparseM[0].row;
    unsigned int col = sparseM[0].col;
    int valueIndex = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (valueIndex <= sparseM[0].value &&
                sparseM[valueIndex].row == i && sparseM[valueIndex].col == j)
            {
                printf("%d ", sparseM[valueIndex].value);
                valueIndex++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void subSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC) {
    *sparseC = (sparse *)malloc((sparseA[0].value + sparseB[0].value + 1) * sizeof(sparse));
    if (*sparseC == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*sparseC)[0].row = sparseA[0].row;
    (*sparseC)[0].col = sparseA[0].col;

    int m = 1, n = 1, k = 1;

    while (m <= sparseA[0].value || n <= sparseB[0].value) {
        if (m > sparseA[0].value) {
            (*sparseC)[k] = sparseB[n];
            (*sparseC)[k].value = -sparseB[n].value;
            k++;
            n++;
        } else if (n > sparseB[0].value) {
            (*sparseC)[k++] = sparseA[m++];
        } else {
            int indexA = sparseA[m].row * sparseA[0].col + sparseA[m].col;
            int indexB = sparseB[n].row * sparseB[0].col + sparseB[n].col;

            if (indexA < indexB) {
                (*sparseC)[k++] = sparseA[m++];
            } else if (indexA > indexB) {
                (*sparseC)[k] = sparseB[n];
                (*sparseC)[k].value = -sparseB[n].value;
                k++;
                n++;
            } else {
                (*sparseC)[k].row = sparseA[m].row;
                (*sparseC)[k].col = sparseA[m].col;
                (*sparseC)[k].value = sparseA[m].value - sparseB[n].value;
                m++;
                n++;
                k++;
            }
        }
    }

    (*sparseC)[0].value = k - 1;
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

    qsort(*sparseB + 1, sparseA[0].value, sizeof(sparse), compareSparse);
}
