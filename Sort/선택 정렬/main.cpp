#include <iostream>
#include <thread>  // sleep_for ����� ���� ���
#include <cstdlib>
#include <chrono>  // chrono ����� ���� ���
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
        sorter.initRandom(rand());            // �迭 �ʱ�ȭ
        cout << "Dataset " << i + 1 << " - Original: ";
        sorter.printArray("Original");

        TimeMsr timer;  // TimeMsr ��ü ����
        timer.measureExecutionTime([&]() {  // ���� ���� �ð� ����
            sorter.selectionSort(); 
        });

        sorter.printArray("Selection"); // ���� �� ���
        timer.printExecutionTime();     // ���� �ð� ���

        cout << endl;

        // ��� ���߱� (��: 15��)
        std::this_thread::sleep_for(std::chrono::seconds(15));
    }

    return 0;
}

