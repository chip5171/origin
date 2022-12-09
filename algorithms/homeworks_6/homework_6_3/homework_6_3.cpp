// homework_6_3.cpp : Задача 3. Упрощённый алгоритм Рабина-Карпа

#include <iostream>
#include <string>

int code(std::string str, int i) {
    return static_cast<int>(str[i]);
}
int simple_string_hash(std::string str) {
    int hash = 0;
    for (int i = 0; i < str.size(); i++) {
        hash += code(str,i);
    }
    return hash;
}
int find_substring_light_rabin_karp(std::string source, std::string substring) {
    int i, j;
    int n = source.length();
    int k = substring.length();
    int substring_hash = simple_string_hash(substring);
    int hash = 0;

    for (i = 0; i < n; i++) {
        if (i == 0) {
            hash = simple_string_hash(source.substr(0, k));
        }
        else {
            hash -= code(source, i - 1);
            if ((i + k - 1) < n) {
                hash += code(source, i + k - 1);
            }
            else return -1;
        }
        
        if (hash != substring_hash) {
                continue;
        }
        else {
            for (j = 0; j < k; j++) {
                if (substring[j] != source[i + j]) {
                    break;
                }
                else {
                    return i;
                }
            }
        }
        return -1;
    }
}

//______________________________________________________________________________________________________

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Rus");
    
    std::string str;
    std::string substr;
    int index = 0;
    
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str;
    do {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> substr;
        index = find_substring_light_rabin_karp(str, substr);
        if (index != -1) {
            std::cout << "Подстрока  " << substr << " найдена по индексу " << index << std::endl;
        }
        else {
            std::cout << "Подстрока  " << substr << " не найдена " << std::endl;
        }
    } while (substr != "exit");

    return 0;
}

