#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// Add(T obj);
//-------------

class temp
{
private:
    int d;

public:
    temp() {}
    temp(int a)
    {
        d = a;
    }
    friend bool operator==(const temp &c1, const temp &c2);
    ~temp() {}
};

bool operator==(const temp &c1, const temp &c2)
{
    return (c1.d == c2.d);
}

TEST_CASE("add single element", "[myLinkedList]")
{
    SimpleList<temp> *myLinkedList = new SimpleList<temp>();
    temp t(2);
    myLinkedList->add(t);
    myLinkedList->add(temp());
    REQUIRE(myLinkedList->getLast() == temp());
}

TEST_CASE("add multi element, check size", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->add(4);
    myLinkedList->add(7);
    REQUIRE(myLinkedList->size() == 2);
}

TEST_CASE("add multi element, check order", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->add(2);
    myLinkedList->add(7);
    myLinkedList->add(9);
    REQUIRE(myLinkedList->getFirst() == 2);
}

// Failed Test: reuired to be sorted, the sort check is not working correctly
TEST_CASE("add multi element ordered, check sorted", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->add(2);
    myLinkedList->add(7);
    myLinkedList->add(9);
    REQUIRE(myLinkedList->isSorted() == true);
}

/*----------------------------------------------------------------------------------------------*/

// Add(int index, T obj);
//-----------------------

// Failure on adding in the first node
TEST_CASE("add element with index in range in first node", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->add(5);
    myLinkedList->add(8);
    myLinkedList->add(1, 6);
    REQUIRE(myLinkedList->getFirst() == 5);
    myLinkedList->add(0, 2);
    REQUIRE(myLinkedList->getLast() == 8);
    REQUIRE(myLinkedList->isSorted() == 1);
}

// Failure on adding elements ascendingly and sorted is false
TEST_CASE("add element ascendingly and check sorted", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->add(5);
    myLinkedList->add(8);
    myLinkedList->add(1, 6);
    REQUIRE(myLinkedList->isSorted() == 1);
}

TEST_CASE("add element with index out of range", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->add(2);
    myLinkedList->add(4, 7);
    REQUIRE(myLinkedList->getFirst() == 2);
}

/*----------------------------------------------------------------------------------------------*/

// insert(T obj);
//---------------

TEST_CASE("insert at empty list", "[myLinkedList]")
{
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->insert(2);
    REQUIRE(myLinkedList->getFirst() == 2);
}

// Failed to sort inserted element
TEST_CASE("insert at nonempty list", "[myLinkedList]")
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
    myLinkedList->insert(2);
    REQUIRE(myLinkedList->getFirst() == 2);
    myLinkedList->insert(6);
    REQUIRE(myLinkedList->getLast() == 6);
    myLinkedList->insert(4);
    REQUIRE(myLinkedList->get(0) == 2);
    REQUIRE(myLinkedList->get(1) == 4);
    REQUIRE(myLinkedList->get(2) == 6);
    REQUIRE(myLinkedList->getLast() == 6);
}

/*----------------------------------------------------------------------------------------------*/
