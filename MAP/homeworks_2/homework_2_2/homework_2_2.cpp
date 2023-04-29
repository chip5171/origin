// homework_2_2.cpp : MAP-5 Задание 2. «Прогресс бар»

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <Windows.h>

using namespace std::chrono_literals;
auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
//std::mutex m;

void setCursor(int x, int y) {
    SetConsoleCursorPosition(handle, { static_cast<SHORT>(x), static_cast<SHORT>(y) });
}
void setColor(int text, int background)
{
    SetConsoleTextAttribute(handle, (WORD)((background << 4) | text));
}

void progressBar(int x, int y, int length, double& progress, int k) {
    int fill = static_cast<int>(length * progress);
    setCursor(x, y);
    setColor(10 + k, 0);
    std::cout << "\r поток " << k << " #id " << std::this_thread::get_id() << " ";
    for (int i = 0; i < fill; ++i) {
        std::cout << "|";
    }
}

//_____________________________________________________________________

int main(int argc, char** argv) {
    setlocale(LC_ALL, "rus");

    int threadNumber = 5;
    int length = 20;
    double progress = 0;
    int x = 1;
    int y = 1;
       
    std::vector<std::thread> t;
    for (int j = 0; j < threadNumber; ++j) {
        y++;
    auto job = [x, y, length, &progress, j]() {
        auto start = std::chrono::high_resolution_clock::now();
        do {
            progressBar(x, y, length, progress, j);
            std::this_thread::sleep_for(std::chrono::milliseconds(1500 * j));
        } while (progress < 1);
        progressBar(x, y, length, progress, j);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration <double> time = end - start;
        std::cout << " " << time.count() << std::endl;
    };
        t.push_back(std::thread(job));

        int count = 20;
        int index = 0;
        while (index < count) {
            index += 1 + rand() % 8;
            if (index > count)
                index = count;
            progress = static_cast<double>(index) / count;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
    for (auto& t : t) { t.join(); }

    return 0;
}

  
        