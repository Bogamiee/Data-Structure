#include <iostream>
#include <cstdlib>  // for rand
#include <ctime>    // for time
#include "InsertionSorter.h"

using namespace std;
#define endl "\n"

// ������: �迭 ũ�⸦ �޾Ƽ� �迭 ���� �Ҵ�
InsertionSorter::InsertionSorter(int n) : size(n) {
    list = new int[size];  // �迭 ���� �Ҵ�
    srand(static_cast<unsigned int>(time(nullptr)));  // ���� �õ� ����
}

// �Ҹ���: ���� �Ҵ��� �迭 ����
InsertionSorter::~InsertionSorter() {
    delete[] list;
}

// �迭�� �����ϰ� �ʱ�ȭ
void InsertionSorter::initRandom(int max) {
    for (int i = 0; i < size; i++) {
        list[i] = rand() % max;
    }
}

// �迭�� ���
void InsertionSorter::printArray(const char* str) const {
    cout << str << " = ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

// ���� ���� ����
void InsertionSorter::insertionSort() {
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int j = i - 1;

        // key���� ū ���ҵ��� ���������� �̵�
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;  // key�� �ùٸ� ��ġ�� ����
    }
}


