// homework_7_2.cpp : Задача 2*. Обход в ширину

#include <iostream>
#include <fstream>

int** create_double_array(int n) {
    int** arr = new int* [n]();
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n]();
    }
    return arr;
}
void delete_double_array(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
void bfs(int **graph, bool* visited, int v, int vertex) {
    int* queue = new int[v]();
    int count = 0; 
    int head = 0;
    queue[count++] = vertex;
    visited[vertex] = true;
    while (head < count) {
        vertex = queue[head++];
        std::cout << vertex + 1 << " ";
        for (int i = 0; i < v; i++)
            if (graph[vertex][i] && !visited[i]) {
                queue[count++] = i;
                visited[i] = true;
            }
    }
    delete[]queue;
}

//___________________________________________________________________

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Rus");

    int v;
    int start_vertex;
    std::ifstream fin("input.txt");

    if (fin.is_open()) {
        fin >> v;
        int** graph = create_double_array(v);
        bool* visited = new bool[v];

        while (true) {
        std::cout << "В графе " << v << " вершин. Введите номер вершины, с которой начнётся обход: ";
            std::cin >> start_vertex;
            if ((start_vertex <= 0) || (start_vertex > v)) {
                std::cout << "Вершины с таким номером в графе нет." << std::endl;
                continue;
            }
            else break;
        }
        while (!fin.eof()) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    fin >> graph[i][j];
                }
            }
        }
        for (int i = 0; i < v; i++) {
            visited[i] = false;
        }
        std::cout << "Порядок обхода вершин: " << std::endl;
        bfs(graph, visited, v, start_vertex - 1);
        
        fin.close();
        delete[] visited;
        delete_double_array(graph, v);
    }
    else {
        std::cout << "Файл не открывается!" << std::endl;
    }
    return 0;
}


