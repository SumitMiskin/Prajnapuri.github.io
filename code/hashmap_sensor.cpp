#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, float> sensorData;
    sensorData["pH"] = 6.5;
    sensorData["EC"] = 1.8;

    cout << "pH Level: " << sensorData["pH"] << endl;
    return 0;
}
