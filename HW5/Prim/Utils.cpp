#include "Utils.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Graph generateGraph(int nodes, double edgeDensity) {
    Graph graph(nodes);
    int totalEdges = (nodes * (nodes - 1) / 2) * edgeDensity;
    srand(time(nullptr));

    while (totalEdges > 0) {
        int u = rand() % nodes;
        int v = rand() % nodes;
        if (u != v && graph.getAdjMatrix()[u][v] == 0) {
            int weight = rand() % 100 + 1;
            graph.addEdge(u, v, weight);
            totalEdges--;
        }
    }

    return graph;
}
