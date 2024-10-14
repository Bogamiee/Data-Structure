#include "Matrix.h"

Matrix::Matrix() {
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int nums) {
    rows = nums;
    cols = nums;
}

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
}

void Matrix::createMatrix() {
    A = new int[rows * cols];
}

void Matrix::fillMatrix(int percent) {
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

Matrix::~Matrix() {
    delete[] A;
}
