#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int waterLevel[] = {40, 10, 30, 20};
    int n = 4;

    sort(waterLevel, waterLevel + n);

    cout << "Irrigation Order: ";
    for(int i = 0; i < n; i++)
        cout << waterLevel[i] << " ";

    cout << endl;
    return 0;
}
