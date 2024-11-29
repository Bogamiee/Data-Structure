#ifndef DFS_H
#define DFS_H

#include <vector>
#include "Edge.h"
using namespace std;

void dfs(int nodes, const vector<Edge>& graph, int startNode);
bool isSpanningTree(int nodes, const vector<int>& visitedNodes);

#endif // DFS_H
