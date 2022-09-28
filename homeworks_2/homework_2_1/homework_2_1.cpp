// Задача 1. Месяцы

#include <iostream>

enum class Months {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};
int main(int argc, char** argv) {

    setlocale(LC_ALL, "rus");
  
    int userInput = 1;

    while (userInput != 0) {
        std::cout << "Введите номер месяца: ";
        std::cin >> userInput;
       
        Months month = static_cast<Months>(userInput);

        if (static_cast<int>(month) != 0) {
            switch (month) {
                case(Months::JANUARY):
                    std::cout << "Январь" << std::endl;
                    break;
                case(Months::FEBRUARY):
                    std::cout << "Февраль" << std::endl;
                    break;
                case(Months::MARCH):
                    std::cout << "Март" << std::endl;
                    break;
                case(Months::APRIL):
                    std::cout << "Апрель" << std::endl;
                    break;
                case(Months::MAY):
                    std::cout << "Май" << std::endl;
                    break;
                case(Months::JUNE):
                    std::cout << "Июнь" << std::endl;
                    break;
                case(Months::JULY):
                    std::cout << "Июль" << std::endl;
                    break;
                case(Months::AUGUST):
                    std::cout << "Август" << std::endl;
                    break;
                case(Months::SEPTEMBER):
                    std::cout << "Сентябрь" << std::endl;
                    break;
                case(Months::OCTOBER):
                    std::cout << "Октябрь" << std::endl;
                    break;
                case(Months::NOVEMBER):
                    std::cout << "Ноябрь" << std::endl;
                    break;
                case(Months::DECEMBER):
                    std::cout << "Декабрь" << std::endl;
                    break;
                default:
                    std::cout << "Неправильный номер!" << std::endl;
                    break;
            }
            //break;
        }
    }
    std::cout << "Спасибо!" << std::endl;
    return 0;
}

