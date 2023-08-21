// course project.cpp : MAP-6 Курсовой проект: "Потокобезопасная очередь"

#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <chrono>

void f1() {
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::cout << "Running function f1" << std::endl;
}
void f2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "Running function f2" << std::endl;
}

template<class T>
class SafeQueue {
public:
    SafeQueue() {}

    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mutexQueue);
        tasksQueue.push(std::move(new_value));
        var.notify_one();
    }

    bool pop(T& value) {
        std::lock_guard<std::mutex> lk(mutexQueue);
        if (tasksQueue.empty())
            return false;
        value = std::move(tasksQueue.front());
        tasksQueue.pop();
        return true;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lk(mutexQueue);
        return tasksQueue.empty();
    }

private:
    std::mutex mutexQueue;
    std::queue<T> tasksQueue;
    std::condition_variable var;
};

class ThreadPool {
public:
    ThreadPool() {
        done = false;
        size_t const thread_count = std::thread::hardware_concurrency();

        for (size_t i = 0; i < thread_count; ++i) {
            threadsVector.push_back(
                std::thread(&ThreadPool::work, this));
        }
    }

    ~ThreadPool() {
        done = true;
        for (size_t i = 0; i < threadsVector.size(); ++i)
        {
            if (threadsVector[i].joinable())
                threadsVector[i].join();
        }
    }

    template<typename FunctionType>
    void submit(FunctionType f) {
        workQueue.push(std::function<void()>(f));
    }

private:
    void work() {
        while (!done) {
            std::function<void()> task;
            if (workQueue.pop(task)) {
                task();
            }
            else {
                std::this_thread::yield();
            }
        }
    }

    std::atomic_bool done;
    SafeQueue<std::function<void()>> workQueue;
    std::vector<std::thread> threadsVector;
};

int main(int args, char** argv) {
    ThreadPool tp;
    for (size_t i = 0; i < 5; i++) {

        tp.submit(f1);
        tp.submit(f2);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}