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
    unsigned int nonZeroCount; // Number of non-zero elements

public:
    Matrix(); // Default constructor
    Matrix(unsigned int rows,unsigned int cols); // Matrix constructor
    Matrix(const Matrix& m); // Copy constructor
    Matrix& operator=(const Matrix& m); // Assignment operator

    unsigned int getRows() const; // Get the number of rows
    unsigned int getCols() const; // Get the number of columns
    int getValue(unsigned int index) const; // Get the value at the given index

    void fillMatrix(int percent); // Fill the matrix with random numbers
    void printMatrix() const; // Print the matrix
    void calcNonZeroCount(); // Calculate the number of non-zero elements
    unsigned int getNonZero() const; // Get the number of non-zero elements
    void denseToSparse(); // Convert dense matrix to sparse matrix
    void printSparseMatrix() const; // Print the sparse matrix
    void setValue(unsigned int index, int value); // Set the value at the given index
    ~Matrix(); // Destructor
};

#endif
