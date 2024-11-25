#ifndef TERM_H
#define TERM_H

struct Term {
    int coefficient; // 계수
    int exponent;    // 지수

    Term(int c, int e) : coefficient(c), exponent(e) {}

    // 지수를 기준으로 내림차순 정렬을 위한 연산자
    bool operator<(const Term& other) const {
        return exponent > other.exponent;
    }
};

#endif // TERM_H
