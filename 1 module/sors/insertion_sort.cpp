#include <iostream>

void insertion_sort (int*a, int n) {
    for (int i = 0; i < n; ++i) {
        int tmp = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > tmp; --j) {
            a[j + 1] = a[j];
        }

        a[j + 1] = tmp;
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    int*a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    insertion_sort(a, n);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}
