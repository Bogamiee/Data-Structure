#include <ctime>
#include <cstdlib>
#include "Matrix.h"

#define endl "\n"

// Square Matrix Constructor
Matrix::Matrix(int n)
: rows(n), cols(n), A(nullptr), S(nullptr), nonZeroCount(0) {
    A = new int[rows * cols];
}

// Non-Square Matrix Constructor
Matrix::Matrix(int rows, int cols)
: rows(rows), cols(cols), A(nullptr), S(nullptr), nonZeroCount(0) {
    A = new int[rows * cols];
}

// Matrix filling function (same as before)
void Matrix::fillMatrix(int percent) {
    srand(time(NULL));
    for (int i = 0; i < rows * cols; i++) {
        if (rand() % 100 < percent) 
            A[i] = 0;
        else
            A[i] = rand() % 9 + 1;
    }
}

// Matrix printing function (same as before)
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
    
    if (S != nullptr) {
        delete[] S; // 기존의 S가 있으면 해제
    }

    S = new SparseMatrix[nonZeroCount]; // 새로운 희소 행렬 할당
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

// Sparse matrix printing function (same as before)
void Matrix::printSparseMatrix() const {
    for (int i = 0; i < nonZeroCount; i++) {
        cout << S[i].row << " " << S[i].col << " " << S[i].value << endl;
    }
}

// Destructor
Matrix::~Matrix() {
    delete[] A; // Free the memory for the matrix
    delete[] S; // Free the memory for the sparse matrix
}
