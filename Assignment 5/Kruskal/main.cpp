#include <iostream>
#include "graph.h"
#include "kruskal.h"
#include "utils.h"

using namespace std;

int main() {
    int nodes = 50; // 노드 수
    int edges = (nodes * (nodes - 1)) / 2 * 0.6; // 간선 수는 60% 이상

    // 그래프 생성
    vector<Edge> graph = generateRandomGraph(nodes, edges);

    // Kruskal 알고리즘 실행
    vector<Edge> mst = kruskal(nodes, graph);

    // 스패닝 트리인지 확인
    if (isSpanningTree(nodes, mst)) {
        cout << "최소 스패닝 트리 성공!" << endl;
        printMST(mst);
    } else {
        cout << "스패닝 트리가 아닙니다." << endl;
    }

    return 0;
}
