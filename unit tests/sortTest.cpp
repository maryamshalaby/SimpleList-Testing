#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// These tests is for "void sort()" that sorts list ascendingly
// Test 1
TEST_CASE( "sort(): Empty List", "[tags]" ) {

   // Now List is []
   SimpleList<int> L;

   //Sort L
   L.sort();

   // Now List is []
   REQUIRE(L.size() == 0);

 }

// Test 2
TEST_CASE( "sort(): List with 1 element", "[tags]" ) {

   // Now List is [11]
   SimpleList<int> L;
   L.insert(11);

   L.sort();

   // Now List is []
   REQUIRE(L.size() == 1);
   REQUIRE(L.get(0) == 11);

 }

// Test 3
TEST_CASE( "sort(): List with multiple elements on arbitrary order", "[tags]" ) {

   // Now List is [11,-2,3,1]
   SimpleList<int> L([](int &a, int &b) -> int {
         if(a < b) return -1;
         if(a == b) return 0;
         if(a > b) return 1;  
      });

   L.insert(11);
   L.insert(-2);
   L.insert(3);
   L.insert(1);


   L.sort();

   // Now List is [-2, 1, 3, 11]
   REQUIRE(L.size() == 4);
   REQUIRE(L.get(0) == -2);
   REQUIRE(L.get(1) == 1);
   REQUIRE(L.get(2) == 3);
   REQUIRE(L.get(3) == 11);

 }
// Test 4
TEST_CASE( "sort(): List with multiple elements sorted ascendingly", "[tags]" ) {

   // Now List is [-3, 0, 3, 17]
   SimpleList<int> L;
   L.insert(-3);
   L.insert(0);
   L.insert(3);
   L.insert(17);


   L.sort();

   // Now List is [-3, 0, 3, 17]
   REQUIRE(L.size() == 4);
   REQUIRE(L.get(0) == -3);
   REQUIRE(L.get(1) == 0);
   REQUIRE(L.get(2) == 3);
   REQUIRE(L.get(3) == 17);

 }
// Test 5
TEST_CASE( "sort(): List with multiple elements sorted decendingly", "[tags]" ) {

   // Now List is [17, 3, 0, -3]
   SimpleList<int> L([](int &a, int &b) -> int {
         if(a < b) return -1;
         if(a == b) return 0;
         if(a > b) return 1;  
      });

      
   L.insert(17);
   L.insert(3);
   L.insert(0);
   L.insert(-3);


   L.sort();

   // Now List is [-3, 0, 3, 17]
   REQUIRE(L.size() == 4);
   REQUIRE(L.get(0) == -3);
   REQUIRE(L.get(1) == 0);
   REQUIRE(L.get(2) == 3);
   REQUIRE(L.get(3) == 17);

 }
//////////////////////////////////////////////////////////