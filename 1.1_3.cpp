#include <iostream>


int find_gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return find_gcd (b, a % b);
}


int main() {
    int a,b;
    int c,d;
    std:: cin >> a >> b >> c >> d;

    int m = a*d + b*c;
    int n = b*d;

    int gcd = find_gcd(m,n);
    std::cout << m/gcd << " " << n/gcd;
}
