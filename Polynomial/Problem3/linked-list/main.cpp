#include <iostream>
#include "linkedPolynomial.h"
#include "TimeMsr.h"
using namespace std;

int main() {
    int n, coeff, exp;
    TimeMsr timer;

    cout << "Linked List-based Polynomial:" << endl;

    ListPolynomial polyList1, polyList2;
    ListPolynomial sumList, subList;

    // 첫 번째 다항식 입력
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n;
    cout << "Enter terms (coefficient exponent) for the first polynomial:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        polyList1.setTerm(coeff, exp);
    }

    // 두 번째 다항식 입력
    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n;
    cout << "Enter terms (coefficient exponent) for the second polynomial:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coeff >> exp;
        polyList2.setTerm(coeff, exp);
    }
    
    cout << "polyList1: ";
    polyList1.display();
    cout << "polyList2: ";
    polyList2.display();
 
    // 덧셈 연산 측정
    timer.measureExecutionTime([&]{
        sumList = polyList1.add(polyList2);
    });
    
    cout << "sumList (polyList1 + polyList2): ";
    sumList.display();
    timer.printExecutionTime();

    // 뺄셈 연산 측정
    timer.measureExecutionTime([&]{
        subList = polyList1.sub(polyList2);
    });

    cout << "subList (polyList1 - polyList2): ";
    subList.display();
    timer.printExecutionTime();

    return 0;
}
