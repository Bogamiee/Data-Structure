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
        SelectionSorter sorter(n);      // 객체 생성
        sorter.initRandom();            // 배열 초기화
        cout << "Dataset " << i + 1 << " - Original: ";
        sorter.printArray("Original");

        TimeMsr timer;  // TimeMsr 객체 생성
        timer.measureExecutionTime([&]() {  // 선택 정렬 시간 측정
            sorter.selectionSort(); 
        });

        sorter.printArray("Selection"); // 정렬 후 출력
        timer.printExecutionTime();     // 실행 시간 출력

        cout << endl;
    }

    return 0;
}

