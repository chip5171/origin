// Задача 3. Вывод структуры

#include <iostream>

struct Address {
    std::string sity;
    std::string street;
    int house;
    int apartment;
    int index;
};

void structurePrinting(Address& n) {
    std::cout << "Город: " << n.sity << std::endl;
    std::cout << "Улица: " << n.street << std::endl;
    std::cout << "Номер дома: " << n.house << std::endl;
    std::cout << "Номер квартиры: " << n.apartment << std::endl;
    std::cout << "Индекс: " << n.index << std::endl;
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "rus");

    Address a1, a2, a3;

    a1 = { "Москва", "Арбат", 12, 8, 123456 };
    a2 = { "Ижевск", "Пушкина", 59, 143, 953769 };
    a3 = { "Тверь", "Ленина", 20, 15, 654321 };

    structurePrinting(a1);
    structurePrinting(a2);
    structurePrinting(a3);
    
    return 0;
}

