#include <iostream>

double pow (int a, int n) {
    double res = 1;
    double a_in_pow_2 = a;
    
    while (n > 0) {
        if (n % 2) {
            res *= a_in_pow_2;
        }
        
        a_in_pow_2 *= a_in_pow_2;
        n = n >> 1;
    }
    
    return res;
}

int main() {
    int a = 0;
    std::cin >> a;

    int n = 0;
    std::cin >> n;
    std::cout << pow(a, n);
}
