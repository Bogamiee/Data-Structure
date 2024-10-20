#include <stdio.h>
#include <time.h>
#include <math.h>

#include "timer.h"

clock_t start, end;
double execTime;

void startTimer()
{
    start = clock();
}

void endTimer()
{
    end = clock();
    execTime = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
}

void printExecutionTime()
{
    double microseconds = execTime;
    double milliseconds = microseconds / 1000.0;
    double seconds = milliseconds / 1000.0;
    double minutes = seconds / 60.0;
    double hours = minutes / 60.0;

    printf("- %.0lf microseconds\n", microseconds);
    printf("- %.3lf milliseconds\n", milliseconds);
    printf("- %.3lf seconds\n", seconds);
    printf("- %d minutes %.3lf seconds\n", (int)minutes, fmod(seconds, 60.0));
    printf("- %d hours %d minutes %.3lf seconds\n", (int)hours, (int)fmod(minutes, 60.0), fmod(seconds, 60.0));
}
