#ifndef TIMEMSR_H
#define TIMEMSR_H

#include <iostream>
#include <chrono>
#include <functional>
#include <cmath>

using namespace std;

class TimeMsr {
private:
    chrono::duration<long double, micro> exec_time;  // ���� �ð� ����

public:
    TimeMsr();  // ������
    ~TimeMsr(); // �Ҹ���

    void measureExecutionTime(function<void()> func);  // ���� �ð� ���� �Լ�
    void printExecutionTime();  // ���� �ð� ��� �Լ�
};

#endif // TIMEMSR_H
