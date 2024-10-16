#include <iostream>
#include "InsertionSorter.h"
#include "TimeMsr.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    InsertionSorter sorter(n);  // ��ü ����
    sorter.initRandom();         // �迭 �ʱ�ȭ
    cout << "Original: ";
    sorter.printArray("Original");

    TimeMsr timer; // TimeMsr ��ü ����
    timer.measureExecutionTime([&]() { // ���� �ð� ����
        sorter.insertionSort();      // ���� ���� ����
    });

    sorter.printArray("Sorted");    // ���� �� ���
    timer.printExecutionTime();      // ���� �ð� ���

    return 0;
}

