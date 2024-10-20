#ifndef SPARSE_H
#define SPARSE_H

typedef struct Sparse 
{
    unsigned int row; // row index
    unsigned int col; // column index
    int value; // value
} sparse;

void addSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC);
int compareSparse(const void *a, const void *b);
void denseToSparse(const unsigned int row, const unsigned int col, const int *matrix, sparse **sparseMatrix);
void divSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC);
void freeSparse(sparse **sparseM);
int getValue(const unsigned int row, const unsigned int col, const sparse *sparseM);
void mulSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC);
void printSparse(const sparse *sparseM);
void subSparse(const sparse *sparseA, const sparse *sparseB, sparse **sparseC);
void transposeSparse(const sparse *sparseA, sparse **sparseB);

#endif
