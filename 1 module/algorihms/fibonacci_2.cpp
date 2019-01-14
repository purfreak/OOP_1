#include <iostream>

int fibonacci_2 (int n) {
    if (n == 0) {
        return 1;
    }

    int prev = 1;
    int curr = 1;

    for (int i = 2; i <= n; ++i) {
        int tmp = curr;
        curr += prev;
        prev = tmp;
    }

    return curr;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_2(n);
}
