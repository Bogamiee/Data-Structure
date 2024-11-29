#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);

#endif // QUICKSORT_H
