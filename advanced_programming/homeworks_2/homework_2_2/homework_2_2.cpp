// homework_2_2.cpp : CPPL-5 Задача 2*. Сплошные ошибки
// Программа должна считывать массив из файла и выводить его на экран.

/*Синтаксическая ошибка  - в файле homework_2_2.cpp;
  семантическая ошибка - в файле function.cpp;
  ошибка линковки - в файле function.h */

#include <iostream>
#include <fstream>
#include "functions.h" 

int main(int argc, char** argv)
{
    int N;
    std::ifstream fin("in.txt");
    // Синтаксическая ошибка - отсутствует закрывающая скобка ")" в условном операторе
    if (!fin.is_open() { 
        std::cout << "File in.txt not opened\n";
        return 1;
    }
    
    fin >> N;
    int* arrN = create_array(N);
    writing_array(fin, arrN, N);
    fin.close();
    print_array(arrN, N);
    delete_array(arrN, N);
    
    return 0;
}

