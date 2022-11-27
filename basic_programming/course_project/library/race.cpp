//race.cpp
#include <iostream>
#include "race.h"

Race::Race() {
    name_ = "Участник гонки";
    totalTime_ = 1;
}
Race::Race(int s, int k) {
    switch (k) {
    case 1: {
        AllTerrainBoots boots(s);
        name_ = boots.getName();
        totalTime_ = boots.getTotalTime(s);
    }
          break;
    case 2: {
        Broomstick broomstick(s);
        name_ = broomstick.getName();
        totalTime_ = broomstick.getTotalTime(s);
    }
          break;
    case 3: {
        Camel camel(s);
        name_ = camel.getName();
        totalTime_ = camel.getTotalTime(s);
    }
          break;
    case 4: {
        Centaur centaur(s);
        name_ = centaur.getName();
        totalTime_ = centaur.getTotalTime(s);
    }
          break;
    case 5: {
        Eagle eagle(s);
        name_ = eagle.getName();
        totalTime_ = eagle.getTotalTime(s);
    }
          break;
    case 6: {
        SpeedCamel speedCamel(s);
        name_ = speedCamel.getName();
        totalTime_ = speedCamel.getTotalTime(s);
    }
          break;
    case 7: {
        CarpetPlane carpet(s);
        name_ = carpet.getName();
        totalTime_ = carpet.getTotalTime(s);
    }
          break;
    default:
        std::cout << "Неверно! Выберите транспорт или 0 для окончания процесса регистрации: " << std::endl;
    }
}
std::string Race::getName() {
    return name_;
}
double Race::getTotalTime(int s) {
    return totalTime_;
}
double Race::totalTime() {
    return totalTime_;
}



