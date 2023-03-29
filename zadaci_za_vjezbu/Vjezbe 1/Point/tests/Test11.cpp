#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "../../../doctest/doctest.h"
#include "../Point.hpp"

TEST_CASE("Test operator+=") {
  Point p1(1.0, 2.0);
  Point p2(3.0, 4.0);

  p1 += p2;

  CHECK(p1.x() == 4.0);
  CHECK(p1.y() == 6.0);
}
