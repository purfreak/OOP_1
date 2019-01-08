#include <iostream>


int winner (int n, int k) {
    int person_index = 0;

    for (int i = 0; i < n; ++i) {
        person_index = (person_index + k) % (i + 1);
    }

    return ++person_index;
}


int main() {
    int n = 0;
    std::cin >> n;
    int k = 0;
    std::cin >> k;

    std::cout << winner (n,k);
}
