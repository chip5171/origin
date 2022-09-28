// Задача 2. Счета

#include <iostream>
#include <Windows.h>

struct BankAccount {
    int accountNumber;
    std::string firstName;
    double balance;
};

void changeBalance(BankAccount& b, double newBalance) {
    b.balance = newBalance;
}

int main(int argc, char** argv) {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    BankAccount b; 
    double newBalance;
    std::cout << "Введите номер счета: ";
    std::cin >> b.accountNumber;
    std::cout << "Введите имя владельца: ";
    std::cin >> b.firstName;
    std::cout << "Введите баланс: ";
    std::cin >> b.balance;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    changeBalance(b, newBalance);

    std::cout << "Ваш счет: " << b.firstName << ", " << b.accountNumber << ", " << b.balance << std::endl;
    
    return 0;
}



