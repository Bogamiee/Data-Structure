#include "TimeMsr.h"

TimeMsr::TimeMsr() {
    exec_time = chrono::duration<long double, std::micro>(0);
}

void TimeMsr::measureExecutionTime(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func(); // 전달된 함수 실행
    auto end = chrono::high_resolution_clock::now();
    exec_time = end - start; // 실행 시간 계산
}

void TimeMsr::printExecutionTime() {
    long double microseconds = exec_time.count();
    long double milliseconds = microseconds / 1000.0;
    long double seconds = milliseconds / 1000.0;

    cout << "Execution time:" << endl;
    cout << "- " << microseconds << " microseconds" << endl;
    cout << "- " << milliseconds << " milliseconds" << endl;
    cout << "- " << seconds << " seconds\n" << endl;
}

TimeMsr::~TimeMsr() {}
