#include "MatrixCalc.h"
#include "Matrix.h"

MatrixCalc::MatrixCalc(const Matrix& a, const Matrix& b)
: a(a), b(b) {}

Matrix MatrixCalc::add(const Matrix& a, const Matrix& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        cerr << "Error: Matrices must have the same dimensions." << endl;
        return Matrix(0);
    }

    Matrix result(a.getRows(), a.getCols());

    for (int i = 0; i < a.getRows() * a.getCols(); i++) {
        result.setValue(i, a.getValue(i) + b.getValue(i));
    }

    return result;
}

Matrix MatrixCalc::sub(const Matrix& a, const Matrix& b) {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        cerr << "Error: Matrices must have the same dimensions." << endl;
        return Matrix(0);
    }

    Matrix result(a.getCols(), a.getRows());

    for (int i = 0; i < a.getRows() * a.getCols(); i++) {
        result.setValue(i, a.getValue(i) - b.getValue(i));
    }

    return result;
}

Matrix MatrixCalc::mul(const Matrix& a, const Matrix& b) {
    if (a.getCols() != b.getRows()) {
        cerr << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return Matrix(0);
    }

    Matrix result(a.getRows(), b.getCols());

    for (int i = 0; i < a.getRows(); i++) {
        for (int j = 0; j < b.getCols(); j++) {
            int sum = 0;
            for (int k = 0; k < a.getCols(); k++) {
                sum += a.getValue(i * a.getCols() + k) * b.getValue(k * b.getCols() + j);
            }
            result.setValue(i * result.getCols() + j, sum);
        }
    }

    return result;
}

Matrix MatrixCalc::div(const Matrix& a, const Matrix& b) {
    Matrix result(0);
    return result;
}
