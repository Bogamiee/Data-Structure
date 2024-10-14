#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
using namespace std;

struct SparseMatrix {
    int row; // 행
    int col; // 열
    int value; // 값
};

class Matrix {
    private:
        unsigned int rows; // Number of rows
        unsigned int cols; // Number of columns
        vector<int> A; // Matrix
        vector<SparseMatrix> S; // Sparse Matrix       
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

        ~Matrix(); // Destructor
};

#endif
