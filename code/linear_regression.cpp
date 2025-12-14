#include <iostream>
using namespace std;

int main() {
    // Example data (temperature vs yield)
    int n = 5;
    double x[] = {20, 22, 25, 27, 30}; // temperature
    double y[] = {10, 12, 15, 17, 20}; // yield

    double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;

    for(int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXX += x[i] * x[i];
    }

    double m = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    double c = (sumY - m * sumX) / n;

    double futureTemp = 28;
    double predictedYield = m * futureTemp + c;

    cout << "Predicted Yield: " << predictedYield << endl;
    return 0;
}
