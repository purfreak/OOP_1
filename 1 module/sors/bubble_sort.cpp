#include <iostream>

void bubble_sort (int*a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swap_info = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swap_info = true;
            }
        }

        if (!swap_info) {
            return;
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    int*a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    bubble_sort(a, n);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}
