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

        // �ð� ����
        TimeMsr timer; // TimeMsr ��ü ����
        timer.measureExecutionTime([&]() { heapSort(data); }); // heapSort ���� �ð� ����
        timer.printExecutionTime(); // ������ �ð� ���
    }
}

int main() {
    testHeapSort();
    return 0;
}
