#include "MatrixCalc.h"
#include "Matrix.h"

MatrixCalc::MatrixCalc() {}

MatrixCalc::MatrixCalc(Matrix& a) 
: a(a) {
    a.denseToSparse();
}

MatrixCalc::MatrixCalc(Matrix& a, Matrix& b)
: a(a), b(b) {
    a.denseToSparse();
    b.denseToSparse();
}

Matrix MatrixCalc::add() {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        cerr << "Error: Matrices must have the same dimensions." << endl;
        return Matrix(0, 0);
    }

    Matrix result(a.getRows(), a.getCols());

    for (unsigned int i = 0; i < a.getRows() * a.getCols(); i++) {
        result.setValue(i, a.getValue(i) + b.getValue(i));
    }

    return result;
}

Matrix MatrixCalc::sub() {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
        cerr << "Error: Matrices must have the same dimensions." << endl;
        return Matrix(0, 0);
    }

    Matrix result(a.getCols(), a.getRows());

    for (unsigned int i = 0; i < a.getRows() * a.getCols(); i++) {
        result.setValue(i, a.getValue(i) - b.getValue(i));
    }

    return result;
}

Matrix MatrixCalc::mul() {
    if (a.getCols() != b.getRows()) {
        cerr << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return Matrix(0, 0);
    }

    Matrix result(a.getRows(), b.getCols());

    for (unsigned int i = 0; i < a.getRows(); i++) {
        for (unsigned int j = 0; j < b.getCols(); j++) {
            int sum = 0;
            for (unsigned int k = 0; k < a.getCols(); k++) {
                sum += a.getValue(i * a.getCols() + k) * b.getValue(k * b.getCols() + j);
            }
            result.setValue(i * result.getCols() + j, sum);
        }
    }

    return result;
}

Matrix MatrixCalc::div() {
    if (a.getCols() != b.getCols() || a.getRows() != b.getRows()) {
        cerr << "Error: Matrices must have the same dimensions." << endl;
        return Matrix(0, 0);
    }
    
    Matrix result(a.getRows(), a.getCols());

    for (unsigned int i = 0; i < a.getRows() * a.getCols(); i++) {
        result.setValue(i, a.getValue(i) / b.getValue(i));
    }

    return result;
}

// Transpose the matrix
Matrix MatrixCalc::transpose() {
    Matrix result(a.getCols(), a.getRows());

    for (unsigned int i = 0; i < a.getRows(); i++) {
        for (unsigned int j = 0; j < a.getCols(); j++) {
            result.setValue(j * a.getRows() + i, a.getValue(i * a.getCols() + j));
        }
    }

    return result;
}
