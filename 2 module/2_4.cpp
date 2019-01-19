#include <iostream>
#include <vector>


struct point {
    int number;
    int state;

    point(int a, int b): number(a), state(b) {};
};

bool operator< (point p1, point p2) {
    if (p1.number < p2.number) {
        return true;
    } else if (p1.number == p2.number) {
        return p1.state < p2.state;
    }
}

void sift_down (std::vector<point> &points, int n, int index) {
    int left = 2*index + 1;
    int right = left + 1;
    int largest = index;

    if (left < n && points[index] < points[left]) {
        largest = left;
    }

    if (right < n && points[largest] < points[right]) {
        largest = right;
    }

    if (index != largest) {
        std::swap(points[largest], points[index]);
        sift_down(points, n, largest);
    }
}

void heap_sort (std::vector<point> &points, int n) {
    for (int i = n/2 - 1; i >= 0; --i) {
        sift_down(points, n , i);
    }

    while (n > 1) {
        std::swap(points[0], points[n - 1]);
        --n;
        sift_down(points, n, 0);
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    n *= 2;
    std::vector<point> points;
    
    for (int i = 0; i < n/2; ++i) {
        int a;

        std::cin >> a;
        point p1(a, 1);
        points.push_back(p1);

        std::cin >> a;
        point p2(a, -1);
        points.push_back(p2);
    }

    heap_sort(points, n);

    int retval = 0;
    int level = 1;
    for (int i = 1; i < n; ++i) {
        if (level == 1) {
            retval += points[i].number - points[i-1].number;
        }
        level += points[i].state;
    };

    std::cout << retval;
}
