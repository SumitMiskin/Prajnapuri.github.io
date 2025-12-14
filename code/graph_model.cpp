#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> graph[3];

    graph[0].push_back(1); // Pump → Water Flow
    graph[1].push_back(2); // Water Flow → Plant Growth

    cout << "System Dependencies Created" << endl;
    return 0;
}
