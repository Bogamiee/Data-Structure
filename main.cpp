#include <iostream>
#include <ctime>
#include <chrono>
#include "Matrix.h"
#include "MatrixCalc.h"
using namespace std;

#define PERCENT 50

int main() {
    int choice, rows, cols;
    Matrix c;

    srand(static_cast<unsigned int>(time(NULL))); // Seed for randomness
    
    while (true) {
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
        cin >> choice;
        cout << endl;

        if (choice == 1 || choice == 2 || choice == 4) { // Add, subtract, divide
            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of columns: ";
            cin >> cols;
            cout << endl; 

            if (rows <= 0 || cols <= 0) {
                cout << "Invalid dimensions." << endl;
                continue;
            }

            Matrix a(rows, cols);
            Matrix b(rows, cols);

            a.fillMatrix(PERCENT);
            b.fillMatrix(0);
            
            MatrixCalc calc(a, b);

            if (choice == 1) {
                c = calc.add(a, b);
            } else if (choice == 2) {
                c = calc.sub(a, b);
            } else if (choice == 4) {
                c = calc.div(a, b);
            }
            cout << "Matrix A:" << endl;
            a.printMatrix();

            cout << endl << "Matrix B:" << endl;
            b.printMatrix();            

            cout << endl << "Result:" << endl;
            c.printMatrix();
        }
        else if (choice == 3) { // Multiply
            cout << "Enter the number of rows for the first matrix: ";
            cin >> rows;
            cout << "Enter the number of columns for the first matrix: ";
            cin >> cols;
            cout << endl;

            Matrix a(rows, cols);

            cout << "Enter the number of rows for the second matrix: ";
            cin >> rows;
            cout << "Enter the number of columns for the second matrix: ";
            cin >> cols;
            cout << endl;

            Matrix b(rows, cols);

            a.fillMatrix(PERCENT);
            b.fillMatrix(PERCENT);

            MatrixCalc calc(a, b);

            c = calc.mul(a, b);

            cout << "Matrix A:" << endl;
            a.printMatrix();

            cout << endl << "Matrix B:" << endl;
            b.printMatrix();

            cout << endl << "Result:" << endl;
            c.printMatrix();
        }
        else if (choice == 5) { // Sparse matrix operations
            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of columns: ";
            cin >> cols;
            cout << endl;

            if (rows <= 0 || cols <= 0) {
                cout << "Invalid dimensions." << endl;
                continue;
            }

            Matrix a(rows, cols);

            a.fillMatrix(PERCENT);
            a.denseToSparse();

            cout << "Matrix A:" << endl;
            a.printMatrix();

            cout << endl << "Sparse matrix A:" << endl;
            a.printSparseMatrix();
        }
        else if (choice == 6) { // Transpose
            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of columns: ";
            cin >> cols;
            cout << endl;

            if (rows <= 0 || cols <= 0) {
                cout << "Invalid dimensions." << endl;
                continue;
            }

            Matrix a(rows, cols);

            a.fillMatrix(PERCENT);
            a.transpose();

            cout << endl << "Matrix A:" << endl;
            a.printMatrix();
        }
        else if (choice == 7) { // Exit
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }
        cout << endl;
    }
    
    return 0;
}
