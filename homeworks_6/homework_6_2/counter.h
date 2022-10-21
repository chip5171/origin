#pragma once

class Counter {
private:
    int privCount;
public:
    void setPrivCount(int value);
    Counter(int value);
    Counter();
    int increment();
    int decrement();
    void getPrivCount();
};

void counterCalc(Counter& count);