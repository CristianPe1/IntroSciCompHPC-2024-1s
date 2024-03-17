#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch_test_macros.hpp"
#include "vector_ops.hpp"
#include <vector>

TEST_CASE( "Mean of a vector is computed", "[mean]" ) {
  
  std::vector<double> x = {1, 2, 3, 4, 5};
  REQUIRE( isclose(mean(x), 3, 1e-5, 1e-3));

  std::vector<double> y = {1, 2, 3, 4, 5, 6};
  REQUIRE( isclose(mean(y), 3.5, 1e-5, 1e-3));

  std::vector<double> z = {1, 2, 3, 4, 5, 6, 7};
  REQUIRE( isclose(mean(z), 4, 1e-5, 1e-3));

  std::vector<double> w = {1, 2, 3, 4, 5, 6, 7, 8};
  REQUIRE( isclose(mean(w), 4.5, 1e-5, 1e-3));

  std::vector<double> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  REQUIRE( isclose(mean(v), 5, 1e-5, 1e-3));
  
}