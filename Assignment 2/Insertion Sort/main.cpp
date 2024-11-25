#include <iostream>
#include <thread>  // sleep_for 사용을 위한 헤더
#include <cstdlib>
#include <chrono>  // chrono 사용을 위한 헤더
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
        sorter.initRandom(rand());            // 배열 초기화
        cout << "Dataset " << i + 1 << " - Original: ";
        sorter.printArray("Original");

        TimeMsr timer;  // TimeMsr 객체 생성
        timer.measureExecutionTime([&]() {  // 선택 정렬 시간 측정
            sorter.selectionSort(); 
        });

        sorter.printArray("Selection"); // 정렬 후 출력
        timer.printExecutionTime();     // 실행 시간 출력

        cout << endl;

        // 잠시 멈추기 (예: 15초)
        std::this_thread::sleep_for(std::chrono::seconds(15));
    }

    return 0;
}

