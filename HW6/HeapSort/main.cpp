#include "HeapSort.h"
#include "DataGen.h"
#include "TimeMsr.h" 
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void testHeapSort() {
    const int numDatasets = 10;
    const int minSize = 10000;
    const int maxSize = 1000000;

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < numDatasets; i++) {
        int dataSize = minSize + rand() % (maxSize - minSize + 1);
        vector<int> data = generateRandomData(dataSize);

        cout << "Dataset " << i + 1 << " (Size: " << dataSize << ") - Sorting..." << endl;

        // 시간 측정
        TimeMsr timer; // TimeMsr 객체 생성
        timer.measureExecutionTime([&]() { heapSort(data); }); // heapSort 실행 시간 측정
        timer.printExecutionTime(); // 측정된 시간 출력
    }
}

int main() {
    testHeapSort();
    return 0;
}
