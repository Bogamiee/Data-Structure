#include <iostream>
#include "arrayPolynomial.h"
using namespace std;


int main() {
    int a, b, coeff, exp;
    TimeMsr timer;

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> a;
    ArrayPolynomial polyArray1(a);
    cout << "Enter terms (coefficient exponent) for the first polynomial:\n";
    for (int i = 0; i < a; ++i) {
        cin >> coeff >> exp;
        polyArray1.setTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    cout << "Enter the number of terms in the second polynomial: ";
    cin >> b;
    ArrayPolynomial polyArray2(b);
    cout << "Enter terms (coefficient exponent) for the second polynomial:\n";
    for (int i = 0; i < b; ++i) {
        cin >> coeff >> exp;
        polyArray2.setTerm(coeff, exp);
    }

    ArrayPolynomial sumArray(a + b);
    ArrayPolynomial subArray(a + b);

    cout << "polyArray1: ";
    polyArray1.display();
    cout << "polyArray2: ";
    polyArray2.display();

    // 두 다항식의 덧셈
    timer.measureExecutionTime([&]{
        sumArray = polyArray1.add(polyArray2);
    });

    // 결과 출력
    cout << "sumArray (polyArray1 + polyArray2): ";
    sumArray.display();
    timer.printExecutionTime();

    // 두 다항식의 뺄셈
    timer.measureExecutionTime([&]{
        subArray = polyArray1.sub(polyArray2);
    });

    // 결과 출력
    cout << "subArray (polyArray1 - polyArray2): ";
    subArray.display();
    timer.printExecutionTime();

    return 0;
}
