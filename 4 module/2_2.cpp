/*В большой IT-фирме есть только одна переговорная комната.
 * Желающие посовещаться заполняют заявки с желаемым временем начала и конца. 
 *Ваша задача определить максимальное количество заявок, которое может быть удовлетворено.
 * Число заявок ≤ 100000.*/
#include <iostream>
#include <vector>
#include <algorithm>


//стуктура, в которой будет храниться начало заявки и ее конец
struct claim {
    int start = 0;
    int end = 0;
};


//функция для сравнения структур
bool comparison (claim claim1, claim claim2) {
    if (claim1.end != claim2.end) {
        return claim1.end < claim2.end;
    }
    else {
        return claim1.start < claim2.start;
    }
}


int main() {
    std::vector<claim> vec;
    int num1;
    while (std::cin >> num1) {
        int num2;
        std::cin >> num2;
        claim temp;
        temp.start = num1;
        temp.end = num2;
        vec.push_back(temp);
    }

    //сортируем вектор по возрастанию конца заявки
    std::sort(vec.begin(), vec.end(), comparison);

    int count_claims = 0;
    int point = 0;
    int last_beginning = 0;

    for (int i = last_beginning; i <= vec.size() - 1; i++) {
        if (vec[i].end > point && vec[i].start >= point) {
            count_claims++;
            point = vec[i].end;
            last_beginning = i;
        }
    }

    std::cout << std::endl << count_claims;


    return 0;
}
