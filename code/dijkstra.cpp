#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm to find safest route
// Nodes -> locations
// Edges -> roads
// Weights -> risk level (crime, poor lighting, isolation)

vector<int> dijkstra(int source, vector<vector<pair<int,int>>> &graph) {
    int V = graph.size();
    vector<int> distance(V, INT_MAX);

    // Min-heap priority queue (risk, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentRisk = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentRisk > distance[u])
            continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int risk = edge.second;

            if (distance[u] + risk < distance[v]) {
                distance[v] = distance[u] + risk;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

int main() {
    int V = 5; // number of locations
    vector<vector<pair<int,int>>> graph(V);

    // Adding roads (u, v, risk)
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 1});

    int source = 0;
    vector<int> safestRoute = dijkstra(source, graph);

    cout << "Safest risk level from source location:\n";
    for (int i = 0; i < V; i++) {
        cout << "To location " << i << " = " << safestRoute[i] << endl;
    }

    return 0;
}
