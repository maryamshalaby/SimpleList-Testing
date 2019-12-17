#include "includes/catch.hpp"
#include "../src/SimpleList.h"

TEMPLATE_TEST_CASE( "shift first element out of", "[shift]" , int, float, bool, double) {

    SimpleList<TestType> *myList = new SimpleList<TestType>();

    SECTION( "0 element list" ) {
        REQUIRE( myList->shift()==TestType());
    }
    SECTION( "1 element list" ) {
        myList->insert(4.2);
        REQUIRE( myList->shift()==TestType(4.2));
        REQUIRE( myList->shift()==TestType()); 
    }
    SECTION( "2 element list" ) {
        myList->insert(-4);
        myList->insert(2);
        REQUIRE( myList->shift()==TestType(-4));
        REQUIRE( myList->shift()==TestType(2)); 
    }
    SECTION( "multiple element list" ) {
        myList->insert(-4);
        myList->insert(2.5);
        myList->insert(2);
        myList->insert(3);
        REQUIRE( myList->shift()==TestType(-4));
    }

}
TEMPLATE_TEST_CASE( "pop last element out of", "[pop]",int, float, bool, double ) {

    SimpleList<TestType> *myList = new SimpleList<TestType>();


    SECTION( "0 element list" ) {
        REQUIRE( myList->pop()==TestType());
    }
    SECTION( "1 element list" ) {
        myList->insert(4);
        REQUIRE( myList->pop()==TestType(4));
        REQUIRE( myList->pop()==TestType()); 
    }
    SECTION( "2 element list" ) {
        myList->insert(-4);
        myList->insert(2);
        REQUIRE( myList->pop()==TestType(2));
        REQUIRE( myList->pop()==TestType(-4)); 
    }
    SECTION( "multiple element list" ) {
        myList->insert(-4);
        myList->insert(2);
        myList->insert(2);
        myList->insert(3);
        REQUIRE( myList->pop()==TestType(3));
    }

}