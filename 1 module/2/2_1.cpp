#include <iostream>


void solve (int const* a, int const* b, int n, int a_max = 0, int b_max = 0) {
    int a_curr_max = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] > a[a_curr_max]) {
            a_curr_max = i;
        }
        if (a[a_curr_max] + b[i] > a[a_max] + b[b_max]) {
            a_max = a_curr_max;
            b_max = i;
        }
    }

    std::cout << a_max << " " << b_max;
}


int main() {
    int n;
    std::cin >> n;

    int* a = new int[n];
    int* b = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    solve (a, b, n);

    delete[] a;
    delete[] b;
}
