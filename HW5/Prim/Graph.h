#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<int>> adjMatrix;

public:
    Graph(int nodes);
    void addEdge(int u, int v, int weight);
    int getNumNodes() const;
    const vector<vector<int>>& getAdjMatrix() const;
    bool isSpanningTree(const vector<int>& parent) const;
};

#endif // GRAPH_H
