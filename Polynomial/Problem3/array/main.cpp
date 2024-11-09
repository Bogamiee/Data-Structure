#include <iostream>
#include "TimeMsr.h"
#include "arrayPolynomial.h"
using namespace std;


int main() {
    int n, coeff, exp;
    TimeMsr timer;

    srand(static_cast<unsigned int>(time(0)));

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms: ";
    cin >> n;
    ArrayPolynomial polyArray1(n);
    for (int i = 0; i < n; ++i) {
        coeff = (rand() % 10 + 1) * (rand() % 2 == 0 ? 1 : -1);
        exp = n - i;
        polyArray1.setTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    ArrayPolynomial polyArray2(n);
    cout << "Enter terms (coefficient exponent) for the second polynomial:\n";
    for (int i = 0; i < n; ++i) {
        coeff = (rand() % 10 + 1) * (rand() % 2 == 0 ? 1 : -1);
        exp = n - i;
        polyArray2.setTerm(coeff, exp);
    }

    ArrayPolynomial sumArray(n);
    ArrayPolynomial subArray(n);

    /*
    cout << "polyArray1: ";
    polyArray1.display();
    cout << "polyArray2: ";
    polyArray2.display();
    */

    // 두 다항식의 덧셈
    timer.measureExecutionTime([&]{
        sumArray = polyArray1.add(polyArray2);
    });

    // 결과 출력
    cout << "sumArray (polyArray1 + polyArray2): ";
    /*
    sumArray.display();
    */
    timer.printExecutionTime();

    // 두 다항식의 뺄셈
    timer.measureExecutionTime([&]{
        subArray = polyArray1.sub(polyArray2);
    });

    // 결과 출력
    cout << "subArray (polyArray1 - polyArray2): ";
    /*
    subArray.display();
    */
    timer.printExecutionTime();

    return 0;
}
