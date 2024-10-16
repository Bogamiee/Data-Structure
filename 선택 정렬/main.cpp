#include <iostream>
#include "SelectionSorter.h"
#include "TimeMsr.h"

using namespace std;
#define endl "\n"

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    for (int i = 0; i < 10; i++) {
        SelectionSorter sorter(n);      // ��ü ����
        sorter.initRandom();            // �迭 �ʱ�ȭ
        cout << "Dataset " << i + 1 << " - Original: ";
        sorter.printArray("Original");

        TimeMsr timer;  // TimeMsr ��ü ����
        timer.measureExecutionTime([&]() {  // ���� ���� �ð� ����
            sorter.selectionSort(); 
        });

        sorter.printArray("Selection"); // ���� �� ���
        timer.printExecutionTime();     // ���� �ð� ���

        cout << endl;
    }

    return 0;
}

