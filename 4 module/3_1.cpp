/*Дано N кубиков. Требуется определить, каким количеством способов можно выстроить из этих кубиков пирамиду.
 *Каждый вышележащий слой пирамиды должен быть не больше нижележащего.
 *N ≤ 200.
 */
#include <iostream>
#include <vector>

long long array[201][201];

int main(){
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        array[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 1; k <= i && k <= j; ++k) {
                array[i][j] += array[i - k][k];
            }
        }
    }

    std::cout << array[n][n];
}
