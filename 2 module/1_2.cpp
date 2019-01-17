#include <iostream>
#include <cstring>

struct point {
    int x,y;
};

bool operator < (point point1, point point2) {
    if (point1.x < point2.x) {
        return true;
    } else if ((point1.x == point2.x) && (point1.y < point2.y)) {
        return true;
    }
    return false;
}


int insertion_point (point *points, int n, point value) {
    int first = 0;
    int last = n;

    while (last > first) {
        long mid = (first + last)/2;
        if (points[mid] < value) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }

    return last;
}

void insertion_sort (point *points, int n) {
    for (int i = 1; i < n; i++) {
        point tmp = points[i];
        int number = insertion_point(points, i, tmp);
        if (number != i && number != n - 1) {
            int j = i - 1;
            for (; j >=0 && (tmp < points[j]); j--) {
                points[j + 1] = points[j];
            }

            points[j + 1] = tmp;
        }
    }
}


int main() {
    int n = 0;
    std::cin >> n;

    point *points = new point[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    insertion_sort(points, n);

    for (int i = 0; i < n; ++i) {
        std::cout << points[i].x << " " << points[i].y << std::endl;
    }

    delete[] points;
}
