#include "linkedPolynomial.h"
#include <iostream>
using namespace std;

Node::Node(int c, int e) : coefficient(c), exponent(e), next(nullptr) {}

ListPolynomial::ListPolynomial() : head(nullptr) {}

ListPolynomial::~ListPolynomial() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void ListPolynomial::insertTerm(int coefficient, int exponent) {
    Node** current = &head;
    while (*current && (*current)->exponent > exponent) {
        current = &((*current)->next);
    }
    if (*current && (*current)->exponent == exponent) {
        (*current)->coefficient += coefficient;
    } else {
        Node* newNode = new Node(coefficient, exponent);
        newNode->next = *current;
        *current = newNode;
    }
}

void ListPolynomial::setTerm(int coefficient, int exponent) {
    if (coefficient != 0) insertTerm(coefficient, exponent);
}

ListPolynomial ListPolynomial::add(const ListPolynomial& other) const {
    ListPolynomial result;
    Node* ptrA = head;
    Node* ptrB = other.head;

    while (ptrA || ptrB) {
        if (ptrA && (!ptrB || ptrA->exponent > ptrB->exponent)) {
            result.setTerm(ptrA->coefficient, ptrA->exponent);
            ptrA = ptrA->next;
        } else if (ptrB && (!ptrA || ptrB->exponent > ptrA->exponent)) {
            result.setTerm(ptrB->coefficient, ptrB->exponent);
            ptrB = ptrB->next;
        } else if (ptrA && ptrB) {  // 같은 지수일 때
            int sumCoeff = ptrA->coefficient + ptrB->coefficient;
            if (sumCoeff != 0) result.setTerm(sumCoeff, ptrA->exponent);
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
    }
    return result;
}

ListPolynomial ListPolynomial::sub(const ListPolynomial& other) const {
    ListPolynomial result;
    Node* ptrA = head;
    Node* ptrB = other.head;

    while (ptrA || ptrB) {
        if (ptrA && (!ptrB || ptrA->exponent > ptrB->exponent)) {
            result.setTerm(ptrA->coefficient, ptrA->exponent);
            ptrA = ptrA->next;
        } else if (ptrB && (!ptrA || ptrB->exponent > ptrA->exponent)) {
            result.setTerm(-ptrB->coefficient, ptrB->exponent);
            ptrB = ptrB->next;
        } else if (ptrA && ptrB) {  // 같은 지수일 때
            int subCoeff = ptrA->coefficient - ptrB->coefficient;
            if (subCoeff != 0) result.setTerm(subCoeff, ptrA->exponent);
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
    }
    return result;
}

void ListPolynomial::display() const {
    Node* current = head;
    bool first = true;
    while (current) {
        if (first) {
            cout << current->coefficient;
        } else {
            cout << (current->coefficient >= 0 ? " + " : " - ") << abs(current->coefficient);
        }
        if (current->exponent != 0) cout << "x^" << current->exponent;
        first = false;
        current = current->next;
    }
    if (first) cout << "0";
    cout << endl;
}

