#include <iostream>
#include "Matrix.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)

int main() {
    fast;
    int N;
    cin >> N;

    Matrix a(N);
    a.fillMatrix(50);
    a.printMatrix();

    cout << "\n";

    a.denseToSparse();
    a.printSparseMatrix();
    a.transpose();

    return 0;
}
