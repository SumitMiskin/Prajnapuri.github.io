#include <iostream>
using namespace std;

int main() {
    double setPoint = 25;
    double currentTemp = 30;
    double Kp = 1.2;

    double error = setPoint - currentTemp;
    double controlSignal = Kp * error;

    cout << "Control Signal: " << controlSignal << endl;
    return 0;
}
