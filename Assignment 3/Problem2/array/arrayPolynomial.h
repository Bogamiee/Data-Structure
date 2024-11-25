#ifndef ARRAYPOLYNOMIAL_H
#define ARRAYPOLYNOMIAL_H

#include <vector>

class ArrayPolynomial {
private:
    std::vector<int> coefficients;

public:
    // 생성자: 최대 차수를 받습니다.
    ArrayPolynomial(int maxDegree);

    // 항을 설정하는 함수
    void setTerm(int coefficient, int exponent);

    // 두 다항식의 덧셈
    ArrayPolynomial add(const ArrayPolynomial& other) const;

    // 다항식 출력
    void display() const;
};

#endif // ARRAYPOLYNOMIAL_H
