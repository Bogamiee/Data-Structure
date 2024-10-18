#include <iostream>
#include <cstdlib>  // for rand
#include <ctime>    // for time
#include "BubbleSorter.h"

using namespace std;
#define endl "\n"

// 생성자: 배열 크기를 받아서 배열 동적 할당
BubbleSorter::BubbleSorter(int n) : size(n) {
    list = new int[size];  // 배열 동적 할당
    srand(static_cast<unsigned int>(time(nullptr)));  // 난수 시드 설정
}

// 소멸자: 동적 할당한 배열 해제
BubbleSorter::~BubbleSorter() {
    delete[] list;
}

// 배열을 랜덤하게 초기화
void BubbleSorter::initRandom(int max) {
    for (int i = 0; i < size; i++) {
        list[i] = rand() % max;
    }
}

// 배열을 출력
void BubbleSorter::printArray(const char* str) const {
    cout << str << " = ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

// 버블 정렬 함수 수정
void BubbleSorter::BubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                // list[j]와 list[j + 1]을 swap
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}


