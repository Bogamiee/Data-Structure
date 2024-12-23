#include <iostream>
#include "arrayPolynomial.h"
#include "TimeMsr.h"
using namespace std;


int main() {
    int n, coeff, exp;
    TimeMsr timer;

    srand(static_cast<unsigned int>(time(0)));

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n;
    ArrayPolynomial polyArray1(n);
    cout << "Enter terms (coefficient exponent) for the first polynomial:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        polyArray1.setTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n;
    ArrayPolynomial polyArray2(n);
    cout << "Enter terms (coefficient exponent) for the second polynomial:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        polyArray2.setTerm(coeff, exp);
    }

    ArrayPolynomial sumArray(n);

    // 두 다항식의 덧셈
    timer.measureExecutionTime([&]{
        sumArray = polyArray1.add(polyArray2);
    });
    
    // 결과 출력
    cout << "polyArray1: ";
    polyArray1.display();
    cout << "polyArray2: ";
    polyArray2.display();
    cout << "sumArray (polyArray1 + polyArray2): ";
    sumArray.display();
    timer.printExecutionTime();

    return 0;
}
