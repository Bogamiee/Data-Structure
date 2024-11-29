#ifndef EDGE_H
#define EDGE_H

struct Edge {
    int weight, node1, node2;
    Edge(int w, int n1, int n2) : weight(w), node1(n1), node2(n2) {}
};

#endif // EDGE_H
