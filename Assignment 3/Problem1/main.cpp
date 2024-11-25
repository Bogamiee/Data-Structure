#include <iostream>
#include "polynomial.h"
#include "TimeMsr.h"
using namespace std;

int main() {
    Polynomial poly1, poly2, sum, diff;

    int n, coeff, exp;

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms in the polynomial 1: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        poly1.addTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    cout << "Enter the number of terms in the polynomial 2: ";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        poly2.addTerm(coeff, exp);
    }

    TimeMsr timer;

    // 덧셈 결과 출력
    cout << "\nAddition of the polynomials:\n";
    timer.measureExecutionTime([&]() {
        sum = poly1.add(poly2);
    });
    // sum.display();
    timer.printExecutionTime();

    // 뺄셈 결과 출력
    cout << "\nSubtraction of the polynomials:\n";
    timer.measureExecutionTime([&]() {
        diff = poly1.subtract(poly2);
    });
    // diff.display();
    timer.printExecutionTime();

    return 0;
}
