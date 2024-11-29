#include "QuickSort.h"
using namespace std;

// ���� �Լ�
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // �ǹ� ���� (������ ���)
    int i = low - 1;       // �ǹ����� ���� ����� �� �ε���

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // �ǹ��� �ùٸ� ��ġ�� �̵�
    return i + 1; // �ǹ��� ���� ��ġ ��ȯ
}

// �� ���� �Լ�
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // ���� �� �ǹ� ��ġ ��ȯ

        quickSort(arr, low, pi - 1);  // ���� �κ� ����
        quickSort(arr, pi + 1, high); // ������ �κ� ����
    }
}
