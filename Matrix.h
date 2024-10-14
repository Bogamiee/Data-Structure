#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

struct SparseMatrix {
    int row; 
    int col; 
    int value; 
};

class Matrix {
    private:
        unsigned int rows; // Number of rows
        unsigned int cols; // Number of columns
        int* A; // Matrix using a dynamic array
        SparseMatrix* S; // Sparse matrix using a dynamic array
        int nonZeroCount; // Number of non-zero elements
        
    public:
        Matrix(int nums); // Square Matrix Constructor 
        Matrix(int rows, int cols); // Non-Square Matrix Constructor
        Matrix(const Matrix& m) = delete; // Copy Constructor
        
        void createMatrix(); // Create the matrix
        void fillMatrix(int percent); // Fill the matrix with random numbers
        void printMatrix() const; // Print the matrix 
        int getNonZeroCount() const; // Get the number of non-zero elements
        void denseToSparse(); // Convert dense matrix to sparse matrix
        void printSparseMatrix() const; // Print the sparse matrix

        Matrix transpose() const; // Transpose matrix method (returning a new object)

        ~Matrix(); // Destructor
};

#endif
