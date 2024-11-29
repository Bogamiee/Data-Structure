#include "BFS.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


void bfs(int nodes, const vector<Edge>& graph, int startNode) {
    // 그래프를 인접 리스트로 변환
    unordered_map<int, unordered_set<int>> adjList;
    for (const Edge& e : graph) {
        adjList[e.node1].insert(e.node2);
        adjList[e.node2].insert(e.node1); // 무방향 그래프
    }

    vector<bool> visited(nodes, false);
    queue<int> q;
    vector<int> visitedNodes;
    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS 탐색 순서: ";
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visitedNodes.push_back(node);
        cout << node << " ";
        
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
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

