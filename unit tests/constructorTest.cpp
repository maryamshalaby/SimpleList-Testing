#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// SimpleList();
//------------------------------------------

TEST_CASE("Test constructor", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    REQUIRE(myLinkedList->size() == 0);
}

// SimpleList(int(*compare)(T & a, T & b));
//------------------------------------------

TEST_CASE("Test overloaded constructor", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>([](int &a, int &b) -> int {
        if (a < b)
            return -1;
        if (a == b)
            return 0;
        if (a > b)
            return 1;
        return 0;
    });
    REQUIRE(myLinkedList->size() == 0);
}