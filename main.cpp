#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix a(5);
    a.createMatrix();
    a.fillMatrix(50);
    a.printMatrix();
    a.~Matrix();
    return 0;
}
