#include "Utils.h"
#include <iostream>
using namespace std;

void printGraph(const vector<Edge>& graph) {
    cout << "그래프의 간선: " << endl;
    for (const Edge& e : graph) {
        cout << "노드 " << e.node1 << " - 노드 " << e.node2 << " : 가중치 " << e.weight << endl;
    }
}

void printGraphInfo(int nodes, int edges) {
    cout << "노드 수: " << nodes << endl;
    cout << "간선 수: " << edges << endl;
}
