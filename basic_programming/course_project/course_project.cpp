//course project.cpp : Курсовой проект «Симулятор гонок»

#include <iostream>
#include <cstdlib>
#include "transport.h"
#include "ground_transport.h"
#include "centaur.h"
#include "camel.h"
#include "all_terrain_boots.h"
#include "speed_camel.h"
#include "air_transport.h"
#include "eagle.h"
#include "carpet_plane.h"
#include "broomstick.h"
#include "race.h"
#include "aux_functions.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Rus");

    std::string raceType, transportName;
    int distance; 
    int select1, select2, select3, select4, select5;
    int x = 0; 
    
    //_____________________Выбор типа гонки_______________________________________________

    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    while (true) {
        while (true) {
            std::cout << "1. Гонка для наземного транспорта" << std::endl;
            std::cout << "2. Гонка для воздушного транспорта" << std::endl;
            std::cout << "3. Гонка для наземного и воздушного транспотра" << std::endl;
            std::cout << "Выберите тип гонки: ";
            std::cin >> select1;
            system("cls");
            if ((select1 < 1) || (select1 > 3)) {
                std::cout << "Неверно, повторите ввод!" << std::endl;
                false;
            }
            else break;
        }
        system("cls");

        if (select1 == 1) {
            raceType = "наземного транспорта"; x = 4;
        }
        else if (select1 == 2) {
            raceType = "воздушного транспорта"; x = 3;
        }
        else if (select1 == 3) {
            raceType = "наземного и воздушного транспорта"; x = 7;
        }

        //_________________________Выбор дистанции________________________________________________   

        std::cout << "Укажите длину дистанции (должна быть пололжительна): " << std::endl;
        std::cin >> distance;
        system("cls");

        //___________________________Регистрация ТС_______________________________________________     

        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства: " << std::endl;
        while (true) {
            std::cout << "1. Зарегистрировать транспорт" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> select2;
            system("cls");
            if (select2 != 1) {
                std::cout << "Неверно, повторите ввод!" << std::endl;
                false;
            }
            else break;
        }
        system("cls");

        //_______________________Выбор ТС_______________________________________________________

        int* p = new int[7](); // архив для исключения повторного использования case 

        Race* arr = new Race[x]; // архив для хранения экземпляров класса Race 

        Race raceArr(distance, 7);

        std::string str; // информация о зарегистрированных ТС

        int count = 0; // счетчик положительного выбора

        while (true) {
        label1:
            std::cout << "Гонка для " << raceType << ". Расстояние: " << distance << std::endl;
            std::cout << str;
            std::cout << "1. Ботинки-вездеходы" << std::endl;
            std::cout << "2. Метла" << std::endl;
            std::cout << "3. Верблюд" << std::endl;
            std::cout << "4. Кентавр" << std::endl;
            std::cout << "5. Орел" << std::endl;
            std::cout << "6. Верблюд-быстроход" << std::endl;
            std::cout << "7. Ковер-самолет" << std::endl;
            std::cout << "0. Закончить регистрацию" << std::endl;
            std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
            std::cin >> select3;
            system("cls");

            switch (select3) {
            case 0:
                while (true) {
                    if (count < 2) {
                        std::cout << "Для гонки необходимо не менее двух транспортных средств" << std::endl;
                        goto label1; //90
                    }
                    else {
                        std::cout << "1. Зарегистрировать транспорт" << std::endl;
                        std::cout << "2. Начать гонку" << std::endl;
                        std::cout << "Выберите действие: ";
                        std::cin >> select4;
                        system("cls");
                        if (select4 != 1 && select4 != 2) {
                            std::cout << "Неверно, повторите ввод!" << std::endl;
                            false;
                        }
                        else if (select4 == 1) { goto label1; }//90
                        else if (select4 == 2) { goto label2; }//214
                    }
                    break;
                };
                break;
            case 1:
                if (p[0] == 1) { except(transportName, 2); continue; }
                else if (x == 3) { except(transportName, 1); continue; }
                else {
                    Race race(distance, 1);
                    raceArr = race;
                    transportName = race.getName();
                    p[0] = 1;
                }
                break;
            case 2:
                if (p[1] == 1) { except(transportName, 2); continue; }
                else if (x == 4) { except(transportName, 1); continue; }
                else {
                    Race race(distance, 2);
                    raceArr = race;
                    transportName = race.getName();
                    p[1] = 1;
                }
                break;
            case 3:
                if (p[2] == 1) { except(transportName, 2); continue; }
                else if (x == 3) { except(transportName, 1); continue; }
                else {
                    Race race(distance, 3);
                    raceArr = race;
                    transportName = race.getName();
                    p[2] = 1;
                }
                break;
            case 4:
                if (p[3] == 1) { except(transportName, 2); continue; }
                else if (x == 3) { except(transportName, 1); continue; }
                else {
                    Race race(distance, 4);
                    raceArr = race;
                    transportName = race.getName();
                    p[3] = 1;
                }
                break;
            case 5:
                if (p[4] == 1) { except(transportName, 2); continue; }
                else if (x == 4) { except(transportName, 1); continue; }
                else {
                    Race race(distance, 5);
                    raceArr = race;
                    transportName = race.getName();
                    p[4] = 1;
                }
                break;
            case 6:
                if (p[5] == 1) { except(transportName, 2); continue; }
                else if (x == 3) { except(transportName, 1); continue; }
                else {
                    Race race(distance, 6);
                    raceArr = race;
                    transportName = race.getName();
                    p[5] = 1;
                }
                break;
            case 7:
                if (p[6] == 1) { except(transportName, 2); continue; }
                else if (x == 4) { except(transportName, 1); continue; }
                else {
                    Race race(distance, 7);
                    raceArr = race;
                    transportName = race.getName();
                    p[6] = 1;
                }
                break;
            default:
                std::cout << "Неверно! Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;
                break;
            }

            std::cout << transportName << " успешно зарегистрирован!" << std::endl;

            count++;
            arr[count - 1] = raceArr;

            if (count == 1) { str = "Зарегистрированные транспортные средства: " + transportName + "\n"; }
            else {
                str = str.substr(0, str.length() - 1);
                str += ", " + transportName + "\n";
            }
        }
        label2:

        arraySort(arr, count); // сортировка массива результатов

        std::cout << "Результаты гонки: " << std::endl;
        for (int j = 0; j < count; j++) {
            while (arr[j].getName() != "Участник гонки") {
                std::cout << j + 1 << ". " << arr[j].getName() << ". "
                    << "Время: " << arr[j].totalTime() << std::endl;
                break;
            }
        }
        system("pause");
        system("cls");
        delete[] p;
        delete[] arr;

        std::cout << "1. Провести еще одну гонку " << std::endl;
        std::cout << "2. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> select5;
        system("cls");
        if (select4 != 1 && select4 != 2) {
            std::cout << "Неверно, повторите ввод!" << std::endl;
            false;
        }
        else if (select5 == 1) { continue; }
        else if (select5 == 2) { return 0; }
    }
    return 0;
}
