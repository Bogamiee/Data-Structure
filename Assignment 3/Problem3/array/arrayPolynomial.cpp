#include "arrayPolynomial.h"
#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"

ArrayPolynomial::ArrayPolynomial(int maxDegree) : coefficients(maxDegree + 1, 0) {}

void ArrayPolynomial::setTerm(int coefficient, int exponent) {
    if (exponent >= 0 && exponent < (int)coefficients.size()) {
        coefficients[exponent] = coefficient;
    }
}

ArrayPolynomial ArrayPolynomial::add(const ArrayPolynomial& other) const {
    int maxDegree = max(coefficients.size(), other.coefficients.size());
    ArrayPolynomial result(maxDegree - 1);

    for (int i = 0; i < maxDegree; ++i) {
        int coeffA = i < (int)coefficients.size() ? coefficients[i] : 0;
        int coeffB = i < (int)other.coefficients.size() ? other.coefficients[i] : 0;
        result.setTerm(coeffA + coeffB, i);
    }
    return result;
}

ArrayPolynomial ArrayPolynomial::sub(const ArrayPolynomial& other) const {
    int maxDegree = max(coefficients.size(), other.coefficients.size());
    ArrayPolynomial result(maxDegree - 1);

    for (int i = 0; i < maxDegree; ++i) {
        int coeffA = i < (int)coefficients.size() ? coefficients[i] : 0;
        int coeffB = i < (int)other.coefficients.size() ? other.coefficients[i] : 0;
        result.setTerm(coeffA - coeffB, i);
    }
    return result;
}

void ArrayPolynomial::display() const {
    bool first = true;
    for (int i = coefficients.size() - 1; i >= 0; --i) {
        if (coefficients[i] != 0) {
            if (!first) {
                if (coefficients[i] > 0) {
                    cout << " + " << coefficients[i];
                } else {
                    cout << " - " << -coefficients[i];
                }
            } else {
                cout << (coefficients[i] < 0 ? "- " : "") << abs(coefficients[i]);
            }
            first = false;
            if (i > 0) cout << "x^" << i;
        }
    }
    if (first) cout << "0";
    cout << endl;
}

