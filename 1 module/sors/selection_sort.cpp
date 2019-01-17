#include <iostream>

void selection_sort (int*a, int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }

        std::swap(a[i], a[min_index]);
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    int*a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    selection_sort(a, n);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}
