#ifndef MATRIXCALC_H
#define MATRIXCALC_H

#include "Matrix.h"

class MatrixCalc: public Matrix {
private:
    Matrix a;
    Matrix b;
public:
    MatrixCalc(const Matrix& a, const Matrix& b); // Constructor
    static Matrix add(const Matrix& a, const Matrix& b); // Add two matrices
    static Matrix sub(const Matrix& a, const Matrix& b); // Subtract two matrices
    static Matrix mul(const Matrix& a, const Matrix& b); // Multiply two matrices
    static Matrix div(const Matrix& a, const Matrix& b); // Divide two matrices
};

#endif
