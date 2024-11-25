#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include "Edge.h"
using namespace std;


void bfs(int nodes, const vector<Edge>& graph, int startNode);
bool isSpanningTree(int nodes, const vector<int>& visitedNodes);

#endif // BFS_H
