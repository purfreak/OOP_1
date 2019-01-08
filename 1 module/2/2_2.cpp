#include <iostream>


int solve (int n, int *a, int m, int *b, int k) {
    int last_j = 0;
    int ans = 0;
    
    for (int i = m - 1; i >= 0; i--) {
        int curr_b = b[i];
        
        for (int j = last_j; j < n; j++) {
            int sum = curr_b + a[j];
            if (sum == k) {
                ans++;
            }
            else if (sum > k) {
                last_j = j;
                break;
            }
        }
    }
    return ans;
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
    for (int j = 0; j < m; ++j) {
        std::cin >> b[j];
    }

    int k;
    std::cin >> k;
    
    std::cout << solve (n, a, m, b, k);
}
