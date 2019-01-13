#include <iostream>


int solve (int const *a, int key, int left, int right) {
    int mid = left + (right - left)/2;
    if (a[mid] < key) {
        return solve(a, key, mid + 1, right);
    }
    else if (a[mid] >= key && (a[mid - 1] < key || mid == 0)) {
        return mid;
    }
    else
        return solve(a, key, left, mid - 1);
}


int main() {
    int n, m;
    std::cin >> n >> m;

    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int* b = new int[m];
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    for (int i = 0; i < m; ++i) {
        if (b[i] <= a[n-1]) {
            std::cout << solve(a, b[i], 0, n - 1) << " ";
        }
        else {
            std::cout << n << " ";
        }
    }

    delete[] a;
    delete[] b;
}
