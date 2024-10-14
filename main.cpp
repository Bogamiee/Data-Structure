#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix a(5);
    a.fillMatrix(50);
    a.printMatrix();

    cout << endl;

    a.denseToSparse();
    a.printSparseMatrix();

    return 0;
}
