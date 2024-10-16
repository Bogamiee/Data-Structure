#include <iostream>
#include <cstdlib>  // for rand
#include <ctime>    // for time
#include "InsertionSorter.h"

using namespace std;
#define endl "\n"

// 생성자: 배열 크기를 받아서 배열 동적 할당
InsertionSorter::InsertionSorter(int n) : size(n) {
    list = new int[size];  // 배열 동적 할당
    srand(static_cast<unsigned int>(time(nullptr)));  // 난수 시드 설정
}

// 소멸자: 동적 할당한 배열 해제
InsertionSorter::~InsertionSorter() {
    delete[] list;
}

// 배열을 랜덤하게 초기화
void InsertionSorter::initRandom(int max) {
    for (int i = 0; i < size; i++) {
        list[i] = rand() % max;
    }
}

// 배열을 출력
void InsertionSorter::printArray(const char* str) const {
    cout << str << " = ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

// 삽입 정렬 수행
void InsertionSorter::insertionSort() {
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int j = i - 1;

        // key보다 큰 원소들을 오른쪽으로 이동
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;  // key를 올바른 위치에 삽입
    }
}


