#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// These tests is for "void removeFirst()" that removes element at the beginning of the List
// Test 1
TEST_CASE( "removeFirst(): Empty List", " " ) {

   // Now List is []
   SimpleList<int> L;

   // Try to remove L[0] = --
   L.removeFirst();

   // Now List is []
   REQUIRE(L.size() == 0);

 }

// Test 2
TEST_CASE( "removeFirst(): List with 1 element", "[tags]" ) {

   // Now List is [11]
   SimpleList<int> L;
   L.insert(11);

   // Try to remove L[0] = 11
   L.removeFirst();

   // Now List is []
   REQUIRE(L.size() == 0);



 }

// Test 3
TEST_CASE( "removeFirst(): List with multiple elements", "[tags]" ) {

   // Now List is [11,-2,3,1]
   SimpleList<int> L;
   L.insert(11);
   L.insert(-2);
   L.insert(3);
   L.insert(1);

   // Remove L[0] = 11
   L.removeFirst();
   // Now List is [-2,3,1]
   REQUIRE(L.size() == 3);
   REQUIRE(L.get(0) == -2);
   REQUIRE(L.get(1) == 3);
   REQUIRE(L.get(2) == 1);
        

 }
//////////////////////////////////////////////////////////
