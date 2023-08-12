// homework_4_1.cpp : DPCPP-6 ДЗ к занятию «Свойства хорошего кода. Принципы DRY и SOLID». Задание 1.

#include <fstream>
#include <iostream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};
class Data : public Printable
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };
    // 1)Нарушен принцип открытости (OCP), если нужно добавить дополнительный формат, н-р YAML,
    // то придется вносить изменения в реализацию класса.
    // 2)Так же нарушен принцип разделения интерфейса ISP. Если клиент выбирает определенный
    // формат, то реализация других в данном месте ему не нужна, тем более что при ошибочном
    // использовании ф-ции для дугого формата, будет вызвано исключение.
    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string printAsHTML() const override
    {
        if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + data_ + "<html/>";
    }
    std::string printAsText() const override
    {
        if (format_ != Format::kText) {
            throw std::runtime_error("Invalid format!");
        }
        return data_;
    }
    std::string printAsJSON() const override
    {
        if (format_ != Format::kJSON) {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
    Format format_;
};
// 3)Нарушен принцип подстановки Лисков (LSP). Если используется ссылка на родительский класс, 
// то функция должна работать с любым из потомков, а здесь при использовании объекта Data
// одного формата с функцией другого вылетит исключение.  
void saveTo(std::ofstream& file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

void saveToAsHTML(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kHTML);
}

void saveToAsJSON(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kJSON);
}

void saveToAsText(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kText);
}

int main(int argc, char** argv) {
    Printable p();
    std::ofstream fout("file.txt");
    Data t("TEXT", Data::Format::kText);
    Data h("TEXT", Data::Format::kHTML);

    //saveTo(fout, h, Data::Format::kText);//нарушение LSP
    saveToAsHTML(fout, h);
    //std::cout << h.printAsText() << std::endl;//нарушение ISP
    std::cout << h.printAsHTML() << std::endl;

    fout.close();
    return 0;
}