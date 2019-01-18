#include <iostream>

struct date {
    int year = 0;
    int month = 0;
    int day = 0;
    int birth_or_death = 0;
};

struct person {
    date birth_date;
    date death_date;
};

bool operator< (date date1, date date2) {
    if (date1.year != date2.year) {
        return date1.year < date2.year;
    }
    else if (date1.month != date2.month) {
        return date1.month < date2.month;
    }
    else if (date1.day != date2.day) {
        return date1.day < date2.day;
    }
    else {
        return date1.birth_or_death < date2.birth_or_death;
    }
}

void buildMassiv(person* person, int n, date* massiv) {
    for (int i = 0; i < n; i++) {
        massiv[2 * i] = person[i].birth_date;
        massiv[2 * i + 1] = person[i].death_date;
        massiv[2 * i].year += 18;
        date age_18 = person[i].birth_date;
        date age_80 = person[i].birth_date;
        //чтобы учитывать только ту часть жизни человека, в течение которой он может принимать участие в собраниях
        age_18.year += 18;
        //чтобы сравнить дату смерти человека и дату его 80-летия
        age_80.year += 80;
        //это нужно для того, чтобы учесть случай, когда человек умирает в свой 80-й день рождения
        age_80.birth_or_death = -1;
        /*если человек умер после 80 лет, заменяем дату его смерти на дату 80-ого дня рождения,
        т.к. в данном случае для подсчета количества современников неважна дата его смерти,
          поскольку человек может принимать участие в собраниях только до 80-ти лет*/
        if (age_80 < person[i].death_date) {
            massiv[2 * i + 1] = age_80;
        }
        /*если человек умер до 18-летия, мы его не учитываем,
        т.к. он в любой день своей жизни не мог участвовать в собраниях*/
        if (!(age_18 < person[i].death_date)) {
            massiv[2 * i].birth_or_death = 0;
            massiv[2 * i + 1].birth_or_death = 0;
        }
    }
}

//функция для подсчета количества современников
//она работает по аналогии с подсчетом баланса скобочной последовательности
int countContemporary(date* massiv, int n) {
    int current = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        current += massiv[i].birth_or_death;
        if (current > max) {
            max = current;
        }
    }
    return max;
}

void siftDown(date* massiv, int n, int i) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;
    if (left < n && (massiv[i] < massiv[left]))
        largest = left;
    if (right < n && (massiv[largest] < massiv[right]))
        largest = right;
    if (largest != i) {
        std::swap(massiv[i], massiv[largest]);
        siftDown(massiv, n, largest);
    }
}

void buildHeap(date* massiv, int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        siftDown(massiv, n, i);
    }
}


void extractMax(date* massiv, int& heapSize) {
    std::swap(massiv[0], massiv[heapSize - 1]);
    --heapSize;
    siftDown(massiv, heapSize, 0);
}

void heapSort(date* massiv, int heapSize) {
    while (heapSize > 1) {
        extractMax(massiv, heapSize);
    }
}
int main() {
    int n;
    std::cin >> n;
    auto man = new person [n];
    for (int i = 0; i < n; i++) {
        std::cin >> man[i].birth_date.day >> man[i].birth_date.month >> man[i].birth_date.year >> man[i].death_date.day >> man[i].death_date.month >> man[i].death_date.year;
        man[i].birth_date.birth_or_death = 1;
        man[i].death_date.birth_or_death = -1;
    }

    //создаем массив из дат рождения и смерти, который потом и будем сортировать
    date* massiv = new date [2*n];
    buildMassiv(man, n, massiv);

    //удаляем уже ненужный массив, в который изначально записали даты рождения и смерти
    delete[] man;
    int heapSize = n*2;
    buildHeap(massiv, heapSize);
    heapSort(massiv, heapSize);
    std::cout << countContemporary(massiv, n*2);
    delete[] massiv;
}
