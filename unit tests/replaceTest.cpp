#include "includes/catch.hpp"
#include "../src/SimpleList.h"


// These tests is for "void replace(int index, T obj)" that replaces value of specific element
// Test 1
TEST_CASE( "replace(int index, T obj): Empty List", "[tags]" ) {

   // Now List is []
   SimpleList<int> L;

    SECTION( "Replace index doesn't exist in the List" ) {
       // Try to remove L[5] = --
        L.replace(0,2);

      // Now List is []
         REQUIRE(L.size() == 0);
    }
    SECTION( "Replace negative index" ) {
       // Try to remove L[-10] = --
        L.replace(-10, 2);
      // Now List is []
         REQUIRE(L.size() == 0);
    }
    SECTION( "Replace NULL index" ){
      // Try to remove L[NULL] = --
        L.replace(int(), 2);
      // Now List is []
         REQUIRE(L.size() == 0);
    }
 }

// Test 2
TEST_CASE( "replace(int index, T obj): List with 1 element", "[tags]" ) {

   // Now List is [11]
   SimpleList<int> L;
   L.insert(11);


    SECTION( "Replace element at index 0" ) {
      // Replace L[0] = 11 to be L[0] = 2
      L.replace(0,2);
      // Now List is [2]
      REQUIRE(L.size() == 1);
      REQUIRE(L.get(0) == 2);
      
    }

    SECTION( "Replace index doesn't exist in the List" ) {
       // Try to replace L[5] = --
        L.replace(5,2);

      // Now List is [11]
         REQUIRE(L.size() == 1);
         REQUIRE(L.get(0) == 11);
    }
    SECTION( "Replace negative index" ) {
       // Try to replace L[-10] = --
        L.replace(-10,2);
         // Now List is [11]
         REQUIRE(L.size() == 1);
         REQUIRE(L.get(0) == 11);
    }

     SECTION( "Replace NULL index" ){
      // Try to remove L[NULL] = --
        L.replace(int(), 2);
      // Now List is [11]
         REQUIRE(L.size() == 1);
         REQUIRE(L.get(0) == 11);
    }
 }

// Test 3
TEST_CASE( "replace(int index, T obj): List with multiple elements", "[tags]" ) {

   // Now List is [11,-2,3,1]
   SimpleList<int> L;
   L.insert(11);
   L.insert(-2);
   L.insert(3);
   L.insert(1);


    SECTION( "Replace element at index 0" ) {
      // Replace L[0] = 11 to be L[0] = 33
      L.replace(0,33);
      // Now List is [33,-2,3,1]
      REQUIRE(L.size() == 4);
      REQUIRE(L.get(0) == 33);
      REQUIRE(L.get(1) == -2);
      REQUIRE(L.get(2) == 3);
      REQUIRE(L.get(3) == 1);
        
    }
    SECTION( "Replace index in the middle of List" ) {
         // Replace L[2] = 3 to be L[2] = 9
         L.replace(2,9);
         // Now List is [11, -2, 9, 1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 9);
         REQUIRE(L.get(3) == 1);


    }
    SECTION( "Replace index size-1" ) {
        
      // Replace L[3] = 1 to be L[3] = 10
      L.replace(L.size()-1, 10);

      // Now List is [11,-2, 3, 10]
      REQUIRE(L.size() == 4);
      REQUIRE(L.get(0) == 11);
      REQUIRE(L.get(1) == -2);
      REQUIRE(L.get(2) == 3);
      REQUIRE(L.get(3) == 10);

    }
    SECTION( "Replace index doesn't exist in the List" ) {
       // Replace L[5] = --
        L.replace(5, 3);

      // Now List is [11,-2,3,1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
    }
    SECTION( "Replace negative index" ) {
       // Replace L[-10] = --
        L.replace(-10,2);
         // Now List is [11,-2,3,1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
    }

      SECTION( "Replace NULL index" ){
      // Try to remove L[NULL] = --
        L.replace(int(), 2);
      // Now List is [11,-2,3,1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
    }
 }
//////////////////////////////////////////////////////////
