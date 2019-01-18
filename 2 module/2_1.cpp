#include <iostream>
#include <vector>

struct customer {
    int begin;
    int end;
    customer(int in, int out): begin(in), end(out) {};
};

bool operator <(customer first, customer second) {
    if (first.end < second.end) {
        return true;
    }
    else if (first.end == second.end) {
        return first.begin < second.begin;
    }
    return false;
}

void SiftDown(std::vector<customer> &arr, int index) {
    int left = 2*index + 1;
    int right = 2*index + 2;
    int largest = index;

    if (left < arr.size() && arr[index] < arr[left])
        largest = left;
    if (right < arr.size() && arr[largest] < arr[right])
        largest = right;

    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        SiftDown(arr, largest);
    }
}

void HeapSort(std::vector<customer>& arr) {

    for (int i = arr.size()/2 - 1; i >= 0; i--) {
        SiftDown(arr, i);
    }

    while (arr.size() > 1) {
        customer tmp = arr[0];
        std::swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        SiftDown(arr, 0);
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<customer> arr;

    for (int i = 0; i < n; i++) {
        int begin = 0, end = 0;
        std::cin >> begin >> end;

        customer tmp(begin, end);
        arr.push_back(tmp);
    }

    HeapSort(arr);

    int ads = 0;
    int first_border = -1;
    int second_border = -1;

    for (int i = 0; i < n; i++) {
        customer tmp = arr[i];

        if (tmp.begin > second_border) {
            ads += 2;
            first_border = tmp.end - 1;
            second_border = tmp.end;
        }
        else if (tmp.begin == second_border) {
            ads++;
            first_border = second_border;
            second_border = tmp.end;
        }
        else if (tmp.begin > first_border && tmp.end > second_border) {
            ads++;
            first_border = second_border;
            second_border = tmp.end;
        }
        else if (tmp.begin > first_border && tmp.begin < second_border) {
            ads++;
            first_border = tmp.end;
        }
    }
    std::cout << ads;
}
