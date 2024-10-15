#include <ctime>
#include <cstdlib>
#include "Matrix.h"

#define endl "\n"

// Default constructor
Matrix::Matrix()
: rows(0), cols(0), A(nullptr), S(nullptr), nonZeroCount(0) {}

// Square matrix constructor
Matrix::Matrix(int n)
: rows(n), cols(n), A(nullptr), S(nullptr), nonZeroCount(0) {
    A = new int[rows * cols](); // Initialize with zeros
}

// Non-square matrix constructor
Matrix::Matrix(int rows, int cols)
: rows(rows), cols(cols), A(nullptr), S(nullptr), nonZeroCount(0) {
    A = new int[rows * cols](); // Initialize with zeros
}

// Copy constructor
Matrix::Matrix(const Matrix& m)
: rows(m.rows), cols(m.cols), A(new int[m.rows * m.cols]), S(new SparseMatrix[m.nonZeroCount]), nonZeroCount(m.nonZeroCount) {
    for (int i = 0; i < rows * cols; i++) {
        A[i] = m.A[i];
    }
    for (int i = 0; i < nonZeroCount; i++) {
        S[i] = m.S[i];
    }
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& m) {
    if (this == &m) {
        return *this;
    }

    delete[] A; // Free memory for matrix
    delete[] S; // Free memory for sparse matrix

    rows = m.rows;
    cols = m.cols;
    nonZeroCount = m.nonZeroCount;

    A = new int[rows * cols];
    S = new SparseMatrix[nonZeroCount];

    for (int i = 0; i < rows * cols; i++) {
        A[i] = m.A[i];
    }
    for (int i = 0; i < nonZeroCount; i++) {
        S[i] = m.S[i];
    }

    return *this;
}

// Get the number of rows
int Matrix::getRows() const {
    return rows;
}

// Get the number of columns
int Matrix::getCols() const {
    return cols;
}

// Get the value at the given index
int Matrix::getValue(int index) const {
    if (index < 0 || index >= rows * cols) {
        cerr << "Error: Index out of bounds." << endl;
        return -1;
    }
    return A[index];
}

// Fill the matrix with random numbers
void Matrix::fillMatrix(int percent) {
    if (percent < 0 || percent > 100) {
        cerr << "Error: Percent must be between 0 and 100." << endl;
        return;
    }
    for (int i = 0; i < rows * cols; i++) {
        if (rand() % 100 < percent) 
            A[i] = 0; // Set to zero
        else
            A[i] = rand() % 9 + 1; // Set to a random number between 1 and 9
    }
}

// Print the matrix
void Matrix::printMatrix() const {
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++)
            cout << A[i * cols + j] << " ";
        cout << endl;
    }
}

// Get the number of non-zero elements
int Matrix::getNonZeroCount() const {
    int count = 0;
    for (int i = 0; i < rows * cols; i++) {
        if (A[i] != 0)
            count++;
    }
    return count;
}

// Convert dense matrix to sparse matrix
void Matrix::denseToSparse() {
    nonZeroCount = getNonZeroCount(); // Count non-zero elements
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

// Print the sparse matrix
void Matrix::printSparseMatrix() const {
    for (int i = 0; i < nonZeroCount; i++) {
        cout << S[i].row << " " << S[i].col << " " << S[i].value << endl;
    }
}

// Transpose the matrix and print it directly
void Matrix::transpose() const {
    for (unsigned int i = 0; i < cols; i++) {
        for (unsigned int j = 0; j < rows; j++) {
            cout << A[j * cols + i] << " "; // Access transposed values
        }
        cout << endl; // New line after each row
    }
}

// Set the value at the given index
void Matrix::setValue(int index, int value) {
    if (index < 0 || index >= rows * cols) {
        cerr << "Error: Index out of bounds." << endl;
        return;
    }
    A[index] = value;
}

// Destructor
Matrix::~Matrix() {
    delete[] A; // Free memory for matrix
    delete[] S; // Free memory for sparse matrix
}



