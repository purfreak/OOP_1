#include <iostream>


int solve (int const *a, int key, int n) {
    int pow = 1;
    while (a[pow] <= key && pow < n) {
        pow = std::min (pow*2, n);
    }

    int left = pow/2;
    int right = pow;
    int mid = 0;
    
    while (left < right) {
        mid = left + (right - left)/2;

        if (a[mid] == key) {
            return mid;
        }

        if (left == right - 1) {
            if (abs(key - a[left]) <= abs(a[right] - key)) {
                return mid;
            }
            return mid + 1;
        }

        if (a[mid] > key) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    return left;
}


int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;
    int* b = new int[m];
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    for (int i = 0; i < m; ++i) {
        int res = solve (a, b[i], n);
        std::cout << res << " ";
    }

    delete[] a;
    delete[] b;
}
