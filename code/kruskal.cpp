#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

bool cmp(const Edge &a, const Edge &b) { return a.w < b.w; }

int find_set(int x, vector<int> &parent) {
    if (parent[x] != x) parent[x] = find_set(parent[x], parent);
    return parent[x];
}

void unite(int a, int b, vector<int> &parent) {
    parent[find_set(a, parent)] = find_set(b, parent);
}

int main() {
    // Example graph (3 nodes)
    vector<Edge> edges = {{0,1,4},{1,2,3},{0,2,5}};
    sort(edges.begin(), edges.end(), cmp);

    int n = 3; // number of nodes
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    int cost = 0;
    vector<Edge> mst;
    for (auto &e : edges) {
        if (find_set(e.u, parent) != find_set(e.v, parent)) {
            unite(e.u, e.v, parent);
            cost += e.w;
            mst.push_back(e);
        }
    }

    cout << "Minimum Infrastructure Cost = " << cost << '\n';
    cout << "Edges in MST:\n";
    for (auto &e : mst) cout << e.u << " - " << e.v << " (" << e.w << ")\n";
    return 0;
}
