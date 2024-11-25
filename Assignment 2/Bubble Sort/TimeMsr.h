#ifndef TIMEMSR_H
#define TIMEMSR_H

#include <iostream>
#include <chrono>
#include <functional>

using namespace std;

class TimeMsr {
private:
    chrono::duration<long double, std::micro> exec_time;  // 실행 시간 저장

public:
    TimeMsr();  // 생성자
    ~TimeMsr(); // 소멸자

    void measureExecutionTime(function<void()> func);  // 실행 시간 측정 함수
    void printExecutionTime();  // 실행 시간 출력 함수
};

#endif // TIMEMSR_H
