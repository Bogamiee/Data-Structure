#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

struct SparseMatrix {
    int row; // Row index
    int col; // Column index
    int value; // Value
};

class Matrix {
private:
    unsigned int rows; // Number of rows
    unsigned int cols; // Number of columns
    int* A; // Dynamic array for the matrix
    SparseMatrix* S; // Sparse matrix
    int nonZeroCount; // Number of non-zero elements

public:
    Matrix(int nums); // Square matrix constructor
    Matrix(int rows, int cols); // Non-square matrix constructor
    Matrix(const Matrix& m) = delete; // Deleted copy constructor
    Matrix& operator=(const Matrix& m) = delete; // Deleted copy assignment operator

    void fillMatrix(int percent); // Fill the matrix with random numbers
    void printMatrix() const; // Print the matrix
    int getNonZeroCount() const; // Get the number of non-zero elements
    void denseToSparse(); // Convert dense matrix to sparse matrix
    void printSparseMatrix() const; // Print the sparse matrix
    void transpose() const; // Transpose the matrix and print it
    ~Matrix(); // Destructor
};

#endif







