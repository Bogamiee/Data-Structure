#include <iostream>
#include <cstdlib>  // for rand
#include <ctime>    // for time
#include "BubbleSorter.h"

using namespace std;
#define endl "\n"

// ������: �迭 ũ�⸦ �޾Ƽ� �迭 ���� �Ҵ�
BubbleSorter::BubbleSorter(int n) : size(n) {
    list = new int[size];  // �迭 ���� �Ҵ�
    srand(static_cast<unsigned int>(time(nullptr)));  // ���� �õ� ����
}

// �Ҹ���: ���� �Ҵ��� �迭 ����
BubbleSorter::~BubbleSorter() {
    delete[] list;
}

// �迭�� �����ϰ� �ʱ�ȭ
void BubbleSorter::initRandom(int max) {
    for (int i = 0; i < size; i++) {
        list[i] = rand() % max;
    }
}

// �迭�� ���
void BubbleSorter::printArray(const char* str) const {
    cout << str << " = ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

// ���� ���� �Լ� ����
void BubbleSorter::BubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                // list[j]�� list[j + 1]�� swap
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}


