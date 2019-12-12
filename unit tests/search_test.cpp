#include "includes/catch.hpp"
#include "../src/SimpleList.h"
#include <iostream> 

////////////SEARCH//////////////

/*TEST_CASE( "Search in empty list", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    REQUIRE( myLinkedList->search(0) == -1);
}*/

TEST_CASE( "Search in non-empty list for existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(5);
    REQUIRE( myLinkedList->search(5) == 0);

    // searching for NULL in integer list is equivelent to searching for zero
    myLinkedList->add(0);
    REQUIRE( myLinkedList->search(NULL) == 1);
}
/*
TEST_CASE( "search in non-empty list for non-existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(2);
    REQUIRE( myLinkedList->search(1) == -1);
}*/

///////////SEARCH_NEXT//////////////

// searches for elements after (lastNodeGot)
// if no function that sets (lastNodeGot) is called prior to calling search_next segmentation fault will occur 

/*
TEST_CASE( "searchNext in empty list", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    REQUIRE( myLinkedList->searchNext(1) == -1);
}

TEST_CASE( "search in non-empty list for existing value", "[myLinkedList]") {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(1);
    myLinkedList->add(2);
    myLinkedList->add(3);

    myLinkedList->search(1);
    REQUIRE( myLinkedList->searchNext(2) == 1);
}

TEST_CASE( "search in non-empty list for non-existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(2);
    myLinkedList-> search(2);
    REQUIRE( myLinkedList->searchNext(1) == -1);
}*/

///////////BinSearch//////////////
/*
TEST_CASE( "BinSearch in empty list", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    REQUIRE( myLinkedList->binSearch(1) == -1);
}

TEST_CASE( "search in non-empty list for existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(1);
    REQUIRE( myLinkedList->binSearch(1) == 0);
}

// sorting the list result in performing binary search
TEST_CASE( "search in non-empty sorted list for non-existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(2);
    myLinkedList->add(1);
    myLinkedList->sort();
    REQUIRE( myLinkedList->binSearch(3) == -1);
}

TEST_CASE( "search in non-empty not sorted list for non-existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(2);
    myLinkedList->add(1);
    REQUIRE( myLinkedList->binSearch(3) == -1);
}*/

///////////has//////////////

/*TEST_CASE( "Has in empty list", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    REQUIRE( myLinkedList->has(1) == false);
}

TEST_CASE( "has in non-empty ordered list for existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(2);
    myLinkedList->add(1);
    myLinkedList->sort();
    REQUIRE( myLinkedList->has(1) == true);
}

TEST_CASE( "has in non-empty not ordered list for existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(2);
    myLinkedList->add(1);
    REQUIRE( myLinkedList->has(1) == true);
}

TEST_CASE( "has in non-empty sorted list for non-existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(2);
    myLinkedList->add(1);
    myLinkedList->sort();
    REQUIRE( myLinkedList->has(3) == false);
}

TEST_CASE( "has in non-empty not sorted list for non-existing value", "[myLinkedList]" ) {
    SimpleList<int> *myLinkedList = new SimpleList<int>();
    myLinkedList->setCompare([](int &a, int &b) -> int {
      if(a < b) return -1;
      if(a == b) return 0;
      if(a > b) return 1;  
    });
    myLinkedList->add(2);
    myLinkedList->add(1);
    REQUIRE( myLinkedList->has(3) == false);
}*/




