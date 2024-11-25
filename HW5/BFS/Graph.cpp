#include "Graph.h"
#include <cstdlib>
#include <ctime>
using namespace std;

vector<Edge> generateRandomGraph(int nodes, int edges) {
    vector<Edge> graph;
    srand(time(0));

    for (int i = 0; i < edges; i++) {
        int node1 = rand() % nodes;
        int node2 = rand() % nodes;
        int weight = rand() % 100 + 1; // 가중치: 1부터 100 사이
        if (node1 != node2) {
            graph.push_back(Edge(weight, node1, node2));
        }
    }

    return graph;
}
