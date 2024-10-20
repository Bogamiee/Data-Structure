#ifndef MATRIX_H
#define MATRIX_H

void addMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C);
void divMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C);
void fillMatrix(const unsigned int row, const unsigned int col, int *matrix, const int percent);
void freeMatrix(int **matrix);
void getMatrixSize(unsigned int *row, unsigned int *col);
void makeMatrix(const unsigned int row, const unsigned int col, int **matrix);
void mulMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C);
void printMatrix(const unsigned int row, const unsigned int col, const int *matrix);
void printMenu();
void subMatrix(const unsigned int row, const unsigned int col, int *A, int *B, int *C);
void transposeMatrix(const unsigned int row, const unsigned int col, int *matrixA, int *matrixB);

#endif
