/*Дано невзвешенное дерево.
 * Расстоянием между двумя вершинами будем называть количество ребер в пути, соединяющем эти две вершины.
 * Для каждой вершины определите расстояние до самой удаленной от нее вершины. Время работы должно быть O(n).
 * В первой строке записано количество вершин n ≤ 10000. Затем следует n - 1 строка, описывающая ребра дерева.
 * Каждое ребро - это два различных целых числа - индексы вершин в диапазоне [0, n-1]. Индекс корня – 0.
 * В каждом ребре родительской вершиной является та, чей номер меньше.
 * Выход должен содержать n строк.
 * В i-ой строке выводится расстояние от i-ой вершины до самой удаленной от нее.

 * */
#include <iostream>
#include <vector>

const int MAX_N = 1e4;

std::vector<std::vector<int> > tree;
int d1[MAX_N], d2[MAX_N];
// v - вершина, из которой я перешла (на данный момент текущая вершина)
void dfs(int v, int *d, int parent = -1, int cur_d = 0) {
    d[v] = cur_d;
    for (int u : tree[v]) {
        if (u != parent) {
            dfs(u, d, v, cur_d + 1);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    tree.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        std::cin >> v >> u;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    //записываем в d1 расстояния от корня до всех вершин
    dfs(0, d1);

    int diam1 = 0;
    int diam2 = 0;

    //ищем вершину, которая наиболее удалена от корня (первую точку диаметра)
    for (int i = 0; i < n; ++i) {
        if (d1[diam1] < d1[i]) {
            diam1 = i;
        }
    }

    //записываем в d1 расстояние от "наиболее удаленной от корня вершины" (первой точки диаметра) до всех вершин
    dfs(diam1, d1);

    //ищем вершину, которая наиболее удалена от "наиболее удаленной от корня вершины" (вторую точку диаметра)
    for (int i = 0; i < n; ++i) {
        if (d1[diam2] < d1[i]) {
            diam2 = i;
        }
    }

    //записываем в d2 расстояния от "наиболее удаленной от "наиболее удаленной от корня"" вершины (второй точки диаметра) до всех вершин
    dfs(diam2, d2);

    //для каждой вершины ищем максимум из расстояний до первой точки диаметра и второй точки диаметра
    for (int i = 0; i < n; ++i)
        std::cout << std::max(d1[i], d2[i]) << std::endl;
    return 0;
}
