#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& priority, int low, int high) {
    int pivot = priority[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (priority[j] <= pivot) { i++; swap(priority[i], priority[j]); }
    }
    swap(priority[i + 1], priority[high]);
    return i + 1;
}
void quickSort(vector<int>& priority, int low, int high) {
    if (low < high) {
        int pi = partition(priority, low, high);
        quickSort(priority, low, pi - 1);
        quickSort(priority, pi + 1, high);
    }
}
int main() {
    vector<int> rideRequests = {15, 3, 10, 7, 1, 12};
    quickSort(rideRequests, 0, rideRequests.size() - 1);
    for (int p : rideRequests) cout << p << " ";
    return 0;
}
