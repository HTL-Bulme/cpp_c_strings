#include "array.hpp"

#include <cstddef>
#include <cstdint>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

TEST_CASE("empty array", "[sum]") {
  int32_t a1[0];
  REQUIRE(sum(a1, 0) == 0);
  // callee cannot know the array is not empty
  int32_t a2[2] = {3, 2};
  REQUIRE(sum(a2, 0) == 0);
}

TEST_CASE("single element", "[sum]") {
  int32_t a1[1] = {3};
  CHECK(sum(a1, 1) == 3);
  int32_t a2[1] = {-1234};
  CHECK(sum(a2 , 1) == -1234);
}

TEST_CASE("positive only", "[sum]") {
  int32_t a1[] = {1, 2, 3, 4, 5};
  int32_t a2[] = {1, 1, 1, 1, 1};
  int32_t a3[] = {99, 1, 0};
  int32_t a4[] = {2, 4, 6, 8, 10};

  CHECK(sum(a1, 5) == 15);
  CHECK(sum(a2, 5) == 5);
  CHECK(sum(a3, 3) == 100);
  CHECK(sum(a4, 5) == 30);
}

TEST_CASE("mixing positive and negative", "[sum]") {
  int32_t a1[] = {10, 9, 0, -10, -9};
  int32_t a2[] = {-1, -1, -1, -1, -1};
  int32_t a3[] = {12, -1, 10, -1};

  CHECK(sum(a1, 5) == 0);
  CHECK(sum(a2, 5) == -5);
  CHECK(sum(a3, 4) == 20);
}


TEST_CASE("empty array", "[product]") {
  int32_t a1[0];
  int32_t a2[2] = {3, 2};

  REQUIRE(product(a1, 0) == 1);
  // callee cannot know the array is not empty
  REQUIRE(product(a2, 0) == 1);
}

TEST_CASE("single element", "[product]") {
  int32_t a1[1] = {3};
  int32_t a2[1] = {-1234};

  CHECK(product(a1, 1) == 3);
  CHECK(product(a2, 1) == -1234);
}

TEST_CASE("positive only", "[product]") {
  int32_t a1[] = {1, 2, 3, 4, 5};
  int32_t a2[] = {1, 1, 1, 1, 1};
  int32_t a3[] = {99, 1, 0};
  int32_t a4[] = {2, 4, 6, 8, 10};

  CHECK(product(a1, 5) == 120);
  CHECK(product(a2, 5) == 1);
  CHECK(product(a3, 3) == 0);
  CHECK(product(a4, 5) == 3840);
}

TEST_CASE("mixing positive and negative", "[product]") {
  int32_t a1[] = {10, 9, 0, -10, -9};
  int32_t a2[] = {-1, -1, -1, -1, -1};
  int32_t a3[] = {12, -1, 10, -1};

  CHECK(product(a1, 5) == 0);
  CHECK(product(a2, 5) == -1);
  CHECK(product(a3, 4) == 120);
}


TEST_CASE("single element", "[min]") {
  int32_t a1[1] = {3};
  int32_t a2[1] = {-1234};

  CHECK(min(a1, 1) == 3);
  CHECK(min(a2, 1) == -1234);
}

TEST_CASE("positive only", "[min]") {
  int32_t a1[] = {1, 2, 3, 4, 5};
  int32_t a2[] = {1, 1, 1, 1, 1};
  int32_t a3[] = {99, 1, 0};
  int32_t a4[] = {2, 4, 6, 8, 10};

  CHECK(min(a1, 5) == 1);
  CHECK(min(a2, 5) == 1);
  CHECK(min(a3, 3) == 0);
  CHECK(min(a4, 5) == 2);
}

TEST_CASE("mixing positive and negative", "[min]") {
  int32_t a1[] = {10, 9, 0, -10, -9};
  int32_t a2[] = {-1, -1, -1, -1, -1};
  int32_t a3[] = {12, -5, 10, -1};

  CHECK(min(a1, 5) == -10);
  CHECK(min(a2, 5) == -1);
  CHECK(min(a3, 4) == -5);
}


TEST_CASE("single element", "[max]") {
  int32_t a1[1] = {3};
  int32_t a2[1] = {-1234};

  CHECK(max(a1, 1) == 3);
  CHECK(max(a2, 1) == -1234);
}

