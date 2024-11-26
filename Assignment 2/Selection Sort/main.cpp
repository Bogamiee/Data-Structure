#include <iostream>
#include <thread>  // sleep_for ����� ���� ���
#include <cstdlib>
#include <chrono>  // chrono ����� ���� ���
#include "InsertionSorter.h"
#include "TimeMsr.h"

using namespace std;

int main() 
{

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    for (int i = 0; i < 10; i++) {
    InsertionSorter sorter(n);  // ��ü ����
    sorter.initRandom(rand());     // �迭 �ʱ�ȭ
    cout << "Original: ";
    sorter.printArray("Original");

    TimeMsr timer; // TimeMsr ��ü ����
    timer.measureExecutionTime([&]() { // ���� �ð� ����
    sorter.insertionSort();   // ���� ���� ����
    });

    sorter.printArray("Sorted");    // ���� �� ���
    timer.printExecutionTime();   // ���� �ð� ���

    // ��� ���߱� (��: 15��)
    std::this_thread::sleep_for(std::chrono::seconds(15));
    }
    return 0;
}

