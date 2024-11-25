#include "DFS.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void dfsUtil(int node, const unordered_map<int, unordered_set<int>>& adjList, 
             vector<bool>& visited, vector<int>& visitedNodes) {
    visited[node] = true;
    visitedNodes.push_back(node);
    cout << node << " ";

    for (int neighbor : adjList.at(node)) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adjList, visited, visitedNodes);
        }
    }
}

void dfs(int nodes, const vector<Edge>& graph, int startNode) {
    // 그래프를 인접 리스트로 변환
    unordered_map<int, unordered_set<int>> adjList;
    for (const Edge& e : graph) {
        adjList[e.node1].insert(e.node2);
        adjList[e.node2].insert(e.node1); // 무방향 그래프
    }

    vector<bool> visited(nodes, false);
    vector<int> visitedNodes;

    cout << "DFS 탐색 순서: ";
    dfsUtil(startNode, adjList, visited, visitedNodes);
    cout << endl;

    // 스패닝 트리 판단
    if (isSpanningTree(nodes, visitedNodes)) {
        cout << "스패닝 트리입니다." << endl;
    } else {
        cout << "스패닝 트리가 아닙니다." << endl;
    }
}

bool isSpanningTree(int nodes, const std::vector<int>& visitedNodes) {
    return visitedNodes.size() == static_cast<size_t>(nodes);
}
