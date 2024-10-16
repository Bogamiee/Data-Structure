#ifndef MATRIXOPERATION_H 
#define MATRIXOPERATION_H

#include <iostream>
#include "Matrix.h"
#include "MatrixCalc.h"
#include "TimeMsr.h"
using namespace std;

class MatrixOperation {
    private:
        int percent;
        Matrix a, b, c;
        TimeMsr timer;
    public:
        MatrixOperation();
        MatrixOperation(int percent);
        ~MatrixOperation();
        void run();
        void printMenu();
        void makeMatrix(Matrix &a);
        void makeMatrix(Matrix &a, Matrix &b);
        void makeMatrix(Matrix &a, Matrix &b, int percent);
        void getDimensions(int &rows, int &cols);
        void performAdd();
        void performSub();
        void performMul();
        void performDiv();
        void performSparse();
        void performTranspose();
        void performOperation(int choice);
        void printResult(Matrix &a);
        void printResult(Matrix &a, Matrix &b);
        void printResult(Matrix &a, Matrix &b, Matrix &c);
};

#endif
