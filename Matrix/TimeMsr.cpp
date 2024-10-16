#include "TimeMsr.h"

TimeMsr::TimeMsr() {
    exec_time = chrono::duration<double, micro>(0);
}

void TimeMsr::measureExecutionTime(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    exec_time = end - start;
}

void TimeMsr::printExecutionTime() {
    cout << "\nExecution time: " + to_string(exec_time.count()) + " microseconds" << endl;
}

TimeMsr::~TimeMsr() {}
