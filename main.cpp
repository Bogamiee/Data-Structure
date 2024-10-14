#include <iostream>
#include "Matrix.h"
#include "MatrixCalc.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)

int main() {
    fast;
    int N;
    cin >> N;

    srand(static_cast<unsigned int>(time(NULL))); // Seed for randomness
                                                  
    Matrix a(N);
    a.fillMatrix(50);
    a.printMatrix();

    cout << "\n";

    Matrix b(N);
    b.fillMatrix(50);
    b.printMatrix();

    cout << "\n";

    MatrixCalc calc(a, b);
    Matrix c = calc.add(a, b);
    c.printMatrix();

    cout << "\n";

    Matrix d = calc.sub(a, b);
    d.printMatrix();

    cout << "\n";

    Matrix e = calc.mul(a, b);
    e.printMatrix();

    return 0;
}
