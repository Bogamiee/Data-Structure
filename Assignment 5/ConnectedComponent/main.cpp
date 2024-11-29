#include "Graph.h"

Graph generateDenseGraph(int numNodes);

int main() {
    int numNodes;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    Graph g = generateDenseGraph(numNodes);

    cout << "Graph:" << endl;
    g.displayGraph();

    vector<vector<int>> components = g.findConnectedComponents();

    cout << "Connected components:" << endl;
    for (int i = 0; i < components.size(); ++i) {
        cout << "Component " << i + 1 << ": ";
        for (int node : components[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}

Graph generateDenseGraph(int numNodes) {
    int maxEdges = numNodes * (numNodes - 1) / 2;
    int numEdges = maxEdges * 0.6;
    set<pair<int, int>> edges;

    srand(time(0));

    while (edges.size() < numEdges) {
        int u = rand() % numNodes;
        int v = rand() % numNodes;
        if (u != v) {
            if (u > v) {
                swap(u, v);
            }
            edges.insert({u, v});
        }
    }

    Graph g(numNodes);
    for (auto edge : edges) {
        g.addEdge(edge.first, edge.second);
    }

    return g;
}
