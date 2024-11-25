#include "Utils.h"
#include <iostream>
using namespace std;

void printGraph(const vector<Edge>& graph) {
    cout << "�׷����� ����: " << endl;
    for (const Edge& e : graph) {
        cout << "��� " << e.node1 << " - ��� " << e.node2 << " : ����ġ " << e.weight << endl;
    }
}

void printGraphInfo(int nodes, int edges) {
    cout << "��� ��: " << nodes << endl;
    cout << "���� ��: " << edges << endl;
}
