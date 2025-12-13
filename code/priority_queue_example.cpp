#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> emergencyRequests;
    emergencyRequests.push(5); emergencyRequests.push(20); emergencyRequests.push(10); emergencyRequests.push(30);
    while (!emergencyRequests.empty()) {
        cout << "Serving request with priority: " << emergencyRequests.top() << endl;
        emergencyRequests.pop();
    }
    return 0;
}
