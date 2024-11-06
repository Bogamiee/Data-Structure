#include <iostream>
#include "ListPolynomial.h"


int main() {
    cout << "Linked List-based Polynomial:" << endl;

    ListPolynomial polyList1;
    ListPolynomial polyList2;

    // 다항식 1: 3x^5 + 2x^3 + x
    polyList1.setTerm(3, 5); // 3x^5
    polyList1.setTerm(2, 3); // 2x^3
    polyList1.setTerm(1, 1); // x

    // 다항식 2: 5x^5 + x^3 + 4
    polyList2.setTerm(5, 5); // 5x^5
    polyList2.setTerm(1, 3); // x^3
    polyList2.setTerm(4, 0); // 4

    // 두 다항식의 덧셈
    ListPolynomial sumList = polyList1.add(polyList2);
    
    // 결과 출력
    cout << "polyList1: ";
    polyList1.display();
    cout << "polyList2: ";
    polyList2.display();
    cout << "sumList (polyList1 + polyList2): ";
    sumList.display();

    return 0;
}
