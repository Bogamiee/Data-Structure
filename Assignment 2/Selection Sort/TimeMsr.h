#ifndef TIMEMSR_H
#define TIMEMSR_H

#include <chrono>
#include <iostream>
#include <functional>

class TimeMsr {
private:
    std::chrono::duration<long double, std::micro> exec_time; // 실행 시간

public:
    TimeMsr(); // 생성자
    void measureExecutionTime(std::function<void()> func); // 실행 시간 측정
    void printExecutionTime(); // 실행 시간 출력
    ~TimeMsr(); // 소멸자
};

#endif // TIMEMSR_H
