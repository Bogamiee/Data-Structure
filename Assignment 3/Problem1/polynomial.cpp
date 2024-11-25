#include <iostream>
#include <algorithm>
#include "polynomial.h"
using namespace std;

// 동일 지수의 항들을 합산하는 메서드
void Polynomial::combineLikeTerms() {
    sort(terms.begin(), terms.end());
    vector<Term> combined;
    for (size_t i = 0; i < terms.size();) {
        int coeff_sum = terms[i].coefficient;
        int exp = terms[i].exponent;
        size_t j = i + 1;
        while (j < terms.size() && terms[j].exponent == exp) {
            coeff_sum += terms[j].coefficient;
            j++;
        }
        if (coeff_sum != 0) {
            combined.push_back(Term(coeff_sum, exp));
        }
        i = j;
    }
    terms = combined;
}

// 다항식에 항 추가
void Polynomial::addTerm(int coefficient, int exponent) {
    terms.push_back(Term(coefficient, exponent));
    combineLikeTerms();
}

// 두 다항식의 덧셈
Polynomial Polynomial::add(const Polynomial& other) const {
    Polynomial result = *this;
    for (const auto& term : other.terms) {
        result.addTerm(term.coefficient, term.exponent);
    }
    return result;
}

// 두 다항식의 뺄셈
Polynomial Polynomial::subtract(const Polynomial& other) const {
    Polynomial result = *this;
    for (const auto& term : other.terms) {
        result.addTerm(-term.coefficient, term.exponent);
    }
    return result;
}

// 다항식 출력
void Polynomial::display() const {
    for (size_t i = 0; i < terms.size(); ++i) {
        if (terms[i].coefficient > 0 && i > 0) cout << " + ";
        if (terms[i].coefficient < 0) cout << " - ";
        cout << abs(terms[i].coefficient);
        if (terms[i].exponent != 0) cout << "x^" << terms[i].exponent;
    }
}
