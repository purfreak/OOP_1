#include <iostream>


int solve (int const *a, int left, int right) {
    int mid = 0;
    while (left + 1 < right) {
        mid = left + (right - left)/2;
        if (a[mid] > a[mid - 1]) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    if (a[mid - 1] < a[mid]) {
        left = mid;
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

    std::cout << solve(a, 0, n);

    delete[] a;

}
