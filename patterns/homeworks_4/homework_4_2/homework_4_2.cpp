// homework_4_2.cpp : DPCPP-6 ДЗ к занятию «Свойства хорошего кода. Принципы DRY и SOLID». Задание 2.

#include <fstream>
#include <iostream>

class Printable {
public:
    virtual ~Printable() = default;
    virtual std::string printData() const = 0;
};

class Data : public Printable {
public:
    Data() {};
    explicit Data (std::string& userData) : data_(userData) {}

    virtual std::string printData() const override {
        return "data_";
    }
protected:
    std::string data_;
};

class TextData : public Data {
public:
    explicit TextData(std::string& userData) : Data(userData) {}
     
    std::string printData() const override {
        return data_;
    }
};

class HTMLData : public Data {
public:
    explicit HTMLData(std::string& userData) : Data(userData) {}

    std::string printData() const override {
        return ("<html>" + data_ + "<html/>");
    }
};

class JSONData : public Data {
public:
    explicit JSONData(std::string& userData) : Data(userData) {}

    std::string printData() const override {
        return ("{ \"data\": \"" + data_ + "\"}");
    }
};

void saveTo(std::ofstream& file, const Data& data) {
    file << data.printData();
    std::cout << "written to file: " + data.printData() << std::endl;
}

void saveToAsHTML(std::ofstream& file, std::string& userData) {
    HTMLData data(userData);
    saveTo(file, data);
}

void saveToAsText(std::ofstream& file, std::string& userData) {
    TextData data(userData);
    saveTo(file, data);
}

void saveToAsJSON(std::ofstream& file, std::string& userData) {
    JSONData data(userData);
    saveTo(file, data);
}

int main(int argc, char** argv) {
    Printable p();
    std::string userData = "TEXT";
    std::ofstream fout("file.txt");

    saveToAsHTML(fout, userData);
    saveToAsText(fout, userData);
    saveToAsJSON(fout, userData);

    fout.close();
    return 0;
}




