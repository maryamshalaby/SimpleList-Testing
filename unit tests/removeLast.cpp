#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// These tests is for "void removeLast()" that removes last element of the List
// Test 1
TEST_CASE( "removeLast(): Empty List", "[tags]" ) {

   // Now List is []
   SimpleList<int> L;

   // Try to remove L[last] = --
      L.removeLast();

   // Now List is []
      REQUIRE(L.size() == 0);

 }

// Test 2
TEST_CASE( "removeLast(): List with 1 element", "[tags]" ) {

   // Now List is [11]
   SimpleList<int> L;
   L.insert(11);

   // Try to remove L[last] = 11
      L.removeLast();

   // Now List is []
      REQUIRE(L.size() == 0);


 }

// Test 3
TEST_CASE( "removeLast(): List with multiple elements", "[tags]" ) {

   // Now List is [11,-2,3,1]
   SimpleList<int> L;
   L.insert(11);
   L.insert(-2);
   L.insert(3);
   L.insert(1);


   // Remove L[last] = 1
   L.removeLast();
   // Now List is [11,-2,3]
   REQUIRE(L.size() == 3);
   REQUIRE(L.get(0) == 11);
   REQUIRE(L.get(1) == -2);
   REQUIRE(L.get(2) == 3);
        
    
 }

//////////////////////////////////////////////////////////
