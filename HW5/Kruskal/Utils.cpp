#include "utils.h"
#include <iostream>
#include "union_find.h"
#define endl "\n"

using namespace std;

bool isSpanningTree(int nodes, const vector<Edge>& mst) {
    // nodes - 1을 size_t로 형변환하여 비교
    if (mst.size() != static_cast<size_t>(nodes - 1)) return false;

    UnionFind uf(nodes);
    for (const Edge& e : mst) {
        uf.unionSets(e.node1, e.node2);
    }

    // 모든 노드가 하나의 집합에 속하는지 확인
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
    cout << "선택된 노드와 경로:" << endl;
    for (const Edge& e : mst) {
        cout << "노드 " << e.node1 << " - 노드 " << e.node2 << " : 가중치 " << e.weight << endl;
        totalWeight += e.weight;
    }
    cout << "최소 경로 총 가중치: " << totalWeight << endl;
    cout << "노드 수: " << mst.size() + 1 << ", 간선 수: " << mst.size() << endl;
}
