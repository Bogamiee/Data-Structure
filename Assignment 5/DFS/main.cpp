#include <iostream>
#include "Graph.h"
#include "DFS.h"
#include "Utils.h"

int main() {
    int nodes = 50; // 노드 수
    int edges = (nodes * (nodes - 1)) / 2 * 0.6; // 간선 수는 60% 이상

    // 그래프 생성
    std::vector<Edge> graph = generateRandomGraph(nodes, edges);

    // 그래프 정보 출력
    printGraphInfo(nodes, edges);
    printGraph(graph);

    // DFS 실행
    int startNode = 0; // 시작 노드는 0으로 설정
    dfs(nodes, graph, startNode);

    return 0;
}
