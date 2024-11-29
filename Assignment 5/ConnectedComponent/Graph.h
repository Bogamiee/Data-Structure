#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

class Graph {
    private:
        int numNodes;
        vector<vector<int>> adjList;
        vector<bool> visited;
        void dfs(int node, vector<int>& component);
    public:
        Graph(int numNodes);
        ~Graph();
        void addEdge(int u, int v);
        void displayGraph();
        vector<vector<int>> findConnectedComponents();
};

#endif
