#include "MergeSort.h"
#include "DataGen.h"
#include "TimeMsr.h"
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void testMergeSort() {
    const int numDatasets = 10;
    const int minSize = 10000;
    const int maxSize = 1000000;

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < numDatasets; i++) {
        int dataSize = minSize + rand() % (maxSize - minSize + 1);
        vector<int> data = generateRandomData(dataSize);

        cout << "Dataset " << i + 1 << " (Size: " << dataSize << ") - Sorting..." << endl;

        // 시간 측정
        TimeMsr timer;
        timer.measureExecutionTime([&]() { mergeSort(data, 0, data.size() - 1); });
        timer.printExecutionTime();
    }
}

int main() {
    testMergeSort();
    return 0;
}
