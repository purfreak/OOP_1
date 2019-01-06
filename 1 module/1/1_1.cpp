#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ans = 0;

    for (int i = 5; i <=n; i += 5) {
        int tmp = i;
        while ((tmp % 5 == 0) && (tmp != 0)) {
            ans++;
            tmp /= 5;
        }
    }

    std::cout << ans;
}
