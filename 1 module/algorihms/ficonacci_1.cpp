#include <iostream>

int fibonacci_1 (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return fibonacci_1(n - 1) + fibonacci_1(n - 2);
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_1(n);
}
