#include <iostream>
#include <cstdlib>
using namespace std;

int fitness(int nutrient) {
    return nutrient * nutrient; // example fitness function
}

int main() {
    int population[5] = {2, 5, 8, 3, 6};

    int best = population[0];
    for(int i = 1; i < 5; i++) {
        if(fitness(population[i]) > fitness(best))
            best = population[i];
    }

    cout << "Best Nutrient Value: " << best << endl;
    return 0;
}
