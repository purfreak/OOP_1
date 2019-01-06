#include <iostream>
#include <math.h>


bool is_prime (int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


void find_dividers (int number_to_divide, int next_divisor) {
    for (int i = next_divisor; i <= number_to_divide; ) {
        while (number_to_divide % i == 0 && is_prime(i)) {
                std::cout << i << " ";
                number_to_divide /= i;
        }

        find_dividers(number_to_divide, i+1);
        break;
    }
}


int main() {
    int n;
    std::cin >> n;
    find_dividers(n, 2);
}
