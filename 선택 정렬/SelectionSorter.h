#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H

class SelectionSorter
{
private:
    int* list;    // 배열 포인터
    int size;     // 배열 크기

public:
    // 생성자와 소멸자
    SelectionSorter(int n);
    ~SelectionSorter();

    // 멤버 함수들
    void initRandom(int max = 100);       // 배열을 랜덤으로 초기화
    void printArray(const char* str) const;   // 배열을 출력
    void selectionSort();                 // 선택 정렬 수행
};

#endif // SELECTIONSORTER_H
