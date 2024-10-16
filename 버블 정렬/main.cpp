#include <iostream>
#include "BubbleSort.h"
#include "TimeMsr.h"

using namespace std;

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);

    TimeMsr timer;
    BubbleSort sorter;

    // ���� �ð� ����
    timer.measureExecutionTime([&]() {
        sorter.sort(data, size);
    });

    // ���ĵ� �迭 ���
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    // ���� �ð� ���
    timer.printExecutionTime();

    return 0;
}
