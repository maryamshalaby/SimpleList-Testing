#include "includes/catch.hpp"
#include "../src/SimpleList.h"

////////////SEARCH//////////////

TEST_CASE( "Search", "[search]" ) {
  SimpleList<int> *myLinkedList = new SimpleList<int>();
  myLinkedList->setCompare([](int &a, int &b) -> int {
    if(a < b) return -1;
    if(a == b) return 0;
    if(a > b) return 1; 
    return 0; 
  });

 
  SECTION("Search in non-empty list for existing value") {
    myLinkedList->add(5);
    REQUIRE( myLinkedList->search(5) == 0);
    myLinkedList->add(0);
    REQUIRE( myLinkedList->search(int()) == 1);
  }


}

TEST_CASE( "Search (SEGFAULT)", "[.][segfault]" ) {
  SimpleList<int> *myLinkedList = new SimpleList<int>();
  myLinkedList->setCompare([](int &a, int &b) -> int {
    if(a < b) return -1;
    if(a == b) return 0;
    if(a > b) return 1; 
    return 0; 
  });
    SECTION("Search in empty list") {
      REQUIRE( myLinkedList->search(0) == -1);
    }
      SECTION("Search in non-empty list for non-existing value") {
      myLinkedList->add(2);
      REQUIRE( myLinkedList->search(1) == -1);
    }
}

///////////SEARCH_NEXT//////////////

// searches for elements after (lastNodeGot)
// if no function that sets (lastNodeGot) is called prior to calling search_next segmentation fault will occur 

TEST_CASE( "SearchNext", "[search]" ) {
  SimpleList<int> *myLinkedList = new SimpleList<int>();
  myLinkedList->setCompare([](int &a, int &b) -> int {
    if(a < b) return -1;
    if(a == b) return 0;
    if(a > b) return 1; 
    return 0; 
  });


  SECTION("SearchNext in non-empty list for existing value") {
    myLinkedList->add(1);
    myLinkedList->add(2);
    myLinkedList->add(3);

    myLinkedList->search(1);
    REQUIRE( myLinkedList->searchNext(2) == 1);  
  }

}


TEST_CASE( "SearchNext (SEGFAULT)", "[.][segfault]" ) {
  SimpleList<int> *myLinkedList = new SimpleList<int>();
  myLinkedList->setCompare([](int &a, int &b) -> int {
    if(a < b) return -1;
    if(a == b) return 0;
    if(a > b) return 1; 
    return 0; 
  });

  SECTION("SearchNext in empty list") {
    REQUIRE( myLinkedList->searchNext(1) == -1);
  }
   SECTION("SearchNext in non-empty list for non-existing value") {
    myLinkedList->add(2);

    myLinkedList-> search(2);
    REQUIRE( myLinkedList->searchNext(1) == -1);
  }
}

///////////BinSearch//////////////

TEST_CASE( "BinSearch", "[myLinkedList]" ) {
  SimpleList<int> *myLinkedList = new SimpleList<int>();
  myLinkedList->setCompare([](int &a, int &b) -> int {
    if(a < b) return -1;
    if(a == b) return 0;
    if(a > b) return 1; 
    return 0; 
  });

  SECTION("BinSearch in empty list") {
    REQUIRE( myLinkedList->binSearch(1) == -1);
  }

  SECTION("BinSearch in non-empty sorted list for existing value") {
    myLinkedList->add(1);
    myLinkedList->add(2);
    myLinkedList->sort();

    REQUIRE( myLinkedList->binSearch(1) == 0); 
  }

  SECTION("BinSearch in non-empty sorted list for non-existing value") {
    myLinkedList->add(2);
    myLinkedList->add(1);
    // sorting the list results in performing binary search
    myLinkedList->sort();

    REQUIRE( myLinkedList->binSearch(3) == -1);
  }

  SECTION("BinSearch in non-sorted list for existing values") {
    myLinkedList->add(2);
    myLinkedList->add(1);
    
    // without sorting BinSearch is the same as regular search
    REQUIRE( myLinkedList->binSearch(1) == 1);
  }

}


TEST_CASE( "BinSearch (SEGFAULT)", "[.][segfault]" ) {
  SimpleList<int> *myLinkedList = new SimpleList<int>();
  myLinkedList->setCompare([](int &a, int &b) -> int {
    if(a < b) return -1;
    if(a == b) return 0;
    if(a > b) return 1; 
    return 0; 
  });

  
  SECTION("BinSearch in non-sorted list for non existing values") {
    myLinkedList->add(2);
    myLinkedList->add(1);
    
    // without sorting BinSearch is the same as regular search
    REQUIRE( myLinkedList->binSearch(3) == -1);
  }
}

///////////has//////////////

TEST_CASE( "Has", "[myLinkedList]" ) {
  SimpleList<int> *myLinkedList = new SimpleList<int>();
  myLinkedList->setCompare([](int &a, int &b) -> int {
    if(a < b) return -1;
    if(a == b) return 0;
    if(a > b) return 1; 
    return 0; 
  });

  SECTION("Has in empty list") {
    REQUIRE( myLinkedList->has(1) == false);
  }

  SECTION("Has in non-empty sorted list for existing value") {
    myLinkedList->add(1);
    myLinkedList->add(2);
    myLinkedList->sort();

    REQUIRE( myLinkedList->has(1) == true); 
  }

  SECTION("Has in non-empty sorted list for non-existing value") {
    myLinkedList->add(2);
    myLinkedList->add(1);
    // sorting the list results in performing binary search
    myLinkedList->sort();

    REQUIRE( myLinkedList->has(3) == false);
  }

}

TEST_CASE( "Has (SEGFAULT)", "[.][segfault]"  ) {
  SimpleList<int> *myLinkedList = new SimpleList<int>();
  myLinkedList->setCompare([](int &a, int &b) -> int {
    if(a < b) return -1;
    if(a == b) return 0;
    if(a > b) return 1; 
    return 0; 
  });

  SECTION("Has in non-sorted list for non existing values") {
    myLinkedList->add(2);
    myLinkedList->add(1);
    
    REQUIRE( myLinkedList->has(3) == false);
   }
}