TEST_CASE("positive only", "[max]") {
  int32_t a1[] = {1, 2, 3, 4, 5};
  int32_t a2[] = {1, 1, 1, 1, 1};
  int32_t a3[] = {99, 1, 0};
  int32_t a4[] = {2, 4, 6, 8, 10};

  CHECK(max(a1, 5) == 5);
  CHECK(max(a2, 5) == 1);
  CHECK(max(a3, 3) == 99);
  CHECK(max(a4, 5) == 10);
}

TEST_CASE("mixing positive and negative", "[max]") {
  int32_t a1[] = {10, 9, 0, -10, -9};
  int32_t a2[] = {-1, -1, -1, -1, -1};
  int32_t a3[] = {12, -1, 10, -1};

  CHECK(max(a1, 5) == 10);
  CHECK(max(a2, 5) == -1);
  CHECK(max(a3, 4) == 12);
}


TEST_CASE("empty array", "[count]") {
  int32_t a1[0];
  int32_t a2[2] = {3, 2};

  REQUIRE(count(a1, 0, 10) == 0);
  // callee cannot know the array is not empty
  REQUIRE(count(a2, 0, 3) == 0);
}

TEST_CASE("single element", "[count]") {
  int32_t a1[] = {3};
  int32_t a2[] = {-1234};

  CHECK(count(a1, 1, 3) == 1);
  CHECK(count(a1, 1, 2) == 0);
  CHECK(count(a2, 1, 1234) == 0);
  CHECK(count(a2, 1, -1234) == 1);
}

TEST_CASE("positive only", "[count]") {
  int32_t a1[] = {1, 2, 3, 4, 5};
  int32_t a2[] = {1, 1, 1, 1, 1};
  int32_t a3[] = {99, 1, 0};
  int32_t a4[] = {2, 4, 6, 8, 10};

  CHECK(count(a1, 5, 1) == 1);
  CHECK(count(a2, 5, 1) == 5);
  CHECK(count(a3, 3, 99) == 1);
  CHECK(count(a4, 5, 5) == 0);
}

TEST_CASE("mixing positive and negative", "[count]") {
  int32_t a1[] = {10, 9, 0, -10, -9};
  int32_t a2[] = {-1, -1, -1, -1, -1};
  int32_t a3[] = {12, -1, 10, -1};

  CHECK(count(a1, 5, 10) == 1);
  CHECK(count(a2, 5, -1) == 5);
  CHECK(count(a3, 4, -1) == 2);
}


TEST_CASE("single element", "[mean]") {
  int32_t a1[] = {3};
  int32_t a2[] = {-1234};

  CHECK_THAT(mean(a1, 1),
    Catch::Matchers::WithinAbs(3.0, 0.000001));
  CHECK_THAT(mean(a2, 1),
    Catch::Matchers::WithinAbs(-1234.0, 0.000001));
}

TEST_CASE("positive only", "[mean]") {
  int32_t a1[] = {1, 2, 3, 4, 5};
  int32_t a2[] = {1, 1, 1, 1, 1};
  int32_t a3[] = {99, 1, 0};
  int32_t a4[] = {2, 4, 6, 8, 10};

  CHECK_THAT(mean(a1, 5),
    Catch::Matchers::WithinAbs(3.0, 0.000001));
  CHECK_THAT(mean(a2, 5),
    Catch::Matchers::WithinAbs(1.0, 0.000001));
  CHECK_THAT(mean(a3, 3),
    Catch::Matchers::WithinAbs(33.333, 0.001));
  CHECK_THAT(mean(a4, 5),
    Catch::Matchers::WithinAbs(6.0, 0.000001));
}

TEST_CASE("mixing positive and negative", "[mean]") {
  int32_t a1[] = {10, 9, 0, -10, -9};
  int32_t a2[] = {-1, -1, -1, -1, -1};
  int32_t a3[] = {12, -5, 10, -1};

  CHECK_THAT(mean(a1, 5),
    Catch::Matchers::WithinAbs(0.0, 0.000001));
  CHECK_THAT(mean(a2, 5),
    Catch::Matchers::WithinAbs(-1.0, 0.000001));
  CHECK_THAT(mean(a3, 4),
    Catch::Matchers::WithinAbs(4.0, 0.000001));
}


