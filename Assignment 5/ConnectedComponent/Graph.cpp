#include "Graph.h"

Graph::Graph(int numNodes) 
: numNodes(numNodes) {
    adjList.resize(numNodes);
    visited.resize(numNodes, false);
}

Graph::~Graph() {
    adjList.clear();
    visited.clear();
}

void Graph::dfs(int node, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, component);
        }
    }
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::displayGraph() {
    for (int i = 0; i < numNodes; ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> Graph::findConnectedComponents() {
    vector<vector<int>> components;
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, component);
            components.push_back(component);
        }
    }
    return components;
}
