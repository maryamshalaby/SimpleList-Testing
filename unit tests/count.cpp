#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// count();
//---------

TEST_CASE("count on empty list", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
        if (a < b)
            return -1;
        if (a == b)
            return 0;
        if (a > b)
            return 1;
    });
    REQUIRE(myLinkedList->count(1) == 0);
}

TEST_CASE("count non existing element", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
        if (a < b)
            return -1;
        if (a == b)
            return 0;
        if (a > b)
            return 1;
    });
    myLinkedList->add(1);
    myLinkedList->add(2);
    myLinkedList->add(3);
    myLinkedList->add(3);
    myLinkedList->add(3);
    myLinkedList->add(3);
    REQUIRE(myLinkedList->count(4) == 0);
}

TEST_CASE("count existing element", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
        if (a < b)
            return -1;
        if (a == b)
            return 0;
        if (a > b)
            return 1;
    });
    myLinkedList->add(1);
    myLinkedList->add(2);
    myLinkedList->add(3);
    myLinkedList->add(3);
    myLinkedList->add(3);
    myLinkedList->add(3);
    REQUIRE(myLinkedList->count(3) == 4);
}
