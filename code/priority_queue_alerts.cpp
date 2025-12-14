#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> alerts;

    alerts.push(2); // medium
    alerts.push(5); // critical
    alerts.push(1); // low

    cout << "Highest Priority Alert: " << alerts.top() << endl;
    return 0;
}
