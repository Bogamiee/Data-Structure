#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "edge.h"

using namespace std;


bool isSpanningTree(int nodes, const vector<Edge>& mst);
void printMST(const vector<Edge>& mst);

#endif // UTILS_H
