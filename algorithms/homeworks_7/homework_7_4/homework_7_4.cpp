// homework_7_4.cpp : Задача 4*. Поиск компонентов связности

#include <iostream>
#include <fstream>

int** create_double_array(int n) {
    int** arr = new int* [n]();
    for (int i = 0; i < n; i++) arr[i] = new int[n]();
    return arr;
}
void delete_double_array(int** arr, int n) {
    for (int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
}
void print_adjacency_matrix(int** arr, int n) {
    std::cout << "Матрица смежности графа: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}
void dfs(int** graph, int* cids, int v, int vertex, int cid) {
    cids[vertex] = cid;
    for (int i = 0; i < v; i++) {
        if ((graph[vertex][i] != 0)) {
            if (cids[i] == 0) {
                dfs(graph, cids, v, i, cid);
            }
        }
    }
}
void components(int** graph, int* cids, int v, int vertex) {
    int cid = 0;
    std::cout << "Принадлежность вершин компонентам связности: " << std::endl;
    for (vertex = 0; vertex <= v; vertex++) {
        if (cids[vertex] == 0 ) {
            cid += 1;
            dfs(graph, cids, v, vertex, cid);
        }
        std::cout << vertex << " - " << cid << std::endl;
    }
    std::cout << "Количество компонентов связности в графе: " << cid << std::endl;
}

//___________________________________________________________________

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Rus");
    int v, cid;
    std::ifstream fin("input1.txt");

    if (fin.is_open()) {
        fin >> v;
        int** graph = create_double_array(v);
        bool* visited = new bool[v]();
        int* cids = new int[v]();

        while (!fin.eof()) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    fin >> graph[i][j];
                }
            }
        }
        print_adjacency_matrix(graph, v);
        components(graph, cids, v, 0);

        fin.close();
        delete_double_array(graph, v);
        delete[] visited;
    }
    else std::cout << "Файл не открывается!" << std::endl;

    return 0;
}

