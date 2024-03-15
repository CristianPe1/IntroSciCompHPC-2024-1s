#define CATCH_CONFIG_MAIN
#include "catch2/catch_test_macros.hpp"
#include "factorial.h"


TEST_CASE( "Factorials are computed", "[factorial]" ) {
  REQUIRE( factorial(0) == 1 );
  REQUIRE( factorial(1) == 1 );
  REQUIRE( factorial(2) == 2 );
  REQUIRE( factorial(3) == 6 );
  REQUIRE( factorial(10) == 3628800 );
}
// Path: 09-UnitTest/WorkinClass/factorial.h
