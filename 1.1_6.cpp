#include <iostream>


void swap (int* arr, int n) {
    for (int i = 0; i < n/2; i++) {
        int tmp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = tmp;
    }
}


int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    swap(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}
