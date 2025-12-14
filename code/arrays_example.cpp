#include <iostream>
using namespace std;

int main() {
    int temperature[5] = {24, 25, 26, 27, 28};

    for(int i = 0; i < 5; i++)
        cout << "Temp: " << temperature[i] << endl;

    return 0;
}
