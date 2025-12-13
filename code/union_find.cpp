#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findSet(int x) {
        if (parent[x] != x)
            parent[x] = findSet(parent[x]);
        return parent[x];
    }
    void unionSet(int a, int b) {
        int rootA = findSet(a);
        int rootB = findSet(b);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) parent[rootA] = rootB;
            else if (rank[rootA] > rank[rootB]) parent[rootB] = rootA;
            else { parent[rootB] = rootA; rank[rootA]++; }
        }
    }
};

int main() {
    int locations = 6;
    UnionFind uf(locations);
    uf.unionSet(0,1); uf.unionSet(1,2); uf.unionSet(3,4);
    if (uf.findSet(0) == uf.findSet(2)) cout << "Location 0 and 2 are in the same safe zone\n";
    if (uf.findSet(2) == uf.findSet(4)) cout << "Location 2 and 4 are in the same safe zone\n";
    return 0;
}
