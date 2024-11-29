#include "Graph.h"
#include <functional>
#include <limits>
using namespace std;

// ������
Graph::Graph(int nodes) : numNodes(nodes), adjMatrix(nodes, vector<int>(nodes, 0)) {}

// ���� �߰� �Լ�
void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

// ��� �� ��ȯ
int Graph::getNumNodes() const {
    return numNodes;
}

// ���� ��� ��ȯ
const vector<vector<int>>& Graph::getAdjMatrix() const {
    return adjMatrix;
}

// ���д� Ʈ�� ���� Ȯ�� �Լ�
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

