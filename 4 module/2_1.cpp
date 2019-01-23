#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<long> mass, power;
    long m;
    while (std::cin >> m) {
        long p;
        std::cin >> p;
        mass.push_back(m);
        power.push_back(p);
    }

    sort(mass.begin(), mass.end());
    sort(power.begin(), power.end());

    long curMass = mass[0], curHeight = 1;

    for (unsigned i = 1; i < mass.size(); i++) {
        if (power[i] >= curMass) {
            curMass += mass[i];
            curHeight++;
        }
    }

    std::cout << curHeight;
}
