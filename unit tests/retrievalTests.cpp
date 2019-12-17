#include "includes/catch.hpp"
#include "../src/SimpleList.h"


//test case with sections
TEMPLATE_TEST_CASE( "Get first element from list", "[get]",int, float, bool, double ) {
    SimpleList<TestType> *myList = new SimpleList<TestType>();
    
    SECTION( "0 element list" ) {

        REQUIRE(myList->getFirst()==TestType() );
    }
    SECTION( "one element list" ) {
        myList->insert(1);

        REQUIRE(myList->getFirst()==TestType(1) );
    }
    SECTION( "multiple element list" ) {
        myList->insert(2);
        myList->insert(3);
        myList->insert(4);

        REQUIRE(myList->getFirst()==TestType(2) );
    }
    SECTION( "list with first item removed" ) {
        myList->insert(-2);
        myList->insert(-3);
        myList->insert(4);
        myList->removeFirst();

        REQUIRE(myList->getFirst()==TestType(-3 ));
    }
}

TEMPLATE_TEST_CASE( "Get last element from", "[get]",int, float, bool, double ) {
    SimpleList<TestType> *myList = new SimpleList<TestType>();
    
    SECTION( "0 element list" ) {

        REQUIRE(myList->getLast()==TestType() );
    }
    SECTION( "one element list" ) {
        myList->insert(1);

        REQUIRE(myList->getLast()==TestType(1) );
    }
    SECTION( "multiple element list" ) {
        myList->insert(2);
        myList->insert(-3);
        myList->insert(4);

        REQUIRE(myList->getLast()==TestType(4) );
    }

    SECTION( "list with last item removed" ) {
        myList->insert(-2);
        myList->insert(-3);
        myList->insert(4);
        myList->removeLast();

        REQUIRE(myList->getLast()==TestType(-3) );
    }

}


TEMPLATE_TEST_CASE( "Get element by index from", "get",int, float, bool, double ) {
    
    SimpleList<TestType> *myList = new SimpleList<TestType>();


    SECTION( "0 element list" ) {
        REQUIRE(myList->get(0)==TestType() );
        REQUIRE(myList->get(3)==TestType() );
    }

    SECTION( "one element list" ) {
        myList->insert(1);

        REQUIRE(myList->get(0)==TestType(1) );
    }

    SECTION( "multiple element list" ) {
        myList->insert(2);
        myList->insert(3);
        myList->insert(3);

        REQUIRE(myList->get(2)==TestType(3) );
    }
   
}

TEMPLATE_TEST_CASE( "Get element from list by setting", "get",int, float, bool, double ) {

    SimpleList<TestType> *myList = new SimpleList<TestType>();

    myList->insert(-2);
    myList->insert(-3);
    myList->insert(4);
    myList->insert(20);
    myList->insert(20);

    SECTION( "index equals first element" ) {
        REQUIRE(myList->get(0)==TestType(-2) );
    }

    SECTION( "index equals last element" ) {
        REQUIRE(myList->get(4)==TestType(20) );
    }

    SECTION( "index out of range" ) {
        REQUIRE(myList->get(20)==TestType() );
    }

    SECTION( "index is negative" ) {
        REQUIRE(myList->get(-11)==TestType() );
    }
   
}

