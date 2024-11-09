#include <iostream>
#include "polynomial.h"
#include "TimeMsr.h"
using namespace std;

int main() {
    Polynomial poly1, poly2, sum, diff;

    int n, coeff, exp;

    srand(static_cast<unsigned int>(time(0)));

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        coeff = (rand() % 10 + 1) * (rand() % 2 == 0 ? 1 : -1);
        exp = n - i;
        poly1.addTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    for (int i = 0; i < n; ++i) {
        coeff = (rand() % 10 + 1) * (rand() % 2 == 0 ? 1 : -1);
        exp = n - i;
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
