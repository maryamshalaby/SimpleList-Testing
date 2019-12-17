#include "includes/catch.hpp"
#include "../src/SimpleList.h"
#include <iostream>

////////////SIZE//////////////

TEMPLATE_TEST_CASE( "size of SimpleList", "[myLinkedList][template]", int, char, float, bool) {

  SimpleList<TestType> *myLinkedList = new SimpleList<TestType>();

  SECTION( "empty list size" ) {
    REQUIRE( myLinkedList->size() == 0);
  }

  SECTION( "single element list size" ) {
    myLinkedList->add(5);  
    REQUIRE( myLinkedList->size() == 1);
  }

  SECTION( "multi element list size" ) {
    myLinkedList->add(5);  
    myLinkedList->add(10);
    myLinkedList->add(20);  
    REQUIRE( myLinkedList->size() == 3);
  }
}