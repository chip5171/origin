// homework_4_1 test-main.cpp : CPPL-5 Задача 1. Проверка базовых функций двусвязного списка

#include "list.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("test list", "[list]") {
    List list;
    SECTION("Size") {
        CHECK(list.Size() == 0);
        list.PushBack(1);
        list.PushBack(2);
        list.PushBack(3);
        CHECK(list.Size() == 3);
    }
    SECTION("Empty") {
        list.Size() == 0;
        CHECK(list.Empty() == true);
        list.PushBack(1);
        list.PushBack(2);
        list.Size() == 2;
        CHECK(list.Empty() == false);
    }
    SECTION("Clear") {
        list.Clear();
        CHECK(list.Size() == 0);
    }
}

int main(int argc, char* argv[]) {
   
    return Catch::Session().run(argc, argv);
}
