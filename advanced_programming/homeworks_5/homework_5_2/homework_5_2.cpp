// homework_5_2.cpp : CPPL-5 Задача 2. Таблица

#include <iostream>

template <class T>
class Table {
private:
    T** table;
    int row;
    int column;

public:

    Table(int rowСount, int columnCount) : row(rowСount), column(columnCount) {
        
        if ((rowСount >= 0) && (columnCount >= 0)) {
            table = new T * [row];
            for (int i = 0; i < row; i++) {
                table[i] = new T[column]{};
            }
        }
        else { throw std::exception("Отрицательный размер массива"); }
    }
   
    Table(const Table&) = delete;// компилятор ругается не дает создать экземпляр
    Table& operator=(const Table&) = delete;

    T* operator[](int index) {
        if ((index >= 0) && (index < (row - 1))) {
            return table[index];
        }
        else { throw std::exception("В массиве нет элемента с таким индексом"); }
    }

    T const* operator[](int index) const {
        return table[index];
    }
    
    std::pair<int, int> Size() const {
        return { row, column };
    }
};

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Rus");
    try {
        auto test = Table <int> (2, 3);
        test[0][0] = 4;
        std::cout << test[0][0] << std::endl;
        std::cout << "{ " << test.Size().first << ", " << test.Size().second << " }" << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
