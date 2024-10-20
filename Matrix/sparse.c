#include <stdio.h>
#include <stdlib.h>

#include "sparse.h"

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
                    sum += sparseA[i].value * getValue(n, sparseA[i].col, sparseB);
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
