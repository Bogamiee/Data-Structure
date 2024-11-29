#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "Utils.h"

int main() {
    int nodes = 50; // ��� ��
    int edges = (nodes * (nodes - 1)) / 2 * 0.6; // ���� ���� 60% �̻�

    // �׷��� ����
    std::vector<Edge> graph = generateRandomGraph(nodes, edges);

    // �׷��� ���� ���
    printGraphInfo(nodes, edges);
    printGraph(graph);

    // BFS ����
    int startNode = 0; // ���� ���� 0���� ����
    bfs(nodes, graph, startNode);

    return 0;
}
