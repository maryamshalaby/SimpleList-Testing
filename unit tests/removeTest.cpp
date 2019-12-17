#include "includes/catch.hpp"
#include "../src/SimpleList.h"

// These tests is for "void remove(int index)" that removes element at specific element
// Test 1
TEST_CASE( "remove(index): Empty List", "[tags]" ) {

   // Now List is []
   SimpleList<int> L;

    SECTION( "Remove index doesn't exist in the List" ) {
       // Try to remove L[5] = --
        L.remove(5);

      // Now List is []
         REQUIRE(L.size() == 0);
    }
    SECTION( "Remove negative index" ) {
       // Try to remove L[-10] = --
        L.remove(-10);
         // Now List is []
         REQUIRE(L.size() == 0);
    }
   SECTION( " Remove NULL index " ){
      // Try to remove L[NULL] = --
        L.remove(int());
      // Now List is []
      REQUIRE(L.size() == 0);
   }
 }


// Test 2
TEST_CASE( "remove(index): List with 1 element", "[tags]" ) {

   // Now List is [11]
   SimpleList<int> L;
   L.insert(11);


    SECTION( "Remove at index 0" ) {
      // Remove L[0] = 11
      L.remove(0);
      // Now List is []
      REQUIRE(L.size() == 0);
        
    }

    SECTION( "Remove index doesn't exist in the List" ) {
       // Try to remove L[5] = --
        L.remove(5);

      // Now List is [11]
         REQUIRE(L.size() == 1);
         REQUIRE(L.get(0) == 11);
    }
    SECTION( "Remove negative index" ) {
       // Try to remove L[NULL] = --
        L.remove(-10);
         // Now List is [11]
         REQUIRE(L.size() == 1);
         REQUIRE(L.get(0) == 11);
    }
   SECTION( " Remove NULL index " ){
      // Try to remove L[-10] = --
        L.remove(int());
      // Now List is []
      REQUIRE(L.size() == 1);
      REQUIRE(L.get(0) == 11);

   }
 }

// Test 3
TEST_CASE( "remove(index): List with multiple elements", "[tags]" ) {

   // Now List is [11,-2,3,1]
   SimpleList<int> L;
   L.insert(11);
   L.insert(-2);
   L.insert(3);
   L.insert(1);


    SECTION( "Remove at index 0" ) {
      // Remove L[0] = 11
      L.remove(0);
      // Now List is [-2,3,1]
      REQUIRE(L.size() == 3);
      REQUIRE(L.get(0) == -2);
      REQUIRE(L.get(1) == 3);
      REQUIRE(L.get(2) == 1);
        
    }
    SECTION( "Remove index in the middle of List" ) {
         // Try to remove L[2] = 3
         L.remove(2);
         // Now List is [11,-2,1]
         REQUIRE(L.size() == 3);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 1);


    }
    SECTION( "Remove at index size-1" ) {
        
         // Try to remove L[3] = 1
        L.remove(L.size()-1);

         // Now List is [11,-2, 3]
         REQUIRE(L.size() == 3);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);

    }
    SECTION( "Remove index doesn't exist in the List" ) {
       // Try to remove L[5] = --
        L.remove(5);

      // Now List is [11,-2,3,1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
    }
    SECTION( "Remove negative index" ) {
       // Try to remove L[-10] = --
        L.remove(-10);
         // Now List is [11,-2,3,1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
   }
   SECTION( " Remove NULL index " ){
      // Try to remove L[NULL] = --
        L.remove(int());
      // Now List is [11,-2,3,1]
      REQUIRE(L.size() == 4);
      REQUIRE(L.get(0) == 11);
      REQUIRE(L.get(1) == -2);
      REQUIRE(L.get(2) == 3);
      REQUIRE(L.get(3) == 1);
   }
 }
//////////////////////////////////////////////////////////