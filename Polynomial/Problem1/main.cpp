#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    Polynomial poly1, poly2;

    int n, coeff, exp;

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n;
    cout << "Enter terms (coefficient exponent) for the first polynomial:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        poly1.addTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n;
    cout << "Enter terms (coefficient exponent) for the second polynomial:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        poly2.addTerm(coeff, exp);
    }

    // 덧셈 결과 출력
    cout << "Addition of the polynomials:\n";
    Polynomial sum = poly1.add(poly2);
    sum.display();

    // 뺄셈 결과 출력
    cout << "Subtraction of the polynomials:\n";
    Polynomial diff = poly1.subtract(poly2);
    diff.display();

    return 0;
}
