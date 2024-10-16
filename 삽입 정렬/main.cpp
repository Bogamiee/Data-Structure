#include <iostream>
#include "InsertionSorter.h"
#include "TimeMsr.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    InsertionSorter sorter(n);  // 객체 생성
    sorter.initRandom();         // 배열 초기화
    cout << "Original: ";
    sorter.printArray("Original");

    TimeMsr timer; // TimeMsr 객체 생성
    timer.measureExecutionTime([&]() { // 실행 시간 측정
        sorter.insertionSort();      // 삽입 정렬 수행
    });

    sorter.printArray("Sorted");    // 정렬 후 출력
    timer.printExecutionTime();      // 실행 시간 출력

    return 0;
}

