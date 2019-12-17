#include "includes/catch.hpp"
#include "../src/SimpleList.h"


// These tests is for "void swap(int x, int y)" that replaces value of specific element
// Test 1
TEST_CASE( "swap(int x, int y): Empty List", "[!mayfail]" ) {

   // Now List is []
   SimpleList<int> L;

   SECTION( "Swap Same index" ) {
      // Swap element in 0 with element in 0
        L.swap(0,0);

      // Now List is []
         REQUIRE(L.size() == 0);
    }
   //  SECTION( "Swap index doesn't exist in the List" ) {
     
   //    // Swap element in 0 with element in 2
   //       L.swap(0,2);
       
   //    // Now List is []
   //       REQUIRE(L.size() == 0);
   //  }
    SECTION( "Swap negative x index" ) {
       // Swap element in -10 with element in 2
        L.swap(-10, 2);
      // Now List is []
         REQUIRE(L.size() == 0);
    }
   SECTION( "Swap negative y index" ) {
      // Swap element in 10 with element in -2
        L.swap(10, -2);
      // Now List is []
         REQUIRE(L.size() == 0);
    }
    SECTION( "Swap NULL x index " ){

        L.swap(int(), 0);
      // Now List is []
         REQUIRE(L.size() == 0);
    }
   SECTION( "Swap NULL y index " ){
       
        L.swap(0, int());
      // Now List is []
         REQUIRE(L.size() == 0);
    }
 }

// Test 2
TEST_CASE( "swap(int x, int y): List with 1 element", "[tags]" ) {

   // Now List is [11]
   SimpleList<int> L;
   L.insert(11);

   SECTION( "Swap same index" ) {
      // L[0],L[0] = L[0],L[0]
      L.swap(0,0);

      // Now List is [11]
      REQUIRE(L.size() == 1);
      REQUIRE(L.get(0) == 11);
      
     }

   // SECTION( "Swap x index doesn't exist in the List" ) {
   //     // L[5],L[0] = L[0],L[5]
   //      L.swap(5,0);

   //    // Now List is [11]
   //       REQUIRE(L.size() == 1);
   //       REQUIRE(L.get(0) == 11);

   //   }
   // SECTION( "Swap y index doesn't exist in the List" ) {
   //     // L[5],L[2] = L[2],L[5]
   //      L.swap(0, 5);

   //    // Now List is [11]
   //       REQUIRE(L.size() == 1);
   //       REQUIRE(L.get(0) == 11);
   //  }
   // SECTION( "Swap both index not in the List" ) {
   //     // L[5],L[8] = L[8],L[5]
   //      L.swap(8, 5);

   //    // Now List is [11]
   //       REQUIRE(L.size() == 1);
   //       REQUIRE(L.get(0) == 11);
   //  }
    SECTION( "Swap x negative index" ) {
       // Try to replace L[-10] = --
        L.swap(-10,2);
         // Now List is [11]
         REQUIRE(L.size() == 1);
         REQUIRE(L.get(0) == 11);
    }
   SECTION( "Swap y negative index" ) {
       // Try to replace L[-10] = --
        L.swap(2,-10);
         // Now List is [11]
         REQUIRE(L.size() == 1);
         REQUIRE(L.get(0) == 11);
    }

   SECTION( "Swap both negative index" ) {
       // Try to replace L[-10] = --
        L.swap(-2,-10);
         // Now List is [11]
         REQUIRE(L.size() == 1);
         REQUIRE(L.get(0) == 11);
    }

   // SECTION( "Swap NULL x index " ){

   //      L.swap(int(), 2);
   //    // Now List is []
   //       REQUIRE(L.size() == 1);
   //       REQUIRE(L.get(0) == 11);
   //  }
   // SECTION( "Swap NULL y index " ){
       
   //      L.swap(2, int());
   //    // Now List is []
   //       REQUIRE(L.size() == 1);
   //       REQUIRE(L.get(0) == 11);
   //  }
 }

