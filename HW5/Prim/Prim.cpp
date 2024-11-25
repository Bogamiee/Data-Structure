#include "Prim.h"
#include <queue>
#include <limits>
using namespace std;

pair<int, vector<int>> primMST(const Graph& graph) {
    int numNodes = graph.getNumNodes();
    const auto& adjMatrix = graph.getAdjMatrix();

    vector<int> parent(numNodes, -1);
    vector<int> key(numNodes, numeric_limits<int>::max());
    vector<bool> inMST(numNodes, false);
    int totalWeight = 0;

    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += weight;

        for (int v = 0; v < numNodes; ++v) {
            if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
                pq.emplace(key[v], v);
            }
        }
    }

    return {totalWeight, parent};
}
