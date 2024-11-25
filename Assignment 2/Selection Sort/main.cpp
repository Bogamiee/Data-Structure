#include <iostream>
#include <thread>  // sleep_for 사용을 위한 헤더
#include <cstdlib>
#include <chrono>  // chrono 사용을 위한 헤더
#include "InsertionSorter.h"
#include "TimeMsr.h"

using namespace std;

int main() 
{

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    for (int i = 0; i < 10; i++) {
    InsertionSorter sorter(n);  // 객체 생성
    sorter.initRandom(rand());     // 배열 초기화
    cout << "Original: ";
    sorter.printArray("Original");

    TimeMsr timer; // TimeMsr 객체 생성
    timer.measureExecutionTime([&]() { // 실행 시간 측정
    sorter.insertionSort();   // 삽입 정렬 수행
    });

    sorter.printArray("Sorted");    // 정렬 후 출력
    timer.printExecutionTime();   // 실행 시간 출력

    // 잠시 멈추기 (예: 15초)
    std::this_thread::sleep_for(std::chrono::seconds(15));
    }
    return 0;
}

