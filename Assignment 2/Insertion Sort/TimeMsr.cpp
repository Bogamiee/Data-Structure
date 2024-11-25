#include "TimeMsr.h"
#define endl "\n"

TimeMsr::TimeMsr() {
    exec_time = chrono::duration<long double, micro>(0);
}

void TimeMsr::measureExecutionTime(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    exec_time = end - start;
}

void TimeMsr::printExecutionTime() {
    long double microseconds = exec_time.count();
    long double milliseconds = microseconds / 1000.0;
    long double seconds = milliseconds / 1000.0;
    long double minutes = seconds / 60.0;
    long double hours = minutes / 60.0;

    cout << "\nExecution time:" << endl;
    cout << "- " << microseconds << " microseconds" << endl;
    cout << "- " << milliseconds << " milliseconds" << endl;
    cout << "- " << seconds << " seconds" << endl;
    cout << "- " << static_cast<int>(minutes) << " minutes "
         << fmod(seconds, 60.0) << " seconds" << endl;
    cout << "- " << static_cast<int>(hours) << " hours "
         << static_cast<int>(fmod(minutes, 60.0)) << " minutes "
         << fmod(seconds, 60.0) << " seconds" << endl;
}

TimeMsr::~TimeMsr() {}
