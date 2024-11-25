#include "utils.h"
#include <iostream>
#include "union_find.h"
#define endl "\n"

using namespace std;

bool isSpanningTree(int nodes, const vector<Edge>& mst) {
    // nodes - 1�� size_t�� ����ȯ�Ͽ� ��
    if (mst.size() != static_cast<size_t>(nodes - 1)) return false;

    UnionFind uf(nodes);
    for (const Edge& e : mst) {
        uf.unionSets(e.node1, e.node2);
    }

    // ��� ��尡 �ϳ��� ���տ� ���ϴ��� Ȯ��
    int root = uf.find(0);
    for (int i = 1; i < nodes; i++) {
        if (uf.find(i) != root) {
            return false;
        }
    }
    return true;
}

void printMST(const vector<Edge>& mst) {
    int totalWeight = 0;
    cout << "���õ� ���� ���:" << endl;
    for (const Edge& e : mst) {
        cout << "��� " << e.node1 << " - ��� " << e.node2 << " : ����ġ " << e.weight << endl;
        totalWeight += e.weight;
    }
    cout << "�ּ� ��� �� ����ġ: " << totalWeight << endl;
    cout << "��� ��: " << mst.size() + 1 << ", ���� ��: " << mst.size() << endl;
}
