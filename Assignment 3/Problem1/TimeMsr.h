#ifndef TIMEMSR_H
#define TIMEMSR_H

#include <chrono>
#include <iostream>
#include <functional>

class TimeMsr {
private:
    std::chrono::duration<long double, std::micro> exec_time; // ���� �ð�

public:
    TimeMsr(); // ������
    void measureExecutionTime(std::function<void()> func); // ���� �ð� ����
    void printExecutionTime(); // ���� �ð� ���
    ~TimeMsr(); // �Ҹ���
};

#endif // TIMEMSR_H
