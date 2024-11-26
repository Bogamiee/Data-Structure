#include <iostream>
#include <cstdlib>  // for rand
#include <ctime>    // for time
#include "SelectionSorter.h"
using namespace std;
#define endl "\n"

// ������: �迭 ũ�⸦ �޾Ƽ� �迭 ���� �Ҵ�
SelectionSorter::SelectionSorter(int n)
    : size(n)
{
    list = new int[size];  // �迭 ���� �Ҵ�
    srand(static_cast<unsigned int>(time(nullptr)));  // ���� �õ� ����
}

// �Ҹ���: ���� �Ҵ��� �迭 ����
SelectionSorter::~SelectionSorter()
{
    delete[] list;
}

// �迭�� �����ϰ� �ʱ�ȭ
void SelectionSorter::initRandom(int max)
{
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % max;
    }
}

// �迭�� ���
void SelectionSorter::printArray(const char* str) const
{
    cout << str << " = ";
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

// ���� ���� ����
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
