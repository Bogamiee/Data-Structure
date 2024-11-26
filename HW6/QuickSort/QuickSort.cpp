#include "QuickSort.h"
using namespace std;

// 분할 함수
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 피벗 선택 (마지막 요소)
    int i = low - 1;       // 피벗보다 작은 요소의 끝 인덱스

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // 피벗을 올바른 위치로 이동
    return i + 1; // 피벗의 최종 위치 반환
}

// 퀵 정렬 함수
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 분할 후 피벗 위치 반환

        quickSort(arr, low, pi - 1);  // 왼쪽 부분 정렬
        quickSort(arr, pi + 1, high); // 오른쪽 부분 정렬
    }
}
