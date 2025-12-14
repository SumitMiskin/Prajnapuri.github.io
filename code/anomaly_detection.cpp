#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double values[] = {20, 21, 22, 100, 23};
    int n = 5;

    double mean = 0;
    for(int i = 0; i < n; i++) mean += values[i];
    mean /= n;

    double stdDev = 0;
    for(int i = 0; i < n; i++)
        stdDev += pow(values[i] - mean, 2);
    stdDev = sqrt(stdDev / n);

    for(int i = 0; i < n; i++) {
        double z = (values[i] - mean) / stdDev;
        if(fabs(z) > 2)
            cout << "Anomaly detected: " << values[i] << endl;
    }
    return 0;
}
