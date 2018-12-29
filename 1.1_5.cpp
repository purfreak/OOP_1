#include <iostream>


void pow (int n) {
    int pow = 0;
    int prev = 0;
    for (int i = 0; i < n; i++ ) {
        pow = prev + i + i + 1;
        prev = pow;
        std::cout << pow << " ";
    }
}


int main() {
    int n;
    std::cin >> n;
    pow(n);
}
