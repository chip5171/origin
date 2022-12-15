// homework_8_1.cpp : Задача 1. Вывод орграфа на консоль

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
void print_vertex(int** graph, int v, int vertex) {
    int sum = 0;
    std::cout << vertex+1 << ":";
    for (int i = 0; i < v; i++) {
        sum += graph[vertex][i];
        if (graph[vertex][i] != 0) {
            std::cout << " " << i + 1;
        }
    }
        if (sum == 0) std::cout << " нет";
}
void print_digraph(int** graph, int v) {
    std::cout << "Текстовый вид орграфа: " << std::endl;
    for (int i = 0; i < v; i++) {
        print_vertex(graph, v, i);
        std::cout << std::endl;
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
     
        while (!fin.eof()) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    fin >> graph[i][j];
                }
            }
        }
        print_adjacency_matrix(graph, v);
        std::cout << std::endl;
        print_digraph(graph, v);
        
        fin.close();
        delete_double_array(graph, v);
    }
    else std::cout << "Файл не открывается!" << std::endl;

    return 0;
}

