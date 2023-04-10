// homework_1_1.cpp : MAP-5 Задание 1. «Очередь клиентов»

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void client(int& count, int number) {
    while (count < number) {
        count++;
        std::this_thread::sleep_for(1s);
        std::cout << count << " clients in the queue. " << std::endl;
    }
}
void clerk(int& count) {
    while (count > 0) {
        count--;
        std::this_thread::sleep_for(2s);
        std::cout << "The clerk processed the order, " << count << " clients in the queue. " << std::endl;
    }
}

int main(int argc, char** argv) {
    int c = 3;
    std::thread t1(client, std::ref(c), 5);
    std::thread t2 (clerk, std::ref(c));
    t1.join();
    t2.join();
    
    return 0;
}