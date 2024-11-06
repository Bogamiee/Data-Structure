#include <iostream>
#include "arrayPolynomial.h"
using namespace std;


int main() {
    int n, coeff, exp;

    cout << "Array-based Polynomial:" << endl;

    ArrayPolynomial polyArray1(5);
    ArrayPolynomial polyArray2(5);

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n;
    cout << "Enter terms (coefficient exponent) for the first polynomial:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        polyArray1.setTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n;
    cout << "Enter terms (coefficient exponent) for the second polynomial:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        polyArray2.setTerm(coeff, exp);
    }

    // 두 다항식의 덧셈
    ArrayPolynomial sumArray = polyArray1.add(polyArray2);

    // 두 다항식의 뺄셈
    ArrayPolynomial subArray = polyArray1.sub(polyArray2);
    
    // 결과 출력
    cout << "polyArray1: ";
    polyArray1.display();
    cout << "polyArray2: ";
    polyArray2.display();
    cout << "sumArray (polyArray1 + polyArray2): ";
    sumArray.display();
    cout << "subArray (polyArray1 - polyArray2): ";
    subArray.display();

    return 0;
}
