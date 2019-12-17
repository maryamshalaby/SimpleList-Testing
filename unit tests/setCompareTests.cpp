#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// our test cases

TEST_CASE("set Compare for a list of integers", "[sort]")
{

    SimpleList<int> *myList = new SimpleList<int>();
    myList->insert(7);
    myList->insert(2);
    myList->insert(3);
    myList->insert(3);

    SECTION("to sort ascenddignly")
    {

        myList->setCompare([](int &a, int &b) -> int {
            if (a < b)
                return -1;
            if (a == b)
                return 0;
            if (a > b)
                return 1;
            return 0;
        });

        myList->sort();

        REQUIRE((myList->get(0) == 2 && myList->get(1) == 3 && myList->get(2) == 3 && myList->get(3) == 7));
    }

    SECTION("to sort descendignly")
    {

        myList->setCompare([](int &a, int &b) -> int {
            if (a < b)
                return 1;
            if (a == b)
                return 0;
            if (a > b)
                return -1;
            return 0;
        });

        myList->sort();

        REQUIRE((myList->get(0) == 7 && myList->get(1) == 3 && myList->get(2) == 3 && myList->get(3) == 2));
    }

    SECTION("do nothing")
    {

        myList->setCompare([](int &a, int &b) -> int { return 0; });
        myList->sort();

        REQUIRE((myList->get(0) == 7 && myList->get(1) == 2 && myList->get(2) == 3 && myList->get(3) == 3));
    }
}