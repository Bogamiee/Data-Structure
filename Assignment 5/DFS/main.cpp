#include <iostream>
#include "Graph.h"
#include "DFS.h"
#include "Utils.h"

int main() {
    int nodes = 50; // ��� ��
    int edges = (nodes * (nodes - 1)) / 2 * 0.6; // ���� ���� 60% �̻�

    // �׷��� ����
    std::vector<Edge> graph = generateRandomGraph(nodes, edges);

    // �׷��� ���� ���
    printGraphInfo(nodes, edges);
    printGraph(graph);

    // DFS ����
    int startNode = 0; // ���� ���� 0���� ����
    dfs(nodes, graph, startNode);

    return 0;
}
