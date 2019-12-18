#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// These tests is for "void moveToEnd()" that removes last element of the List
// Test 1
TEST_CASE( "moveToEnd(): Empty List", "[tags]" ) {

   // Now List is []
   SimpleList<int> L;

   // Move L[0] = -- to end
   L.moveToEnd();

   // Now List is []
   REQUIRE(L.size() == 0);    

 }

// Test 2
TEST_CASE( "moveToEnd(): List with 1 element", "[.][segfault]" ) {

   // Now List is [11]
   SimpleList<int> L;
   L.insert(11);

   // Move L[0] = 11 to end
   L.moveToEnd();

   // Now List is [11]
   REQUIRE(L.size() == 1);
   REQUIRE(L.get(0) == 11);

}

// Test 3
TEST_CASE( "moveToEnd(): List with multiple elements", "[tags]" ) {

   // Now List is [11,-2,3,1]
   SimpleList<int> L;
   L.insert(11);
   L.insert(-2);
   L.insert(3);
   L.insert(1);


   // Move L[0] = 11 to end
   L.moveToEnd();

   // Now List is [-2, 3, 1, 11]
   REQUIRE(L.size() == 4);
   REQUIRE(L.get(0) == -2);
   REQUIRE(L.get(1) == 3);
   REQUIRE(L.get(2) == 1);
   REQUIRE(L.get(3) == 11);
      
 }

////////////////////////////////////////////////////////
