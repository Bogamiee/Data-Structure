#ifndef MATRIXCALC_H
#define MATRIXCALC_H

#include "Matrix.h"

class MatrixCalc: public Matrix {
private:
    Matrix a;
    Matrix b;
public:
    MatrixCalc(); // Constructor
    MatrixCalc(Matrix& a); // Constructor
    MatrixCalc(Matrix& a, Matrix& b); // Constructor
    Matrix add(); // Add two matrices
    Matrix sub(); // Subtract two matrices
    Matrix mul(); // Multiply two matrices
    Matrix div(); // Divide two matrices
    Matrix transpose(); // Transpose a matrix
};

#endif
