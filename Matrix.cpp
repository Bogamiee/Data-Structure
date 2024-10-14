#include <ctime>
#include <cstdlib>
#include "Matrix.h"

#define endl "\n"

// Square Matrix Constructor
Matrix::Matrix(int n)
: rows(n), cols(n), A(nullptr), S(nullptr), nonZeroCount(0) {
    A = new int[rows * cols]();
}

// Non-Square Matrix Constructor
Matrix::Matrix(int rows, int cols)
: rows(rows), cols(cols), A(nullptr), S(nullptr), nonZeroCount(0) {
    A = new int[rows * cols]();
}

// Matrix filling function
void Matrix::fillMatrix(int percent) {
    srand(static_cast<unsigned int>(time(NULL))); // Seed for randomness
    for (int i = 0; i < rows * cols; i++) {
        if (rand() % 100 < percent) 
            A[i] = 0;
        else
            A[i] = rand() % 9 + 1;
    }
}

// Matrix printing function
void Matrix::printMatrix() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << A[i * cols + j] << " ";
        cout << endl;
    }
}

// Function to count non-zero elements
int Matrix::getNonZeroCount() const {
    int count = 0;
    for (int i = 0; i < rows * cols; i++) {
        if (A[i] != 0)
            count++;
    }
    return count;
}

// Dense to Sparse matrix conversion
void Matrix::denseToSparse() {
    nonZeroCount = getNonZeroCount();
    
    delete[] S; // Free previous memory for sparse matrix
    S = new SparseMatrix[nonZeroCount]; // Allocate new sparse matrix
    int count = 0;
    
    for (int i = 0; i < rows * cols; i++) {
        if (A[i] != 0) {
            S[count].row = i / cols; // Row index
            S[count].col = i % cols; // Column index
            S[count].value = A[i];   // Non-zero value
            count++;
        }
    }
}

// Sparse matrix printing function
void Matrix::printSparseMatrix() const {
    for (int i = 0; i < nonZeroCount; i++) {
        cout << S[i].row << " " << S[i].col << " " << S[i].value << endl;
    }
}

// Transpose matrix method (returns a new Matrix object)
Matrix Matrix::transpose() const {
    Matrix transposed(cols, rows); // Create new transposed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed.A[j * rows + i] = A[i * cols + j]; // Transpose values
        }
    }
    return transposed; // Return the transposed matrix
}

// Destructor
Matrix::~Matrix() {
    delete[] A; // Free the memory for the matrix
    delete[] S; // Free the memory for the sparse matrix
}
