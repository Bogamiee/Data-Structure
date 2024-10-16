#ifndef TIMEMSR_H
#define TIMEMSR_H

#include <chrono>
#include <iostream>
#include <functional>
using namespace std;

class TimeMsr {
    private:
        chrono::duration<long double, micro> exec_time;
    public:
        TimeMsr(); // Constructor
        ~TimeMsr(); // Destructor
        void measureExecutionTime(function<void()> func);
        void printExecutionTime();
};

#endif
