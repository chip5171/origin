#pragma once
#include <iostream>
#include <fstream>

// ошибка линковки - тип заявленной переменной в заголовочном файле отличается от типа в файле реализации
int* create_array(double size);
int* writing_array(std::ifstream& file, int* arr, int size);
void print_array(int* arr, int size);
void delete_array(int* arr, int size);