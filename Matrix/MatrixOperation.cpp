#include "MatrixOperation.h"

MatrixOperation::MatrixOperation() {}

MatrixOperation::MatrixOperation(int percent)
: percent(percent) {}

MatrixOperation::~MatrixOperation() {}

void MatrixOperation::run() {
    int choice;

    while (true) {
        printMenu();
        cin >> choice;
        cout << endl;

        if (choice == 7) {
            break;
        }
        else if (choice > 0 && choice < 7) {
            performOperation(choice);
        } 
        else {
            cout << "Invalid choice." << endl;
        }
        cout << endl;
    }
}

void MatrixOperation::printMenu() {
    cout << "==================================" << endl;
    cout << "1. Add two matrices" << endl;
    cout << "2. Subtract two matrices" << endl;
    cout << "3. Multiply two matrices" << endl;
    cout << "4. Divide two matrices" << endl;
    cout << "5. Sparse matrix operations" << endl;
    cout << "6. Transpose a matrix" << endl;
    cout << "7. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Enter your choice: ";
}

void MatrixOperation::getDimensions(int &rows, int &cols) {
    while (true) {
        cout << "Enter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> cols;
        if (rows <= 0 || cols <= 0) {
            cout << "Invalid dimensions." << endl;
            continue;
        }
        cout << endl; 
        return;
    }
}

void MatrixOperation::makeMatrix(Matrix &a) {
    int rows, cols;
    getDimensions(rows, cols);
    a = Matrix(rows, cols);
    a.fillMatrix(percent);
}

void MatrixOperation::makeMatrix(Matrix &a, Matrix &b) {
    int rows, cols;
    getDimensions(rows, cols);
    a = Matrix(rows, cols);
    b = Matrix(rows, cols);
    a.fillMatrix(percent);
    b.fillMatrix(percent);
}

void MatrixOperation::makeMatrix(Matrix &a, Matrix &b, int p) {
    int rows, cols;
    getDimensions(rows, cols);
    a = Matrix(rows, cols);
    b = Matrix(rows, cols);
    a.fillMatrix(percent);
    b.fillMatrix(p);
}

void MatrixOperation::performAdd() {
    makeMatrix(a, b);
    MatrixCalc calc(a, b);
    timer.measureExecutionTime([&] {
        c = calc.add(a, b);
    });
}

void MatrixOperation::performSub() {
    makeMatrix(a, b);
    MatrixCalc calc(a, b);
    timer.measureExecutionTime([&] {
        c = calc.sub(a, b);
    });
}

void MatrixOperation::performMul() {
    cout << "Matrix A:" << endl;
    makeMatrix(a);
    cout << "Matrix B:" << endl;
    makeMatrix(b);
    MatrixCalc calc(a, b);
    timer.measureExecutionTime([&] {
        c = calc.mul(a, b);
    });
}

void MatrixOperation::performDiv() {
    makeMatrix(a, b, 0);
    MatrixCalc calc(a, b);
    timer.measureExecutionTime([&] {
        c = calc.div(a, b);
    });
}

void MatrixOperation::performSparse() {
    makeMatrix(a);
    timer.measureExecutionTime([&] {
        a.denseToSparse();
    });
}

void MatrixOperation::performTranspose() {
    makeMatrix(a);
    MatrixCalc calc(a);
    timer.measureExecutionTime([&] {
        c = calc.transpose(a);
    });
}

void MatrixOperation::performOperation(int choice) {
    switch (choice) {
        case 1:
            performAdd();
            printResult(a, b, c);
            break;
        case 2:
            performSub();
            printResult(a, b, c);
            break;
        case 3:
            performMul();
            printResult(a, b, c);
            break;
        case 4:
            performDiv();
            printResult(a, b, c);
            break;
        case 5:
            performSparse();
            printResult(a);
            cout << endl << "Sparse matrix:" << endl;
            a.printSparseMatrix();
            break;
        default:
            performTranspose();
            printResult(a, c);
            break;
    }
    timer.printExecutionTime();
}

void MatrixOperation::printResult(Matrix &a) {
    cout << "Matrix A:" << endl;
    a.printMatrix();
}

void MatrixOperation::printResult(Matrix &a, Matrix &b) {
    cout << "Matrix A:" << endl;
    a.printMatrix();

    cout << endl << "Result:" << endl;
    b.printMatrix();
}

void MatrixOperation::printResult(Matrix &a, Matrix &b, Matrix &c) {
    cout << "Matrix A:" << endl;
    a.printMatrix();

    cout << endl << "Matrix B:" << endl;
    b.printMatrix();

    cout << endl << "Result:" << endl;
    c.printMatrix();
}
