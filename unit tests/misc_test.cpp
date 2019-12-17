#include "includes/catch.hpp"
#include "../src/SimpleList.h"

////////////SIZE//////////////

TEMPLATE_TEST_CASE( "size of SimpleList", "[myLinkedList][template]", int, char, float, bool) {

  SimpleList<TestType> *myLinkedList = new SimpleList<TestType>();
  // empty list
  REQUIRE( myLinkedList->size() == 0);

  myLinkedList->add((TestType)5);  
  // list with one element
  REQUIRE( myLinkedList->size() == 1);

  myLinkedList->add((TestType)10);
  // list with 2 elements
  REQUIRE( myLinkedList->size() == 2);
}