#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

class BubbleSorter {
private:
    int* list;    // 배열 포인터
    int size;     // 배열 크기

public:
    // 생성자와 소멸자
    BubbleSorter(int n);
    ~BubbleSorter();

    // 멤버 함수들
    void initRandom(int max = 100);       // 배열을 랜덤으로 초기화
    void printArray(const char* str) const;   // 배열을 출력
    void BubbleSort();                 // 삽입 정렬 수행
};

#endif // BubbleSORTER_H
