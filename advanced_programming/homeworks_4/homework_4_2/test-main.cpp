// homework_4_2 test-main.cpp : CPPL-5 Задача 2. Проверка функций добавления и получения элементов из двусвязного списка

#include "list.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("test list", "[list]") {
    List list;
    SECTION("PushBack") {
        list.PushBack(2);
        list.PushBack(3);
        CHECK(list.PopBack() == 3);
        list.PushBack(9);
        CHECK(list.PopBack() == 9);
        list.PushBack(10);
        CHECK(list.PopFront() == 2);
    }
    SECTION("PushFront") {
        list.PushFront(2);
        list.PushFront(3);
        CHECK(list.PopFront() == 3);
        list.PushBack(1);
        list.PushFront(5);
        CHECK(list.PopFront() == 5);
        list.PushFront(10);
        CHECK(list.PopBack() == 1);
    }
    SECTION("PopBack") {
        list.PushBack(1);
        CHECK(list.PopBack() == 1);
        list.PushBack(2);
        list.PushBack(5);
        list.PushBack(3);
        CHECK(list.PopBack() == 3);
    }
    SECTION("PopFront") {
        list.PushBack(1);
        CHECK(list.PopFront() == 1);
        list.PushBack(2);
        list.PushBack(5);
        list.PushBack(3);
        CHECK(list.PopFront() == 2);
    }
    SECTION("Throws Exceptions") {
        list.Clear();
        CHECK_THROWS(list.PopBack());
        CHECK_THROWS(list.PopFront());
    }
}

int main(int argc, char* argv[]) {
   
    return Catch::Session().run(argc, argv);
}
