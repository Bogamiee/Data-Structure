#include "kruskal.h"
#include <algorithm>

using namespace std;

vector<Edge> kruskal(int nodes, vector<Edge>& graph) {
    UnionFind uf(nodes);
    vector<Edge> mst;

    // �������� ����ġ ������ ����
    sort(graph.begin(), graph.end(), [](Edge& e1, Edge& e2) {
        return e1.weight < e2.weight;
    });

    // ���� ����
    for (Edge& e : graph) {
        if (uf.unionSets(e.node1, e.node2)) {
            mst.push_back(e);
        }
    }

    return mst;
}