TEST_CASE("positive only", "[variance]") {
  int32_t a1[] = {1, 2, 3, 4, 5};
  int32_t a2[] = {1, 1, 1, 1, 1};
  int32_t a3[] = {99, 1, 0};
  int32_t a4[] = {2, 4, 6, 8, 10};

  CHECK_THAT(variance(a1, 5),
    Catch::Matchers::WithinAbs(2.5, 0.000001));
  CHECK_THAT(variance(a2, 5),
    Catch::Matchers::WithinAbs(0.0, 0.000001));
  CHECK_THAT(variance(a3, 3),
    Catch::Matchers::WithinAbs(3234.333333333333, 0.001));
  CHECK_THAT(variance(a4, 5),
    Catch::Matchers::WithinAbs(10.0, 0.000001));
}

TEST_CASE("mixing positive and negative", "[variance]") {
  int32_t a1[] = {10, 9, 0, -10, -9};
  int32_t a2[] = {-1, -1, -1, -1, -1};
  int32_t a3[] = {12, -5, 10, -1};

  CHECK_THAT(variance(a1, 5),
    Catch::Matchers::WithinAbs(90.5, 0.000001));
  CHECK_THAT(variance(a2, 5),
    Catch::Matchers::WithinAbs(-0.0, 0.000001));
  CHECK_THAT(variance(a3, 4),
    Catch::Matchers::WithinAbs(68.6666666666666, 0.000001));
}


bool array_equal(const int32_t first[], const int32_t second[], size_t count) {
  for (size_t i = 0; i < count; ++i) {
    if (first[i] != second[i]) return false;
  }
  return true;
}

TEST_CASE("empty base array", "[subarray]") {
  int32_t a[] = {};
  int32_t actual[] = {-1, -1, -1, -1, -1};
  std::vector<int32_t> expected{-1, -1, -1, -1, -1};
  subarray(a, 0, 0, actual);
  std::vector<int32_t> actual_v(actual, actual + sizeof(actual) / sizeof(int32_t));
  CHECK_THAT(actual_v,
    Catch::Matchers::Equals(expected));
}

TEST_CASE("single element", "[subarray]") {
  int32_t a1[] = {3};
  int32_t actual[] = {0, 0, 0, 0, 0};
  int32_t expected1[] = {0, 0, 0, 0, 0};
  int32_t expected2[] = {3, 0, 0, 0, 0};
  subarray(a1, 0, 0, actual);
  CHECK(array_equal(actual, expected1, 5));
  subarray(a1, 0, 1, actual);
  CHECK(array_equal(actual, expected2, 5));
}

TEST_CASE("regular array", "[subarray]") {
  int32_t actual[] = {0, 0, 0, 0, 0};
  int32_t a1[] = {1, 2, 3, 4, 5};

  SECTION("copy empty selection of elements") {
    int32_t expected[] = {0, 0, 0, 0, 0};
    subarray(a1, 0, 0, actual);
    CHECK(array_equal(actual, expected, 5));
    subarray(a1, 3, 3, actual);
    CHECK(array_equal(actual, expected, 5));
  }

  SECTION("copy single element") {
    int32_t e1[] = {1, 0, 0, 0, 0};
    int32_t e2[] = {4, 0, 0, 0, 0};
    int32_t e3[] = {5, 0, 0, 0, 0};
    subarray(a1, 0, 1, actual);
    CHECK(array_equal(actual, e1, 5));
    subarray(a1, 3, 4, actual);
    CHECK(array_equal(actual, e2, 5));
    subarray(a1, 4, 5, actual);
    CHECK(array_equal(actual, e3, 5));
  }

  SECTION("copy proper slice") {
    int32_t a2[] = {-5, -4, -3};
    int32_t e1[] = {3, 4, 5, 0, 0};
    int32_t e2[] = {2, 3, 0, 0, 0};
    int32_t e3[] = {-5, -4, -3, 0, 0};
    int32_t actual2[] = {0, 0, 0, 0, 0};
    int32_t actual3[] = {0, 0, 0, 0, 0};
    subarray(a1, 2, 5, actual);
    CHECK(array_equal(actual, e1, 5));
    subarray(a1, 1, 3, actual2);
    CHECK(array_equal(actual2, e2, 5));
    subarray(a2, 0, 3, actual3);
    CHECK(array_equal(actual3, e3, 5));
  }
}

