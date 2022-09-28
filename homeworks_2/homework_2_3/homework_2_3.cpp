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
    a1.sity = "Москва";
    a1.street = "Арбат";
    a1.house = 12;
    a1.apartment = 8;
    a1.index = 123456;

    a2.sity = "Ижевск";
    a2.street = "Пушкина";
    a2.house = 59;
    a2.apartment = 143;
    a2.index = 953769;

    a3.sity = "Тверь";
    a3.street = "Ленина";
    a3.house = 20;
    a3.apartment = 15;
    a3.index = 654321;

    structurePrinting(a1);
    structurePrinting(a2);
    structurePrinting(a3);
    
    return 0;
}

