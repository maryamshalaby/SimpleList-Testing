#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// clear();
//---------

TEST_CASE("clear empty list", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->clear();
    REQUIRE(myLinkedList->size() == 0);
}

TEST_CASE("clear Non-empty list", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->clear();
    myLinkedList->add(2);
    myLinkedList->add(3);
    myLinkedList->clear();
    myLinkedList->clear();
    REQUIRE(myLinkedList->size() == 0);
}

/*----------------------------------------------------------------------------------------------*/

// isEmpty();
//---------

TEST_CASE("check empty list on clearing list", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->clear();
    myLinkedList->add(2);
    myLinkedList->add(3);
    myLinkedList->clear();
    myLinkedList->clear();
    REQUIRE(myLinkedList->isEmpty() == 1);
}

TEST_CASE("Check non-empty list", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->clear();
    myLinkedList->add(2);
    myLinkedList->add(3);
    REQUIRE(myLinkedList->isEmpty() == 0);
}