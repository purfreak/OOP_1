#include <iostream>


int main() {
    int n;
    int gd;
    std:: cin >> n;

    for (int i = n-1; i >= 1; i--) {
        if (n % i == 0) {
            gd = i;
            break;
        }
    }

    std::cout << gd << " " << n - gd;
}
