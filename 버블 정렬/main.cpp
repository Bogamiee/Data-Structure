#include <iostream>
#include "BubbleSort.h"
#include "TimeMsr.h"

using namespace std;

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);

    TimeMsr timer;
    BubbleSort sorter;

    // 실행 시간 측정
    timer.measureExecutionTime([&]() {
        sorter.sort(data, size);
    });

    // 정렬된 배열 출력
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    // 실행 시간 출력
    timer.printExecutionTime();

    return 0;
}
