#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
using namespace std;

void mergeSort(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int mid, int right);

#endif // MERGESORT_H
