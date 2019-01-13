#include <iostream>

int solve (int const *a, int key, int left, int right) {
    int mid = 0;
    while (left + 1 < right) {
        mid = left + (right - left)/2;

        if (a[mid] == key) {
            return mid;
        }

        if (a[mid] > key) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    if (a[left] < key) {
        return left;
    }

    return left;
}


int main() {
    int n,m;
    std::cin >> n >> m;

    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int* b = new int[m];
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    
    int left = 0;
    for (int i = 0; i < m; ++i) {
        int num = solve(a, b[i], left, n);
        if (b[i] == a[num]) {
            std::cout << b[i] << " ";
        }
        left = num;
    }
}
