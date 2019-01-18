#include <iostream>
#include <cstring>
#include <string>


bool operator < (std::string s1, std::string s2) {
        int i = 0;
        int min_size = std::min(s1.size(), s2.size());
        while (s1[i] == s2[i] && i < min_size) {
            i++;
        }
        if (i == min_size) {
            return s1.size() < s2.size();
        }

        return s2[i] > s1[i];
}

int insertion_point (const std::string *arr, int n, const std::string s) {
    int first = 0;
    int last = n;

    while (last > first) {
        long mid = (first + last)/2;
        if (arr[mid] < s) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }

    return last;
}

void insertion_sort (std::string *arr, int n) {
    for (int i = 1; i < n; i++) {
        std::string tmp = arr[i];
        int number = insertion_point(arr, i, tmp);
        if (number != i && number != n - 1) {
            int j = i - 1;
            for (; j >=0 && tmp < arr[j]; j--) {
                arr[j + 1] = arr[j];
            }

            arr[j + 1] = tmp;
        }
    }
}


int main() {
    int n = 0;
    std::cin >> n;

    auto *string_arr = new std::string[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> string_arr[i];
    }

    insertion_sort(string_arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << string_arr[i] << std::endl;
    }

    delete[] string_arr;
}
