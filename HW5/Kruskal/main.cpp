#include <iostream>
#include "graph.h"
#include "kruskal.h"
#include "utils.h"

using namespace std;

int main() {
    int nodes = 50; // ��� ��
    int edges = (nodes * (nodes - 1)) / 2 * 0.6; // ���� ���� 60% �̻�

    // �׷��� ����
    vector<Edge> graph = generateRandomGraph(nodes, edges);

    // Kruskal �˰��� ����
    vector<Edge> mst = kruskal(nodes, graph);

    // ���д� Ʈ������ Ȯ��
    if (isSpanningTree(nodes, mst)) {
        cout << "�ּ� ���д� Ʈ�� ����!" << endl;
        printMST(mst);
    } else {
        cout << "���д� Ʈ���� �ƴմϴ�." << endl;
    }

    return 0;
}
