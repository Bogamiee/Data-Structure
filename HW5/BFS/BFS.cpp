#include "BFS.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


void bfs(int nodes, const vector<Edge>& graph, int startNode) {
    // �׷����� ���� ����Ʈ�� ��ȯ
    unordered_map<int, unordered_set<int>> adjList;
    for (const Edge& e : graph) {
        adjList[e.node1].insert(e.node2);
        adjList[e.node2].insert(e.node1); // ������ �׷���
    }

    vector<bool> visited(nodes, false);
    queue<int> q;
    vector<int> visitedNodes;
    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Ž�� ����: ";
    
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
    
    // ���д� Ʈ�� �Ǵ�
    if (isSpanningTree(nodes, visitedNodes)) {
        cout << "���д� Ʈ���Դϴ�." << endl;
    } else {
        cout << "���д� Ʈ���� �ƴմϴ�." << endl;
    }
}

bool isSpanningTree(int nodes, const std::vector<int>& visitedNodes) {
    return visitedNodes.size() == static_cast<size_t>(nodes);
}

