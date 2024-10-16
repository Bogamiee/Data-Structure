#ifndef INSERTIONSORTER_H
#define INSERTIONSORTER_H

class InsertionSorter {
private:
    int* list;    // 배열 포인터
    int size;     // 배열 크기

public:
    // 생성자와 소멸자
    InsertionSorter(int n);
    ~InsertionSorter();

    // 멤버 함수들
    void initRandom(int max = 100);       // 배열을 랜덤으로 초기화
    void printArray(const char* str) const;   // 배열을 출력
    void insertionSort();                 // 삽입 정렬 수행
};

#endif // INSERTIONSORTER_H
