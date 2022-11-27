// homework_4_1.cpp : Задача 1. Адреса.

#include <iostream>
#include <sstream>
#include <fstream>

class Address {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;
public:
    Address() {
        city = "город";
        street = "улица";
        house = 1;
        apartment = 1;
    };
    Address(std::string sity, std::string street, int house, int apartment) {
        this->city = sity;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }
    std::string OutputAddress() {
        std::ostringstream out;
        out << city << ", " << street << ", " << house << ", " << apartment << std::endl;
        return out.str();
    }
};

        
int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "rus");
   
    int N, houseValue, apartmentValue;
    std::string cityValue, streetValue;

    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (!fin.is_open()) {
        std::cout << "File in.txt not opened\n";
        return 1;
    }
    if (!fout.is_open()) {
        std::cout << "File out.txt not opened\n";
        return 1;
    }
    
    fin >> N;
    fout << N << std::endl;
    
    Address *arrAddress = new Address[N];
    for (int i = 0; i < N; i++) {
        fin >> cityValue;
        fin >> streetValue;
        fin >> houseValue;
        fin >> apartmentValue;
        arrAddress[i] = { cityValue, streetValue, houseValue, apartmentValue };
    }
    fin.close();
    for (int i = N-1; i >= 0; i--) {
        fout << arrAddress[i].OutputAddress();
    };
    fout.close();
    delete []arrAddress;
    return 0;
}

