#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n);
    int find(int x);
    bool unionSets(int x, int y);
};

#endif // UNION_FIND_H
