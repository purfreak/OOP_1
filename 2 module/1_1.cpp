#include <iostream>
#include <stdio.h>
#include <cstring>

int insertion_point (long long *boxes, int n, long long value) {
    long first = 0;
    long last = n;

    while (last > first) {
        long mid = first + (last - first)/2;
        if (boxes[mid] < value) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }

    return (int) last;
}

void insertion_sort (long long *boxes, int* boxes_indexes, int n) {
    for (int i = 1; i < n; ++i) {
        long long tmp = boxes[i];
        int tmp_index = boxes_indexes[i];
        int number = insertion_point(boxes, i, tmp);
        if (number != i && number != n - 1) {
            memmove(boxes + number + 1, boxes + number, sizeof(long long) * (i - number));
            boxes[number] = tmp;
            memmove(boxes_indexes + number + 1, boxes_indexes + number, sizeof(int) * (i - number));
            boxes_indexes[number] = tmp_index;
        }
    }
}


int main() {
    int n = 0;
    std::cin >> n;

    long long *boxes = new long long[n];
    int* boxes_indexes = new int[n];
    for (int i = 0; i < n; ++i) {
        boxes[i] = 1;
        for (int j = 0; j < 3; ++j) {
            int a = 0;
            std::cin >> a;
            boxes[i] *= a;
        }
        boxes_indexes[i] = i;
    }
    insertion_sort(boxes, boxes_indexes, n);

    for (int i = 0; i < n; ++i) {
        std::cout << boxes_indexes[i] << " ";
    }

    delete[] boxes;
    delete[] boxes_indexes;
}
