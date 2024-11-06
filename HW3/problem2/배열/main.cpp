#include <iostream>
#include "ArrayPolynomial.h"
using namespace std;


int main() {
    cout << "Array-based Polynomial:" << endl;

    ArrayPolynomial polyArray1(5);
    ArrayPolynomial polyArray2(5);

    // 다항식 1: 3x^5 + 2x^3 + x
    polyArray1.setTerm(3, 5); // 3x^5
    polyArray1.setTerm(2, 3); // 2x^3
    polyArray1.setTerm(1, 1); // x

    // 다항식 2: 5x^5 + x^3 + 4
    polyArray2.setTerm(5, 5); // 5x^5
    polyArray2.setTerm(1, 3); // x^3
    polyArray2.setTerm(4, 0); // 4

    // 두 다항식의 덧셈
    ArrayPolynomial sumArray = polyArray1.add(polyArray2);
    
    // 결과 출력
    cout << "polyArray1: ";
    polyArray1.display();
    cout << "polyArray2: ";
    polyArray2.display();
    cout << "sumArray (polyArray1 + polyArray2): ";
    sumArray.display();

    return 0;
}
