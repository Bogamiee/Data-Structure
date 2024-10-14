#include <vector>
#include <ctime>
#include "Matrix.h"

Matrix::Matrix(int n)
: rows(n), cols(n) {
    A.resize(rows * cols);
}

Matrix::Matrix(int rows, int cols)
: rows(rows), cols(cols) {
    A.resize(rows * cols);
}

void Matrix::fillMatrix(int percent) {
    srand(time(NULL));
    for (int i = 0; i < rows * cols; i++) {
        if (rand() % 100 < percent) 
            A[i] = 0;
        else
            A[i] = rand() % 9 + 1;
    }
}

void Matrix::printMatrix() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << A[i * cols + j] << " ";
        cout << endl;
    }
}

int Matrix::getNonZeroCount() const {
    int count = 0;
    for (int i = 0; i < rows * cols; i++) {
        if (A[i] != 0)
            count++;
    }
    return count;
}

void Matrix::denseToSparse() {
    int count = 0;

    S.resize(getNonZeroCount());
    for (int i = 0; i < rows * cols; i++) {
        if (A[i] != 0) {
            S[count].row = i / cols;
            S[count].col = i % cols;
            S[count].value = A[i];
            count++;
        }
    }
}

void Matrix::printSparseMatrix() const {
    for (int i = 0; i < S.size(); i++) {
        cout << S[i].row << " " << S[i].col << " " << S[i].value << endl;
    }
}

Matrix::~Matrix() {}
