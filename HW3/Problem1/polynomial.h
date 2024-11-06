#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include "Term.h"

class Polynomial {
private:
    std::vector<Term> terms;

    // 동일 지수의 항들을 합산하는 메서드
    void combineLikeTerms();

public:
    // 다항식에 항 추가
    void addTerm(int coefficient, int exponent);

    // 두 다항식의 덧셈
    Polynomial add(const Polynomial& other) const;

    // 두 다항식의 뺄셈
    Polynomial subtract(const Polynomial& other) const;

    // 다항식 출력
    void display() const;
};

#endif // POLYNOMIAL_H
