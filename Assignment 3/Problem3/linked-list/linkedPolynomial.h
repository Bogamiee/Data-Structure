#ifndef LINKEDPOLYNOMIAL_H
#define LINKEDPOLYNOMIAL_H

struct Node {
    int coefficient;
    int exponent;
    Node* next;

    Node(int c, int e);
};

class ListPolynomial {
private:
    Node* head;

    // 내부 함수: 항을 삽입하는 함수
    void insertTerm(int coefficient, int exponent);

public:
    // 생성자와 소멸자
    ListPolynomial();
    ~ListPolynomial();

    // 항을 설정하는 함수
    void setTerm(int coefficient, int exponent);
    
    // 두 다항식의 덧셈
    ListPolynomial add(const ListPolynomial& other) const;

    // 두 다항식의 뺄셈
    ListPolynomial sub(const ListPolynomial& other) const;

    // 다항식 출력
    void display() const;
};

#endif // LINKEDPOLYNOMIAL_H
