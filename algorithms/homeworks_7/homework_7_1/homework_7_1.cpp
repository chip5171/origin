// homework_7_1.cpp : Задача 1. Обход в глубину

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
void print_adjacency_matrix(int** arr, int n) {
    std::cout << "Матрица смежности графа: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}
void dfs(int** graph, bool* visited, int v, int vertex) {
    std::cout << vertex + 1 << " ";
    visited[vertex] = true;
    for (int i = 0; i < v; i++) {
        if ((graph[vertex][i] != 0) && (!visited[i]))
            dfs(graph, visited, v, i);
    }
}

//___________________________________________________________________

int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "Rus");
    
    int v;
    std::ifstream fin("input.txt");

    if (fin.is_open()) {
        
        fin >> v;
        int** graph = create_double_array(v);
        bool* visited = new bool[v];
       
        while (!fin.eof()) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    fin >> graph[i][j];
                }
            }
        }
        print_adjacency_matrix(graph, v);
        for (int i = 0; i < v; i++) {
            visited[i] = false;
        }
        std::cout << std::endl;
        std::cout << "Порядок обхода вершин: " << std::endl;
        dfs(graph, visited, v, 0);
        std::cout << std::endl;
               
        fin.close();
        delete[] visited;
        delete_double_array(graph, v);
    }
    else {
        std::cout << "Файл не открывается!" << std::endl;
    }
    return 0;
}


