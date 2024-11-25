#include <iostream>
#include <cstdlib>  // for rand
#include <ctime>    // for time
#include "SelectionSorter.h"
using namespace std;
#define endl "\n"

// 생성자: 배열 크기를 받아서 배열 동적 할당
SelectionSorter::SelectionSorter(int n)
    : size(n)
{
    list = new int[size];  // 배열 동적 할당
    srand(static_cast<unsigned int>(time(nullptr)));  // 난수 시드 설정
}

// 소멸자: 동적 할당한 배열 해제
SelectionSorter::~SelectionSorter()
{
    delete[] list;
}

// 배열을 랜덤하게 초기화
void SelectionSorter::initRandom(int max)
{
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % max;
    }
}

// 배열을 출력
void SelectionSorter::printArray(const char* str) const
{
    cout << str << " = ";
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

// 선택 정렬 수행
void SelectionSorter::selectionSort()
{
    for (int i = 0; i < size - 1; i++)
    {
        int least = i;
        for (int j = i + 1; j < size; j++)
        {
            if (list[j] < list[least]) least = j;
        }
        // Swap using inline swap function
        int tmp = list[i];
        list[i] = list[least];
        list[least] = tmp;
    }
}
