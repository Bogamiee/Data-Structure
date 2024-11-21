#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void quickSort(Node nodes[], int low, int high);
int partition(Node nodes[], int low, int high);
void swap(Node *a, Node *b);

#endif
