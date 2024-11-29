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
    // �׷����� ���� ����Ʈ�� ��ȯ
    unordered_map<int, unordered_set<int>> adjList;
    for (const Edge& e : graph) {
        adjList[e.node1].insert(e.node2);
        adjList[e.node2].insert(e.node1); // ������ �׷���
    }

    vector<bool> visited(nodes, false);
    vector<int> visitedNodes;

    cout << "DFS Ž�� ����: ";
    dfsUtil(startNode, adjList, visited, visitedNodes);
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
