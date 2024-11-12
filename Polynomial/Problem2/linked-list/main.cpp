#include <iostream>
#include "linkedPolynomial.h"
#include "TimeMsr.h"
using namespace std;

int main() {
    int n, coeff, exp;

    cout << "Linked List-based Polynomial:" << endl;

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n;
    ListPolynomial polyList1;
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        polyList1.setTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n;
    ListPolynomial polyList2;
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        polyList2.setTerm(coeff, exp);
    }

    // 두 다항식의 덧셈
    ListPolynomial sumList;
    TimeMsr timer;

    timer.measureExecutionTime([&]() {
        sumList = polyList1.add(polyList2);
    });

    // 결과 출력
    /*
    cout << "polyList1: ";
    polyList1.display();
    cout << "polyList2: ";
    polyList2.display();
    cout << "sumList (polyList1 + polyList2): ";
    sumList.display();
    */
    timer.printExecutionTime();

    return 0;
}
