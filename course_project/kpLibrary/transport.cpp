//transport.cpp
#include "pch.h"
#include "transport.h"

Transport::Transport() {
    name_ = "���������";
}
Transport::Transport(int s) {
    name_ = "���������";
    speed_ = 1;
}

std::string Transport::getName() { 
    return name_;
}
double Transport::getSpeed() { 
    return speed_;
}
double Transport::getTotalTime(int s) { 
    return(s / speed_); 
}