// Test 3
TEST_CASE( "swap(int x, int y): List with multiple elements", "[tags]" ) {

   // Now List is [11,-2,3,1]
   SimpleList<int> L;
   L.insert(11);
   L.insert(-2);
   L.insert(3);
   L.insert(1);

   SECTION( "Swap same index" ) {
      // L[0] = L[0] , L[1] = L[1], L[2] = L[2], L[3] = L[3]
      L.swap(0,0);
      L.swap(1,1);
      L.swap(2,2);
      L.swap(3,3);
      
      // Now List is [11,-2,3,1]
      REQUIRE(L.size() == 4);
      REQUIRE(L.get(0) == 11);
      REQUIRE(L.get(1) == -2);
      REQUIRE(L.get(2) == 3);
      REQUIRE(L.get(3) == 1);
        
     }
   SECTION( "Swap first element with last" ) {
         // Swap element at 0 with last one
         L.swap(0,L.size()-1);
         // Now List is [1, -2, 3, 11]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 1);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 11);
    }
   SECTION( "Swap last element with first" ) {
         // Swap element at 0 with last one
         L.swap(L.size()-1, 0);
         // Now List is [1, -2, 3, 11]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 1);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 11);
    }
    
   SECTION( "Swap first element with middle" ) {
         // Swap element at 0 with one in middle
         L.swap(0, 2);
         // Now List is [3, -2, 11, 1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 3);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 11);
         REQUIRE(L.get(3) == 1);
    }
   SECTION( "Swap middle element with first" ) {
         // Swap element at 0 with one in the middle
         L.swap(1, 0);
         // Now List is [-2, 11, 3, 1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == -2);
         REQUIRE(L.get(1) == 11);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
    }
   SECTION( "Swap last element with middle" ) {
         // Swap element at 1 with last one
         L.swap(L.size()-1, 1); 
         // Now List is [11, 1, 3, -2]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == 1);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == -2);
    }

   
   SECTION( "Swap middle element with last" ) {
      // Swap element at 2 with last one
      L.swap(2, L.size()-1);
      // Now List is [11, -2, 1, 3]
      REQUIRE(L.size() == 4);
      REQUIRE(L.get(0) == 11);
      REQUIRE(L.get(1) == -2);
      REQUIRE(L.get(2) == 1);
      REQUIRE(L.get(3) == 3);
    }
   SECTION( "Swap middle element with middle" ) {
      // Swap element at 1 with 2
      L.swap(1, 2);
      // Now List is [11, 3, -2, 1]
      REQUIRE(L.size() == 4);
      REQUIRE(L.get(0) == 11);
      REQUIRE(L.get(1) == 3);
      REQUIRE(L.get(2) == -2);
      REQUIRE(L.get(3) == 1);
    }

   // SECTION( "Swap x index doesn't exist in the List" ) {
   //     // L[5],L[2] = L[2],L[5]
   //      L.swap(5,2);

   //    // Now List is [11, -2, 3, 1]
   //       REQUIRE(L.size() == 4);
   //       REQUIRE(L.get(0) == 11);
   //       REQUIRE(L.get(1) == -2);
   //       REQUIRE(L.get(2) == 3);
   //       REQUIRE(L.get(3) == 1);
   //   }
   // SECTION( "Swap y index doesn't exist in the List" ) {
   //     // L[5],L[2] = L[2],L[5]
   //      L.swap(2, 5);

   //    // Now List is [11, -2, 3, 1]
   //       REQUIRE(L.size() == 4);
   //       REQUIRE(L.get(0) == 11);
   //       REQUIRE(L.get(1) == -2);
   //       REQUIRE(L.get(2) == 3);
   //       REQUIRE(L.get(3) == 1);
   //  }
   // SECTION( "Swap both index not in the List" ) {
   //     // L[5],L[8] = L[8],L[5]
   //      L.swap(8, 5);

   //    // Now List is [11, -2, 3, 1]
   //       REQUIRE(L.size() == 4);
   //       REQUIRE(L.get(0) == 11);
   //       REQUIRE(L.get(1) == -2);
   //       REQUIRE(L.get(2) == 3);
   //       REQUIRE(L.get(3) == 1);
   //  }
   SECTION( "Swap x negative index" ) {
       // Swap L[-10] = --
        L.swap(-10,2);
      // Now List is [11, -2, 3, 1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
     }
   SECTION( "Swap y negative index" ) {
       // Swap element at 2 with -10
        L.swap(2,-10);
      // Now List is [11, -2, 3, 1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
    }

   SECTION( "Swap both negative index" ) {
       // Swap element at -2 with -10
        L.swap(-2,-10);
      // Now List is [11, -2, 3, 1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
    }
    
   SECTION( "Swap NULL x index " ){

        L.swap(int(), 2);
    // Now List is [11, -2, 3, 1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);    
   }
   SECTION( "Swap NULL y index " ){
       
        L.swap(2, int());
       // Now List is [11, -2, 3, 1]
         REQUIRE(L.size() == 4);
         REQUIRE(L.get(0) == 11);
         REQUIRE(L.get(1) == -2);
         REQUIRE(L.get(2) == 3);
         REQUIRE(L.get(3) == 1);
    }
 }

//////////////////////////////////////////////////////////
