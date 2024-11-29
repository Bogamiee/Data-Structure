#include "Graph.h"
#include <functional>
#include <limits>
using namespace std;

// 생성자
Graph::Graph(int nodes) : numNodes(nodes), adjMatrix(nodes, vector<int>(nodes, 0)) {}

// 간선 추가 함수
void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

// 노드 수 반환
int Graph::getNumNodes() const {
    return numNodes;
}

// 인접 행렬 반환
const vector<vector<int>>& Graph::getAdjMatrix() const {
    return adjMatrix;
}

// 스패닝 트리 여부 확인 함수
bool Graph::isSpanningTree(const vector<int>& parent) const {
    vector<bool> visited(numNodes, false);
    int count = 0;

    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        count++;
        for (int i = 0; i < numNodes; ++i) {
            if (adjMatrix[node][i] != 0 && !visited[i]) {
                dfs(i);
            }
        }
    };

    dfs(0);
    return count == numNodes;
}

