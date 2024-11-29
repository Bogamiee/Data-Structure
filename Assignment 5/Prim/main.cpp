#include <iostream>
#include "Graph.h"
#include "Prim.h"
#include "Utils.h"

using namespace std;

int main() {
    const int numNodes = 50;
    const double edgeDensity = 0.6;
    Graph graph = generateGraph(numNodes, edgeDensity);

    auto [totalWeight, parent] = primMST(graph);

    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (int i = 1; i < numNodes; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " (Weight: " << graph.getAdjMatrix()[parent[i]][i] << ")\n";
        }
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";

    if (graph.isSpanningTree(parent)) {
        cout << "The tree is a valid spanning tree.\n";
    } else {
        cout << "The tree is not a valid spanning tree.\n";
    }

    cout << "Number of Nodes: " << numNodes << "\n";
    cout << "Number of Edges: " << numNodes * (numNodes - 1) / 2 * edgeDensity << "\n";

    return 0;
}
